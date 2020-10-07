#include "button_pads/pad_mcp23017.h"

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
