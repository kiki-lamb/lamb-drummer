#include "button_pads/encoder_pad_mcp23017.h"

encoder_pad_mcp23017::encoder_pad_mcp23017(
  uint8_t i2c_addr_,
  uint8_t encoder_count_,
  uint8_t button_range_start_
) :
  pad_mcp23017(i2c_addr_, (encoder_count_ << 1), button_range_start_),
  _encoder_count(encoder_count_),
  _encoder_states(NULL)
{
  _encoder_states = (encoder_state *) malloc(
    _encoder_count * sizeof(encoder_state)
  );
  
  dynamic_light_buffer_resize(motion_events_type, motion_events, _encoder_count);
}

encoder_pad_mcp23017::~encoder_pad_mcp23017() {}

bool encoder_pad_mcp23017::read() {
  bool read = false;
  uint16_t tmpval = begin_read(read);

  if (! read) return false;
    
  buttons_ = apply_button_mask(tmpval);
    
  uint16_t partial_mask = 0b11;
  
  partial_mask <<= (_encoder_count-1) << 1;

  for (uint8_t ix = 0; ix < _encoder_count; ix++, partial_mask >>= 2) {
    uint16_t cut = partial_mask & buttons_;
    uint8_t shifted = cut >> (((_encoder_count-1) << 1) - (ix << 1));

    _encoder_states[ix].update(shifted);

    if (_encoder_states[ix].flagged && light_buffer_writable(motion_events)) {
      light_buffer_write(
        motion_events,
        (motion_event { ix, (int8_t)(_encoder_states[ix].motion ^ 1) })
      );
      _encoder_states[ix].motion = 0;
      _encoder_states[ix].flagged = false;
    }
  }
    
  return light_buffer_readable(motion_events);
}
