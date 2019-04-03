#include "controls/button.h"

Button::Button(
  uint8_t pin_,
  bool adc_state_
) :
  pin(pin_),
  adc_state(adc_state_) {
};

Button::~Button() {}

void Button::setup() {
  pinMode(pin, INPUT_PULLUP);
}

bool Button::read() {
  uint16_t adc_last = analogRead(pin);

  if      (adc_state    && (adc_last < 0b01000000))
    adc_state = false;
  else if ((!adc_state) && (adc_last > 0b11000000))
    adc_state = true;
  return ! adc_state;
}
