#ifdef LAMB_DRUMMER_USE_LAMB_ENCODER

#include "controls/encoder.h"

encoder::enc_t encoder::_encoder;

encoder::encoder() {};

encoder::~encoder() {}

void encoder::set_value(uint8_t const & value) {
  _encoder.state().set_value(value);
}

uint8_t encoder::value() {
  static const uint8_t MIN = 8;
  uint8_t val = _encoder.state().value();
  if (val < MIN) {
    val = MIN;
    _encoder.state().set_value(val);
  }
  return val;
}

void encoder::setup() {
  _encoder.setup();

  // Attaching from inside setup() is fucking broken for some reason. Manually attach until it's fixed:
  attachInterrupt(digitalPinToInterrupt(encoderA), enc_interface_t::update, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderB), enc_interface_t::update, CHANGE);
}

#endif
