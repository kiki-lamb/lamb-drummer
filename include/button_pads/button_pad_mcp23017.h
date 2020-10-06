#ifndef LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H

#include <Arduino.h>
#include "button_pad.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "i2c_lock.h"

template <uint8_t i2c_addr_>
class button_pad_mcp23017 : public button_pad<uint16_t> {
private:
  uint16_t          buttons_;
  uint16_t          new_buttons;
  Adafruit_MCP23017 device;

public:
  button_pad_mcp23017() : buttons_(0) {}

  virtual ~button_pad_mcp23017() {}

  virtual void impl_setup() {
    Serial.println(F("Setup button_pad_MCP23017...")); Serial.flush();

    device.begin(i2c_addr_);

    for (uint8_t ix = 0; ix < 16; ix++) {
      device.pinMode(ix, INPUT);
      device.pullUp(ix, HIGH);
    }

    Serial.println(F("Done setup button_pad_MCP23017.")); Serial.flush();
  }

  void print_bits_16(uint16_t tmpval) const {
    for(uint16_t mask = 32768; mask; mask >>= 1) {
      if(mask  & tmpval) {
        Serial.print('1'); Serial.flush();
      }
      else {
        Serial.print('.'); Serial.flush();
      }
    }
  }
  
  virtual bool impl_read() {
#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif
    if (! i2c_lock::claim()) return false;

    char cSREG = SREG;    

    sei();

    uint16_t tmpval = ~device.readGPIOAB();

    i2c_lock::release();

    SREG = cSREG;    

#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif

//#ifdef LOG_BUTTONPAD_MCP_RAW_READING
    Serial.print(F("old =>   ")); Serial.flush();
    print_bits_16(tmpval);
    
//#endif

    new_buttons = buttons_ ^ tmpval;

    Serial.print(F(" new =>   ")); Serial.flush();
    print_bits_16(new_buttons);
    Serial.println();

    delay(50);

    buttons_ = tmpval;

    return 0 != new_buttons;
      
  }

  virtual uint16_t impl_buttons() const {
    Serial.print("Returning ");
    print_bits_16(new_buttons);
    Serial.println();
    Serial.flush();
    
    return new_buttons;
  }
};

#endif
