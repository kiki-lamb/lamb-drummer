#include "Arduino.h"
#include "eeprom/eeprom.h"
#include "tracks/euclidean.h"
#include "tracks/x0x.h"

#define ADDR_BPM  3
#define ADDR_PLAY 4

eeprom::eeprom() : save_requested() {}

// eeprom::~eeprom() {}

void eeprom::flag_save_requested() {
  save_requested.set();
  last_edit = millis();
}

void eeprom::unflag_save_requested() {
  save_requested.unset();
}

void eeprom::save_playback_state(bool const & playback_state_) const {
  Serial.print(F("Save playback_state "));
  Serial.println(playback_state_ ? 1 : 0);

  EEPROM.write(ADDR_PLAY, playback_state_);
}

void eeprom::save_bpm(uint8_t const & bpm_) const {
  Serial.print(F("Save BPM "));
  Serial.println(bpm_);
  EEPROM.write(ADDR_BPM, bpm_);
}

bool eeprom::playback_state() const {
  bool tmp = EEPROM.read(ADDR_PLAY);

  Serial.print(F("Load playback_state "));
  Serial.println(tmp ? F("play") : F("pause"));
  return tmp;
}

uint8_t eeprom::bpm() const {
  uint8_t tmp = EEPROM.read(ADDR_BPM);

  Serial.print(F("Load BPM "));
  Serial.println(tmp);

  return tmp;
}

template <>
void eeprom::save_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
) const {
  EEPROM.write(eeprom_location + 0, track.mod_maj());
  Serial.print(F("Save mod_maj "));
  Serial.print(track.mod_maj()); Serial.println();
  
  EEPROM.write(eeprom_location + 1, track.mod_min());
  Serial.print(F("Save mod_min "));
  Serial.print(track.mod_min()); Serial.println();
  
  EEPROM.write(eeprom_location + 2, track.phase_min());
  Serial.print(F("Save phase_min "));
  Serial.print(track.phase_min()); Serial.println();
  
  EEPROM.write(eeprom_location + 3, track.phase_maj());
  Serial.print(F("Save phase_maj "));
  Serial.print(track.phase_maj()); Serial.println();
  
  Serial.println(F("Saved track"));
}

template<>
void eeprom::restore_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
) {
  track.set_mod_maj(EEPROM.read(eeprom_location + 0));
  Serial.print(F("Restore mod_maj "));
  Serial.print(track.mod_maj()); Serial.println();
  
  track.set_mod_min(EEPROM.read(eeprom_location + 1));
  Serial.print(F("Restore mod_min "));
  Serial.print(track.mod_min()); Serial.println();
  
  track.set_phase_min(EEPROM.read(eeprom_location + 2));
  Serial.print(F("Restore phase_min "));
  Serial.print(track.phase_min()); Serial.println();
  
  track.set_phase_maj(EEPROM.read(eeprom_location + 3));
  Serial.print(F("Restore phase_maj "));
  Serial.print(track.phase_maj()); Serial.println();
  
  Serial.print(F("Unflag track state"));
  Serial.println();
  Serial.println();
  Serial.flush();
  track.modified.unset();
}

template <>
void eeprom::save_track<tracks::x0x>(
  size_t const & eeprom_location,
  tracks::x0x & track
) const {
  // if (! track.modified.consume() ) {
  //   Serial.println(F("Not modified, not saving."));
    
  //   return;
  // }

  Serial.print(F(" 0x"));
  Serial.print(eeprom_location, HEX);
  Serial.print(F(" bars_count = "));
  Serial.print(track.bars_count());
  Serial.println();
  Serial.flush();

  EEPROM.write(eeprom_location + 0, track.bars_count());

  uint8_t ix = 0;
  
  for (; ix < track.bars_count(); ix++) {
    size_t loc = eeprom_location + 1 + (ix * 2);

    uint16_t bar_data = track.bar(ix);
    uint8_t  bar_data_lo = bar_data & 0xff;
    uint8_t  bar_data_hi = bar_data >> 8;
    
    Serial.print(F(" 0x"));
    Serial.print(loc, HEX);
    Serial.print(F(" bar "));
    Serial.print(ix);
    Serial.print(F(" hi = "));
    lamb::print_bits_8(bar_data_hi);
    Serial.println();
    Serial.flush();

    Serial.print(F(" 0x"));
    Serial.print(loc + 1, HEX);
    Serial.print(F(" bar "));
    Serial.print(ix);
    Serial.print(F(" lo = "));
    lamb::print_bits_8(bar_data_lo);
    Serial.println();
    Serial.flush();

    EEPROM.write(loc + 0, bar_data_hi);
    EEPROM.write(loc + 1, bar_data_lo);
  }

  for (; ix < 8; ix++) {
    size_t loc = eeprom_location + 1 + (ix * 2);

    EEPROM.write(loc + 0, 0);
    EEPROM.write(loc + 1, 0);
  }
    
  Serial.print(F("Saved track to 0x"));
  Serial.print(eeprom_location, HEX);
  Serial.println();
}

template<>
void eeprom::restore_track<tracks::x0x>(
  size_t const & eeprom_location,
  tracks::x0x & track
) {
  uint8_t tmp_bars_count = EEPROM.read(eeprom_location + 0);
  
  Serial.print(F(" 0x"));
  Serial.print(eeprom_location, HEX);
  Serial.print(F(" bars_count = "));
  Serial.print(tmp_bars_count);
  Serial.println();
  Serial.flush();
  
  track.clear(tmp_bars_count);

  for (uint8_t ix = 0; ix < track.bars_count(); ix++) {
    size_t   loc         = eeprom_location + 1 + (ix * 2);
    uint8_t  bar_data_hi = EEPROM.read(loc);
    uint8_t  bar_data_lo = EEPROM.read(loc + 1);
    uint16_t bar_data    = bar_data_hi;
    bar_data <<= 8;
    bar_data |= bar_data_lo;
    
    Serial.print(F(" 0x"));
    Serial.print(loc, HEX);
    Serial.print(F(" bar "));
    Serial.print(ix);
    Serial.print(F(" hi = "));
    lamb::print_bits_8(bar_data_hi);
    Serial.println();
    Serial.flush();

    Serial.print(F(" 0x"));
    Serial.print(loc + 1, HEX);
    Serial.print(F(" bar "));
    Serial.print(ix);
    Serial.print(F(" lo = "));
    lamb::print_bits_8(bar_data_lo);
    Serial.println();
    Serial.flush();

    track.set_bar(ix, bar_data);
  }

  
//  track.set_mod_maj(EEPROM.read(eeprom_location + 0));
//  Serial.print(F("Restore mod_maj "));
//  Serial.print(track.mod_maj()); Serial.println();
//  
//  track.set_mod_min(EEPROM.read(eeprom_location + 1));
//  Serial.print(F("Restore mod_min "));
//  Serial.print(track.mod_min()); Serial.println();
//  
//  track.set_phase_min(EEPROM.read(eeprom_location + 2));
//  Serial.print(F("Restore phase_min "));
//  Serial.print(track.phase_min()); Serial.println();
//  
//  track.set_phase_maj(EEPROM.read(eeprom_location + 3));
//  Serial.print(F("Restore phase_maj "));
//  Serial.print(track.phase_maj()); Serial.println();
//  
//  Serial.print(F("Unflag track state"));
//  Serial.println();
//  Serial.println();
//  Serial.flush();
  track.modified.unset();
}
