#include "button_pads/button_pad_mcp23017.h"

button_pad_mcp23017::button_pad_mcp23017(
  uint8_t i2c_addr_, 
  uint8_t button_count_,
  uint8_t button_range_start_
) :
  pad_mcp23017(i2c_addr_, button_count_, button_range_start_),
  new_buttons(0) {}

button_pad_mcp23017::~button_pad_mcp23017() {}

// void button_pad_mcp23017::setup(Adafruit_MCP23017 * _device) {
//   Serial.print(F("Setup button_pad_MCP23017 @ 0x"));
//   Serial.print(i2c_addr, HEX);
//   Serial.println(F("...")); Serial.flush();

//   device = _device;

//   for (uint8_t ix = 0; ix < 16; ix++) {
//     device->pinMode(ix, INPUT);
//     device->pullUp(ix, HIGH);
//   }

//   uint16_t partial_mask = 0x8000;
    
//   for (uint8_t ix = 0; ix < button_count; ix++, partial_mask >>= 1 ) {
//     button_mask |= partial_mask;
//   }

//   button_mask >>= button_range_start;    

//   button_shift = 16 - button_count - button_range_start;
// }
    
bool button_pad_mcp23017::read() {
#ifdef LOG_I2C_LOCK
  Serial.print(F("B:ir ")); Serial.flush();
#endif

  if (! i2c_lock::claim())
    return false;

  uint16_t tmpval = device->readGPIOAB();
    
  i2c_lock::release();

#ifdef LOG_BUTTONPAD_MCP_RAW_READING
  Serial.print(F("raw =>   ")); Serial.flush();
  util::print_bits_16(tmpval);
#endif
    
  tmpval = ~tmpval;  

#ifdef LOG_I2C_LOCK
  Serial.print(F("B:ir ")); Serial.flush();
#endif

  new_buttons = tmpval & ~buttons_; //  ^ tmpval;

  if (button_mask != 0xffff) {
    new_buttons &= button_mask;
  }

  if (button_shift != 0) {
    new_buttons >>= button_shift;
  }
    
#ifdef LOG_BUTTONPAD_MCP_RAW_READING
  Serial.print("MCP @ 0x");
  Serial.print(i2c_addr, HEX);

  Serial.print(F(" old =>   ")); Serial.flush();
  util::print_bits_16(buttons_);

  Serial.print(F("read =>   ")); Serial.flush();
  util::print_bits_16(tmpval);    
#endif

  buttons_ = tmpval;

  if (0 != new_buttons) {
#ifdef LOG_BUTTONPAD_MCP_OUTPUT
    Serial.print("MCP @ 0x");
    Serial.print(i2c_addr, HEX);

    Serial.print(" Give buttons: ");
    util::print_bits_16(new_buttons);
    Serial.println();
    Serial.flush();
#endif
      
    return true;
  }

  return false;
}

uint16_t button_pad_mcp23017::buttons() const {
  return new_buttons;
}

