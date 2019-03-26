#include "track_state.h"

TrackState::TrackState(
  uint8_t mod_maj_,
  uint8_t mod_min_,
  uint8_t phase_min_,
  uint8_t phase_maj_
) : _mod_min(mod_min_),
    _mod_maj(mod_maj_),
    _phase_min(phase_min_),
    _phase_maj(phase_maj_) {
};

TrackState::~TrackState() {};

TrackState & TrackState::operator=(TrackState const & other) {
  _mod_maj   = other._mod_maj;
  _phase_maj = other._phase_maj;
  _mod_min   = other._mod_min;
  _phase_min = other._mod_min;
}

bool TrackState::trigger_state(uint8_t counter) const {
    return 0 == ((((uint8_t)(counter - _phase_maj) % _mod_maj) - _phase_min) % _mod_min);
}

void TrackState::set_mod_maj(uint8_t val) {
  Serial.println(F("set_mod_maj!"));
  _mod_maj = val;
  modified.flag();
}

void TrackState::set_mod_min(uint8_t val) {
  Serial.println(F("set_mod_min!"));
  _mod_min = val;
  modified.flag();
}

void TrackState::set_phase_min  (uint8_t val) {
  Serial.println(F("set_phase_min!"));
  _phase_min = val;
  modified.flag();
}

void TrackState::set_phase_maj  (uint8_t val) {
  Serial.println(F("set_phase_maj!"));
  _phase_maj = val;
  modified.flag();
}

uint8_t TrackState::mod_maj() const {
  return _mod_maj;
}

uint8_t TrackState::mod_min() const {
  return _mod_min;
}

uint8_t TrackState::phase_min() const {
  return _phase_min;
}

uint8_t TrackState::phase_maj() const {
  return _phase_maj;
}
