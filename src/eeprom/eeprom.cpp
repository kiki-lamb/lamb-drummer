#include "Arduino.h"
#include "eeprom/eeprom.h"

#define ADDR_BPM  3
#define ADDR_PLAY 4

eeprom::eeprom() : save_requested(), last_edit(0) {}

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

template<>
void eeprom::save_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
) const {
  // if (! track.modified.consume() )
  //  return;

  EEPROM.write(eeprom_location + 0, track.mod_maj());
  Serial.print(F("Save mod_maj ")); Serial.print(track.mod_maj()); Serial.println();

  EEPROM.write(eeprom_location + 1, track.mod_min());
  Serial.print(F("Save mod_min ")); Serial.print(track.mod_min()); Serial.println();

  EEPROM.write(eeprom_location + 2, track.phase_min());
  Serial.print(F("Save phase_min ")); Serial.print(track.phase_min()); Serial.println();

  EEPROM.write(eeprom_location + 3, track.phase_maj());
  Serial.print(F("Save phase_maj ")); Serial.print(track.phase_maj()); Serial.println();

  Serial.println(F("Saved track"));
}

template<>
void eeprom::restore_track<tracks::euclidean>(
  size_t const & eeprom_location,
  tracks::euclidean & track
) {
  track.set_mod_maj(EEPROM.read(eeprom_location + 0));
  Serial.print(F("Restore mod_maj ")); Serial.print(track.mod_maj()); Serial.println();

  track.set_mod_min(EEPROM.read(eeprom_location + 1));
  Serial.print(F("Restore mod_min ")); Serial.print(track.mod_min()); Serial.println();

  track.set_phase_min(EEPROM.read(eeprom_location + 2));
  Serial.print(F("Restore phase_min ")); Serial.print(track.phase_min()); Serial.println();

  track.set_phase_maj(EEPROM.read(eeprom_location + 3));
  Serial.print(F("Restore phase_maj ")); Serial.print(track.phase_maj()); Serial.println();

  Serial.print(F("Unflag track state"));
  Serial.println();
  Serial.println();
  Serial.flush();
  track.modified.unset();
}
