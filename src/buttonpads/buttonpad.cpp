#include "buttonpads/buttonpad.h"

button_pad::button_pad() {}

button_pad::~button_pad() {}

bool button_pad::read() {
  return impl_read();
}

uint8_t button_pad::button() const {
  return impl_button();
}

void button_pad::setup() { impl_setup(); }
