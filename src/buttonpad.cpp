#include "buttonpad.h"

Buttonpad::Buttonpad() {}

Buttonpad::~Buttonpad() {}

bool Buttonpad::read() { 
  return impl_read();
}

uint8_t Buttonpad::buttonpad_button() const { 
  return impl_buttonpad_button(); 
}

void Buttonpad::setup() { impl_setup(); }

