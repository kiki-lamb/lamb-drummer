#include "controls/button_pad_mcp23017.h"

button_pad_mcp23017::~button_pad_mcp23017() {}
    
button_pad_mcp23017::button_pad_mcp23017(
  uint8_t button_count_,
  uint8_t button_range_start_
) :
  pad_mcp23017(button_count_, button_range_start_)
{
  dynamic_light_buffer_resize(button_event, button_events, button_count);
}

bool button_pad_mcp23017::read() {
  bool read = false;
  uint16_t tmpval = begin_read(read);

  if (! read) return false;
  
  uint16_t new_buttons = apply_button_mask(tmpval & ~buttons_);

  uint16_t partial_mask = 0b1;

  partial_mask <<= (button_count-1);
  
  for (uint8_t ix = 0; ix < button_count; ix++, partial_mask >>=1 ) {
    if (new_buttons & partial_mask) {
      light_buffer_write(
        button_events,
        (button_event { ix, true })
      );
    }
  }
  
  buttons_ = tmpval;

  if (0 != new_buttons) {
    return true;
  }

  return false;
}
