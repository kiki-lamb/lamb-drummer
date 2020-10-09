#include "controls/button_pad_mcp23017.h"

// button_pad_mcp23017::button_pad_mcp23017() {
//   /* private */
// }

button_pad_mcp23017::button_pad_mcp23017(
  uint8_t button_count_,
  uint8_t button_range_start_
) :
  pad_mcp23017(button_count_, button_range_start_),
  new_buttons(0) {}

button_pad_mcp23017::~button_pad_mcp23017() {}
    
bool button_pad_mcp23017::read() {
  bool read = false;
  uint16_t tmpval = begin_read(read);

  if (! read) return false;
  
  new_buttons = apply_button_mask(tmpval & ~buttons_);
  
  buttons_ = tmpval;

  if (0 != new_buttons) {
    return true;
  }

  return false;
}

uint16_t button_pad_mcp23017::buttons() const {
  return new_buttons;
}

