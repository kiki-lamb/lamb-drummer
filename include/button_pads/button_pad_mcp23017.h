#ifndef LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H

#include <Arduino.h>
#include "button_pad.h"
#include <Wire.h>
#include "i2c_lock.h"
#include "util/util.h"
#include "button_pads/pad_mcp23017.h"

class button_pad_mcp23017 :
  public button_pad<uint16_t>,
  public pad_mcp23017 {
private:
  uint16_t            new_buttons;
  
public:
  button_pad_mcp23017(
    uint8_t i2c_addr_, 
    uint8_t button_count_ = 16,
    uint8_t button_range_start_ = 0
  );

  virtual ~button_pad_mcp23017();

  virtual void setup() override;
  virtual void setup(Adafruit_MCP23017 * _device);
  virtual void impl_setup() override;    
  virtual bool impl_read() override;
  virtual uint16_t impl_buttons() const override;
};

#endif
