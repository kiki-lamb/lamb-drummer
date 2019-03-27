#include "buttonpad.h"

Buttonpad::Buttonpad() {}

Buttonpad::~Buttonpad() {}

bool Buttonpad::read() {
  return impl_read();
}

uint8_t Buttonpad::button() const {
  return impl_button();
}

void Buttonpad::setup() { impl_setup(); }
