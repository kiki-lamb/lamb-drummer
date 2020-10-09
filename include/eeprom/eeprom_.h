#ifndef LAMB_DRUMMER_EEPROM_H
#define LAMB_DRUMMER_EEPROM_H

#include <EEPROM.h>
#include <lamb.h>
#include "track/track.h"

class eeprom_ {
public:
  template <class tracks_t>
  class PersistantData {
  public:
    tracks_t * tracks;
    uint8_t bpm;
    bool playback_state;
    PersistantData(
      tracks_t * tracks_,
      uint8_t bpm_,
      bool playback_state_
    ) :
      tracks(tracks_),
      bpm(bpm_),
      playback_state(playback_state_)
      {}
  };
private:
  void save_playback_state(bool const & playback_state_) const;
  void save_bpm(uint8_t const & bpm_) const;
  bool playback_state() const;
  uint8_t bpm() const;
  void save_track(
    size_t const & eeprom_location,
    track & track
  ) const;
  void restore_track(
    size_t const & eeprom_location,
    track & track
  );
  lamb::flag save_requested;
  unsigned long last_edit;
public:
  void flag_save_requested();
  void unflag_save_requested();
  eeprom_();
//  /* virtual */ ~eeprom_();

  template <class tracks_t>
  void restore_all(
    PersistantData<tracks_t> & data
  ) {
    data.bpm = bpm();
    data.playback_state = playback_state();

    for (
      size_t ix = 0, addr = 5;
      ix < data.tracks->size();
      ix++, addr+= 4
    ) {
      //Serial.print(F("Restore TS #"));
      //Serial.print(ix);
      //Serial.print(F(" from "));
      //Serial.print(addr);
      //Serial.println();
      restore_track(addr,  (*data.tracks)[ix]);
    }

    save_requested.unset();
  }

  template <class tracks_t>
  void save_all(
    PersistantData<tracks_t> const & data
  ) {
    return;
    
    const unsigned long SAVE_DELAY = 15000UL;

    unsigned long now   = millis();
    unsigned long delta = now - last_edit;

    if (! save_requested.consume())
      return;

    if (delta < SAVE_DELAY) {
      //Serial.print(F("Must wait "));
      //Serial.print(SAVE_DELAY-delta);
      //Serial.println(F("ms before saving."));
      save_requested.set();
      return;
    }

    //Serial.println(F("Save all to EEPROM..."));

    save_bpm(data.bpm);
    save_playback_state(data.playback_state);

    for (
      size_t ix = 0, addr = 5;
      ix < data.tracks->size();
      ix++, addr+= 4
    )
      save_track(addr,  (*data.tracks)[ix]);

    //Serial.println(F("Done save all to EEPROM"));
  }
};

#endif
