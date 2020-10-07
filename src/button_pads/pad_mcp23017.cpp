#include "button_pads/pad_mcp23017.h"
#include <Arduino.h>

pad_mcp23017::pad_mcp23017(
    uint8_t i2c_addr_, 
    uint8_t button_count_,
    uint8_t button_range_start_
) : i2c_addr(i2c_addr_),           
  button_count(button_count_), 
  button_range_start(button_range_start_), 
  device(NULL),             
  buttons_(0),           
  button_mask(0), 
  button_shift(0) {}
  
pad_mcp23017::~pad_mcp23017() {}

void pad_mcp23017::setup(Adafruit_MCP23017 * _device) {
  Serial.print(F("Setup pad_MCP23017 @ 0x"));
  Serial.print(i2c_addr, HEX);
  Serial.println(F("...")); Serial.flush();

  device = _device;

  for (uint8_t ix = 0; ix < 16; ix++) {
    device->pinMode(ix, INPUT);
    device->pullUp(ix, HIGH);
  }

  uint16_t partial_mask = 0x8000;
    
  for (uint8_t ix = 0; ix < button_count; ix++, partial_mask >>= 1 ) {
    button_mask |= partial_mask;
  }

  button_mask >>= button_range_start;    

  button_shift = 16 - button_count - button_range_start;
}
