#include "encoder_button.h"

EncoderButton::EncoderButton(
  uint8_t pin_,
  bool adc_state_
) :
  pin(pin_),
  adc_state(adc_state_) {
};

EncoderButton::~EncoderButton() {}

void EncoderButton::setup() {
  pinMode(pin, INPUT_PULLUP);
}

bool EncoderButton::read() {
  uint16_t adc_last = analogRead(pin);

  if      (adc_state    && (adc_last < 0b01000000)) {
    adc_state = false;
    return true;
  }
  else if ((!adc_state) && (adc_last > 0b11000000))
    adc_state = true;
    return false;
}
