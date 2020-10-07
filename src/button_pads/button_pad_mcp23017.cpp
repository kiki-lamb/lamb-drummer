#include "button_pads/button_pad_mcp23017.h"

button_pad_mcp23017::button_pad_mcp23017(
  uint8_t i2c_addr_, 
  uint8_t button_count_,
  uint8_t button_range_start_
) :
  pad_mcp23017(i2c_addr_, button_count_, button_range_start_),
  new_buttons(0) {}

button_pad_mcp23017::~button_pad_mcp23017() {}
    
bool button_pad_mcp23017::read() {
  bool read = false;
  uint16_t tmpval = begin_read(read);

  if (! read) return false;
  
  new_buttons = tmpval & ~buttons_; //  ^ tmpval;

  if (button_mask != 0xffff) {
    new_buttons &= button_mask;
  }

  if (button_shift != 0) {
    new_buttons >>= button_shift;
  }

  buttons_ = tmpval;

  if (0 != new_buttons) {
    return true;
  }

  return false;
}

uint16_t button_pad_mcp23017::buttons() const {
  return new_buttons;
}

