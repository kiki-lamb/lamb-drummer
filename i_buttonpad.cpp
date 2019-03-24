#include "i_buttonpad.h"

IButtonpad::IButtonpad() {}

IButtonpad::~IButtonpad() {}

bool IButtonpad::read() { 
  return impl_read();
}

uint8_t IButtonpad::buttonpad_button() const { 
  return impl_buttonpad_button(); 
}

void IButtonpad::setup() { impl_setup(); }

