#ifndef LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H

#include <Arduino.h>
#include <Wire.h>
#include "util/util.h"
#include "controls/pad_mcp23017.h"

class button_pad_mcp23017 :
  public pad_mcp23017 {
private:
  uint16_t            new_buttons;
  
public:
  explicit button_pad_mcp23017(
    uint8_t button_count_,
    uint8_t button_range_start_
  );

  /* virtual */ ~button_pad_mcp23017();

  /* virtual */ bool read();

  /* virtual */ uint16_t buttons() const;
};

#endif
