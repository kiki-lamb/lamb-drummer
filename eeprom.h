#ifndef SHELF_CLOCK_EEPROM_H
#define SHELF_CLOCK_EEPROM_H

#include <EEPROM.h>
#include "flag.h"
#include "track_state.h"


class Eeprom {
  public:
  template <class collection_t>
  class persistant_data {
    public:
    collection_t * track_states;
    uint8_t bpm;
    bool play_state;
  
    persistant_data(collection_t * track_states_, uint8_t bpm_, bool play_state_) :
      track_states(track_states_),
      bpm(bpm_),
      play_state(play_state_)
    {}
  };

  private:
    void save_playback_state(bool playback_state_) const;
    void save_bpm(uint8_t bpm_) const;
    bool playback_state() const;
    uint8_t bpm() const;
    void save_track_state(size_t eeprom_location, TrackState const & track_state) const;
    void restore_track_state(size_t eeprom_location, TrackState & track_state);
    Flag save_requested;
    unsigned long last_edit;

  public:
    void flag_save_requested();
    
    Eeprom();
    virtual ~Eeprom();    
    
    template <class collection_t> 
    void Eeprom::restore_all(persistant_data<collection_t> & data) {
     //Encoder::set_value(tmp); // UGLY NEED TO DO THIS OUTSIDE
     data.bpm = bpm();
     data.play_state = playback_state();
        
     for (size_t ix = 0, addr = 5; ix < data.track_states->size(); ix++, addr+= 4) {
       Serial.print(F("Restore TS #"));
       Serial.print(ix);
       Serial.print(F(" from "));
       Serial.print(addr);
       Serial.println();
//       restore_track_state(addr, const_cast<Application::collection_t::item_t &>(Application::track_states()[ix]));
       restore_track_state(addr,  (*data.track_states)[ix]);
     }

     save_requested.unflag();
  }
  
  template <class collection_t> 
  void Eeprom::save_all(persistant_data<collection_t> const & data) {
    const unsigned long SAVE_DELAY = 15000UL;

    unsigned long now   = millis();
    unsigned long delta = now - last_edit;
      
    if (! save_requested.consume())
      return;
  
    if (delta < SAVE_DELAY) {
      Serial.print(F("Must wait "));
      Serial.print(SAVE_DELAY-delta);
      Serial.println(F("ms before saving."));
      save_requested.flag();
      return;
    }
  
    Serial.println(F("Save all to EEPROM..."));
  
    save_bpm(data.bpm);
    save_playback_state(data.play_state);
  
    for (size_t ix = 0, addr = 5; ix < data.track_states->size(); ix++, addr+= 4)
      save_track_state(addr,  (*data.track_states)[ix]);
    
    Serial.println(F("Done save all to EEPROM"));
  } 
};

#endif
