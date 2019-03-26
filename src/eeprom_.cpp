#include "Arduino.h"
#include "eeprom_.h"

#define ADDR_BPM  3
#define ADDR_PLAY 4

Eeprom::Eeprom() : last_edit(0), save_requested("sr") {}

Eeprom::~Eeprom() {}

void Eeprom::flag_save_requested() {
  save_requested.flag();
  last_edit = millis();
}

void Eeprom::unflag_save_requested() {
  save_requested.unflag();
}

void Eeprom::save_playback_state(bool playback_state_) const {
  Serial.print(F("Save playback_state state "));
  Serial.println(playback_state_ ? F("ON") : F("OFF"));

  EEPROM.write(ADDR_PLAY, playback_state_);
}

void Eeprom::save_bpm(uint8_t bpm_) const {
  Serial.print(F("Save BPM "));
  Serial.println(bpm_);
  EEPROM.write(ADDR_BPM, bpm_);
}

bool Eeprom::playback_state() const {
  bool tmp = EEPROM.read(ADDR_PLAY);

  Serial.print(F("Load playback_state: "));
  Serial.println(tmp ? F("play") : F("pause"));
  return tmp;
}

uint8_t Eeprom::bpm() const {
  uint8_t tmp = EEPROM.read(ADDR_BPM);

  Serial.print(F("Load BPM: "));
  Serial.println(tmp);

  return tmp;
}

void Eeprom::save_track_state(
  size_t eeprom_location,
  TrackState & track_state
) const {
  if (! track_state.modified.consume() )
    return;

  EEPROM.write(eeprom_location + 0, track_state.mod_maj());
  Serial.print(F("Save mod_maj ")); Serial.print(track_state.mod_maj()); Serial.println();

  EEPROM.write(eeprom_location + 1, track_state.mod_min());
  Serial.print(F("Save mod_min ")); Serial.print(track_state.mod_min()); Serial.println();

  EEPROM.write(eeprom_location + 2, track_state.phase_min());
  Serial.print(F("Save phase_min ")); Serial.print(track_state.phase_min()); Serial.println();

  EEPROM.write(eeprom_location + 3, track_state.phase_maj());
  Serial.print(F("Save phase_maj ")); Serial.print(track_state.phase_maj()); Serial.println();

  Serial.println(F("Saved track_state."));
}

void Eeprom::restore_track_state(
  size_t eeprom_location,
  TrackState & track_state
) {
  track_state.set_mod_maj(EEPROM.read(eeprom_location + 0));
  Serial.print(F("Restore mod_maj ")); Serial.print(track_state.mod_maj()); Serial.println();

  track_state.set_mod_min(EEPROM.read(eeprom_location + 1));
  Serial.print(F("Restore mod_min ")); Serial.print(track_state.mod_min()); Serial.println();

  track_state.set_phase_min  (EEPROM.read(eeprom_location + 2));
  Serial.print(F("Restore phase_min ")); Serial.print(track_state.phase_min()); Serial.println();

  track_state.set_phase_maj (EEPROM.read(eeprom_location + 3));
  Serial.print(F("Restore phase_maj ")); Serial.print(track_state.phase_maj()); Serial.println();

  Serial.print(F("(Unflag a track state) "));
  Serial.println();
  Serial.println();
  Serial.flush();
  track_state.modified.unflag();
}
