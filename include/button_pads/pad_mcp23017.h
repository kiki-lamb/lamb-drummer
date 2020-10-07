#ifndef LAMB_DRUMMER_PAD_MCP23017_H
#define LAMB_DRUMMER_PAD_MCP23017_H

#include <inttypes.h>
#include "Adafruit_MCP23017.h"

class pad_mcp23017 {
protected:
  uint8_t             i2c_addr;
  uint8_t             button_count;
  uint8_t             button_range_start;
  Adafruit_MCP23017 * device;
  uint16_t            buttons_;
  uint16_t            button_mask;
  uint8_t             button_shift;       
  
public:
  explicit pad_mcp23017(
    uint8_t i2c_addr_, 
    uint8_t button_count_ = 16,
    uint8_t button_range_start_ = 0
  );

  virtual ~pad_mcp23017();

  void setup(Adafruit_MCP23017 * _device);
};

#endif
