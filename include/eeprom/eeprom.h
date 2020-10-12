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
  static const size_t BUFFER_SIZE            = 128;
  mutable uint8_t     saved_bpm              = 0;
  mutable bool        saved_playback_state   = false;    
  size_t              save_ix = 0, save_addr = 5;
  lamb::flag          save_requested;  

  struct queued_write {
    int idx;
    uint8_t val;

    inline queued_write(int idx_ = 0, uint8_t val_ = 0) :
      idx(idx_), val(val_) {}
  };
  
  declare_light_buffer(queued_write, BUFFER_SIZE, queue);
  
  bool write_to_queue(int idx_, uint8_t val_);
  
  void save_playback_state(bool const & playback_state_);

  void save_bpm(uint8_t const & bpm_);

  bool playback_state() const;

  uint8_t bpm() const;

  template <typename track_t>
  void save_track(
    size_t const & eeprom_location,
    track_t & track
  ) {
    Serial.println(F("SAVE_TRACK NOT IMPLEMENTED FOR THIS TYPE"));
  }

  template <typename track_t>
  void restore_track(
    size_t const & eeprom_location,
    track_t & track
  ) {
    Serial.println(F("RESTORE_TRACK NOT IMPLEMENTED FOR THIS TYPE"));
  }  

public:
  bool write_from_queue();

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
  bool save_all(
    PersistentData<tracks_t> const & data
  ) {
    if (! save_requested.consume()) return false;

    if (light_buffer_available(queue) < ADDR_INCR) {
      Serial.println("Too little buffer space, abort.");
      
      return false;
    }

    while (! (*data.tracks)[save_ix].modified.consume()) {
      if (save_ix >= data.tracks->size() - 1) {

        if (saved_bpm != data.bpm) {
          save_bpm(data.bpm);
          
          saved_bpm = data.bpm;
        }
        
        if (saved_playback_state != data.playback_state) {
          save_playback_state(data.playback_state);
          
          saved_playback_state = data.playback_state;
        }

        return false;
      }
      
      save_ix++, save_addr += ADDR_INCR;
    }
    
    Serial.print(F("\nSave track #"));
    Serial.print(save_ix + 1);
    Serial.print('/');
    Serial.print(data.tracks->size());
    Serial.print(' ');
    Serial.print(F(" to 0x"));
    Serial.print(save_addr + ADDR_BASE, HEX);
    Serial.println();
    
    save_track(save_addr + ADDR_BASE, (*data.tracks)[save_ix]);

    return true;
  }
};

template <>
void eeprom::save_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
);

template <>
void eeprom::restore_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
);

template <>
void eeprom::save_track<tracks::x0x>(
  size_t const & eeprom_location,
  tracks::x0x & track
);

template <>
void eeprom::restore_track<tracks::x0x>(
  size_t const & eeprom_location,
  tracks::x0x & track
);

#endif
