#include "controls/encoder.h"

Encoder::enc_t Encoder::encoder;

Encoder::Encoder() {};

Encoder::~Encoder() {}

void Encoder::set_value(uint8_t value) {
  encoder.state().set_value(value);
}

uint8_t Encoder::value() {
  return encoder.state().value();
}

void Encoder::setup() {
  encoder.setup();

  // Attaching from inside setup() is fucking broken for some reason. Manually attach until it's fixed:
  attachInterrupt(digitalPinToInterrupt(encoderA), enc_interface_t::update, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderB), enc_interface_t::update, CHANGE);
}
