#include "tracks/euclidean.h"

tracks::euclidean::euclidean(
  uint8_t const & mod_maj_,
  uint8_t const & mod_min_,
  uint8_t const & phase_min_,
  uint8_t const & phase_maj_
) :
    modified(false),
    _mod_maj(mod_maj_),
    _mod_min(mod_min_),
    _phase_min(phase_min_),
    _phase_maj(phase_maj_)
{};

tracks::euclidean & tracks::euclidean::operator=(euclidean const & other) {
  _mod_maj   = other._mod_maj;
  _phase_maj = other._phase_maj;
  _mod_min   = other._mod_min;
  _phase_min = other._mod_min;

  return *this;
}

bool tracks::euclidean::trigger(uint8_t const & counter) const {
    return 0 == (
      (((uint8_t)(counter - _phase_maj) % _mod_maj) - _phase_min) %
      _mod_min
    );
}

void tracks::euclidean::set_mod_maj(uint8_t const & val) {
  //Serial.println(F("set_mod_maj!"));
  _mod_maj = val;
  modified.set();
}

void tracks::euclidean::set_mod_min(uint8_t const & val) {
  //Serial.println(F("set_mod_min!"));
  _mod_min = val;
  modified.set();
}

void tracks::euclidean::set_phase_min  (uint8_t const & val) {
  //Serial.println(F("set_phase_min!"));
  _phase_min = val;
  modified.set();
}

void tracks::euclidean::set_phase_maj  (uint8_t const & val) {
  //Serial.println(F("set_phase_maj!"));
  _phase_maj = val;
  modified.set();
}

uint8_t tracks::euclidean::mod_maj() const {
  return _mod_maj;
}

uint8_t tracks::euclidean::mod_min() const {
  return _mod_min;
}

uint8_t tracks::euclidean::phase_min() const {
  return _phase_min;
}

uint8_t tracks::euclidean::phase_maj() const {
  return _phase_maj;
}
