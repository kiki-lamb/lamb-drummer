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
  class PersistentData {
  public:
    tracks_t * tracks;
    uint8_t bpm;
    bool playback_state;
    PersistentData(
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

  template <class tracks_t>
  void restore_all(
    PersistentData<tracks_t> & data
  ) {
    data.bpm = bpm();
    data.playback_state = playback_state();

    for (
      size_t ix = 0, addr = 5;
      ix < data.tracks->size();
      ix++, addr+= ADDR_INCR
    ) {
      Serial.print(F("\nRestore track #"));
      Serial.print(ix + 1);
      Serial.print(F(" from 0x"));
      Serial.print(addr + ADDR_BASE, HEX);
      Serial.println();
      
      restore_track(addr + ADDR_BASE,  (*data.tracks)[ix]);
    }

    save_requested.unset();
  }

  template <class tracks_t>
  void save_all(
    PersistentData<tracks_t> const & data
  ) {
    if (! save_requested.consume()) {
      return;
    }
    else {
      Serial.println(F("Saving all..."));
    }

    static size_t ix = 0, addr = 5;

    while (! (*data.tracks)[ix].modified.consume()) {
      if (ix == data.tracks->size()) {
        ix = 0;
        addr = 5;

        save_bpm(data.bpm);

        save_playback_state(data.playback_state);

        Serial.println(F("Nothing left to save."));
        
        return;
      }

      ix++, addr += ADDR_INCR;
    }
    
    Serial.print(F("\nSave track #"));
    Serial.print(ix +1 );
    Serial.print(F(" to 0x"));
    Serial.print(addr + ADDR_BASE, HEX);
    Serial.println();
    
    save_track(addr + ADDR_BASE,  (*data.tracks)[ix]);
    
    save_requested.set();
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
