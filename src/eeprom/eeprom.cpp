#include "Arduino.h"
#include "eeprom/eeprom.h"
#include "tracks/euclidean.h"
#include "tracks/x0x.h"

#define ADDR_BPM  3
#define ADDR_PLAY 4

eeprom::eeprom() :
  saved_bpm(0),
  saved_playback_state(false),
  save_ix(0xff),
  save_addr(5),
  save_requested() {}

void eeprom::flag_save_requested() {
  save_requested.set();
  save_ix   = 0;
  save_addr = 5;
}

void eeprom::unflag_save_requested() {
  save_requested.unset();
}

void eeprom::save_playback_state(bool const & playback_state_) {
  Serial.print(F("Save playback_state "));
  Serial.println(playback_state_ ? 1 : 0);

  write_to_queue(ADDR_PLAY, playback_state_);
}

bool eeprom::write_to_queue(int idx_, uint8_t val_) {
  if (! light_buffer_writable(queue)) return false;
  
  light_buffer_write(queue, queued_write(idx_, val_));
  
  Serial.print(F("Queued write 0x"));
  Serial.print(idx_, HEX);
  Serial.print(F(" = "));
  Serial.print(val_);
  Serial.println();
  
  return true;
}

bool eeprom::write_from_queue() {
  if (light_buffer_readable(queue)) {
    queued_write q_w =
      light_buffer_read(queue);
    
    Serial.print(F("Write queued 0x"));
    Serial.print(q_w.idx, HEX);
    Serial.print(F(" = "));
    Serial.print(q_w.val);
    Serial.println();
  
    EEPROM.write(
      q_w.idx,
      q_w.val
    );

    return true;
  }

  return false;
}

void eeprom::save_bpm(uint8_t const & bpm_) {
  Serial.print(F("Save BPM "));
  Serial.println(bpm_);
  write_to_queue(ADDR_BPM, bpm_);
}

bool eeprom::playback_state() const {
  saved_playback_state = EEPROM.read(ADDR_PLAY);

  Serial.print(F("Load playback_state "));
  Serial.println(saved_playback_state ? F("play") : F("pause"));
  return saved_playback_state;
}

uint8_t eeprom::bpm() const {
  saved_bpm = EEPROM.read(ADDR_BPM);
  
  Serial.print(F("Load BPM "));
  Serial.println(saved_bpm);

  return saved_bpm;
}

template <>
void eeprom::save_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
) {
  write_to_queue(eeprom_location + 0, track.mod_maj());
  Serial.print(F("Save mod_maj "));
  Serial.print(track.mod_maj()); Serial.println();
  
  write_to_queue(eeprom_location + 1, track.mod_min());
  Serial.print(F("Save mod_min "));
  Serial.print(track.mod_min()); Serial.println();
  
  write_to_queue(eeprom_location + 2, track.phase_min());
  Serial.print(F("Save phase_min "));
  Serial.print(track.phase_min()); Serial.println();
  
  write_to_queue(eeprom_location + 3, track.phase_maj());
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
) {
  Serial.print(F(" 0x"));
  Serial.print(eeprom_location, HEX);
  Serial.print(F(" bars_count = "));
  Serial.print(track.bars_count());
  Serial.println();
  Serial.flush();

  write_to_queue(eeprom_location + 0, track.bars_count());

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

    write_to_queue(loc + 0, bar_data_hi);
    write_to_queue(loc + 1, bar_data_lo);
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

  track.modified.unset();
}
