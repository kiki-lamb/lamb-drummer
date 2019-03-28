#include "controls/encoder.h"

Encoder::enc_t Encoder::_encoder;

Encoder::Encoder() {};

Encoder::~Encoder() {}

void Encoder::set_value(uint8_t value) {
  _encoder.state().set_value(value);
}

uint8_t Encoder::value() {
  return _encoder.state().value();
}

void Encoder::setup() {
  _encoder.setup();

  // Attaching from inside setup() is fucking broken for some reason. Manually attach until it's fixed:
  attachInterrupt(digitalPinToInterrupt(encoderA), enc_interface_t::update, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderB), enc_interface_t::update, CHANGE);
}
