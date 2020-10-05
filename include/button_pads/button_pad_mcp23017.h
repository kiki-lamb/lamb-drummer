#ifndef LAMB_DRUMMERBUTTON_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTONPAD_PIN_MCP23017_H

#include <Arduino.h>
#include "button_pad.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "i2c_lock.h"

template <
  uint8_t i2c_addr_,
  uint8_t button_count = 16,
  uint8_t button_range_start = 0
  > 
class button_pad_mcp23017 : public button_pad {
private:
  uint8_t           button_;
  Adafruit_MCP23017 device;

public:
  button_pad_mcp23017() : button_(button_range_start+button_count+1) {}

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

  virtual bool impl_read() {
#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif
    if (! I2CLock::claim()) return false;

    char cSREG = SREG;    

    sei();

    uint16_t tmpval = device.readGPIOAB();

    I2CLock::release();

    SREG = cSREG;    

#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif

#ifdef LOG_BUTTONPAD_MCP_RAW_READING
      Serial.print(F("=>   ")); Serial.flush();
      {
        for(uint16_t mask = 32768; mask; mask >>= 1) {
          if(mask  & tmpval) {
            Serial.print('1'); Serial.flush();
          }
          else {
            Serial.print('0'); Serial.flush();
          }
        }
      }
      Serial.println(); Serial.flush();
#endif
    
    uint8_t pin = button_range_start;
    uint16_t mask = 0b1 << (button_range_start);
    
    for (; pin < (button_range_start+button_count); pin++, mask <<= 1) {
      if (! (tmpval & mask)) {
        break;
      }
    }

    pin -= button_range_start;
    
    if (pin != button_) {
      button_ = pin;
      
      if (button_ < button_count) {
        Serial.print(F("Pressed button ")); Serial.flush();
        Serial.print(button_); Serial.flush();
        Serial.println(); Serial.flush();

        return true;
      }
    }
    
    return false;
  }

  virtual uint8_t impl_button() const {
    return button_;
  }
};

#endif