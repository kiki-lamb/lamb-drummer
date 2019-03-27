#include "buttonpad.h"

Buttonpad::Buttonpad() {}

Buttonpad::~Buttonpad() {}

bool Buttonpad::poll() {
  return impl_poll();
}

uint8_t Buttonpad::button() const {
  return impl_button();
}

void Buttonpad::setup() { impl_setup(); }
