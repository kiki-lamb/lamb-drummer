#include "controls/pad_mcp23017.h"
#include <Arduino.h>
#include "i2c_lock/i2c_lock.h"
#include "util/util.h"

pad_mcp23017::pad_mcp23017(
    uint8_t button_count_,
    uint8_t button_range_start_
) :
  button_count(button_count_), 
  button_range_start(button_range_start_), 
  device(NULL),             
  buttons_(0),           
  button_mask(0), 
  button_shift(0) {}
  
//pad_mcp23017::~pad_mcp23017() {}

void pad_mcp23017::setup(Adafruit_MCP23017 * _device) {
  device = _device;

  for (uint8_t ix = button_range_start;
       ix < (button_range_start+button_count);
       ix++) {
    device->pinMode(ix, INPUT);
    device->pullUp(ix, HIGH);
  }

  uint16_t partial_mask = 0x8000;
    
  for (
    uint8_t ix = 0;
    ix < button_count;
    ix++, partial_mask >>= 1) {
    button_mask |= partial_mask;
  }

  button_mask >>= button_range_start;    
  button_shift = button_count - button_range_start;
  button_shift = 16 - button_count - button_range_start;
}

uint16_t pad_mcp23017::apply_button_mask(uint16_t const & value) {
  uint16_t tmp = value;
  
  if (button_mask != 0xffff) {
    tmp &= button_mask;
  }

  if (button_shift != 0) {
    tmp >>= button_shift;
  }
  
  return tmp;  
}

uint16_t pad_mcp23017::begin_read(bool & succeeded) {
  #ifdef LOG_I2C_LOCK
    Serial.print(F("E:ir ")); Serial.flush();
#endif

    if (! i2c_lock::claim()) {
      succeeded = false;

      return 0;
    }

    uint16_t tmpval = device->readGPIOAB();
    
    i2c_lock::release();

    tmpval = ~tmpval;  

    if (tmpval == buttons_) {
      succeeded = 0;
      
      return 0;
    }

#ifdef LOG_I2C_LOCK
    Serial.print(F("E:ir ")); Serial.flush();
#endif

    succeeded = true;
    
    return tmpval;
}
