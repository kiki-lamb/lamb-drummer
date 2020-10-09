#ifndef LAMB_DRUMMER_ENCODER_PAD_MCP23017_H
#define LAMB_DRUMMER_ENCODER_PAD_MCP23017_H

#include <inttypes.h>
#include "lamb.h"
#include "controls/pad_mcp23017.h"
#include "encoder_state/encoder_state.h"

class encoder_pad_mcp23017 : public pad_mcp23017 {
private:
  uint8_t _encoder_count;

  encoder_state * _encoder_states;
  
public:
  struct motion_event {
    uint8_t encoder_number;
    int8_t motion;
  };

  declare_dynamic_light_buffer(motion_event, motion_events);

public:
  explicit encoder_pad_mcp23017(
    uint8_t encoder_count_,
    uint8_t button_range_start_ = 0
  );
  
  /* virtual */ ~encoder_pad_mcp23017();

  /* virtual */ bool read();  
};

#endif












