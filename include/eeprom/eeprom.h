#ifndef LAMB_DRUMMER_EEPROM_H
#define LAMB_DRUMMER_EEPROM_H

#include <EEPROM.h>
#include <lamb.h>
#include "tracks/euclidean.h"
#include "tracks/x0x.h"

#ifdef XOX
#define ADDR_BASE 32
#define ADDR_INCR 16
#else
#define ADDR_BASE 0
#define ADDR_INCR 4
#endif

class eeprom {
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

  template <typename track_t>
  void save_track(
    size_t const & eeprom_location,
    track_t & track
  ) const {
    Serial.println(F("SAVE_TRACK NOT IMPLEMENTED FOR THIS TYPE"));
  }

  template <typename track_t>
  void restore_track(
    size_t const & eeprom_location,
    track_t & track
  ) {
    Serial.println(F("RESTORE_TRACK NOT IMPLEMENTED FOR THIS TYPE"));
  }  

  lamb::flag save_requested;
  unsigned long last_edit;
public:
  void flag_save_requested();
  void unflag_save_requested();
  eeprom();
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
      ix++, addr+= ADDR_INCR
    ) {
//      Serial.print(F("Restore TS #"));
//      Serial.print(ix);
//      Serial.print(F(" from "));
//      Serial.print(addr);
//      Serial.println();
      
      restore_track(addr + ADDR_BASE,  (*data.tracks)[ix]);
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
      ix++, addr+= ADDR_INCR
    )
      save_track(addr + ADDR_BASE,  (*data.tracks)[ix]);

    //Serial.println(F("Done save all to EEPROM"));
  }
};

template <>
void eeprom::save_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
) const;

template <>
void eeprom::restore_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
);

template <>
void eeprom::save_track<tracks::x0x>(
  size_t const & eeprom_location,
  tracks::x0x & track
) const;

template <>
void eeprom::restore_track<tracks::x0x>(
  size_t const & eeprom_location,
  tracks::x0x & track
);

#endif
