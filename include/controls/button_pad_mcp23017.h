#ifndef LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H

#include <Arduino.h>
#include "lamb.h"
#include "controls/pad_mcp23017.h"

class button_pad_mcp23017 : public pad_mcp23017 {
public:
  struct button_event {
    uint8_t button_number;
    bool button_state;
  };
  
  declare_dynamic_light_buffer(button_event, button_events);

private:
  button_pad_mcp23017();

public:
  explicit button_pad_mcp23017(
    uint8_t button_count_,
    uint8_t button_range_start_
  );

  /* virtual */ ~button_pad_mcp23017();

  /* virtual */ bool read();
};

#endif
