#ifndef LAMB_DRUMMER_BUTTONPAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTONPAD_PIN_MCP23017_H

#include <Arduino.h>
#include "buttonpad.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "i2c_lock.h"

template <
  uint8_t i2c_addr_,
  uint8_t button_count = 16,
  uint8_t button_range_start = 0
  > 
class Buttonpad_MCP23017 : public Buttonpad {
private:
  uint8_t           _button;
  Adafruit_MCP23017 device;

public:
  Buttonpad_MCP23017() : _button(button_range_start+button_count+1) {}

  virtual ~Buttonpad_MCP23017() {}

  virtual void impl_setup() {
    Serial.println(F("Setup Buttonpad_MCP23017...")); Serial.flush();

    device.begin(i2c_addr_);

    for (uint8_t ix = 0; ix < 16; ix++) {
      device.pinMode(ix, INPUT);
      device.pullUp(ix, HIGH);
    }

    Serial.println(F("Done setup Buttonpad_MCP23017.")); Serial.flush();
  }

  virtual bool impl_read() {
//    Serial.println("MCP read..."); Serial.flush();
    
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
//    if (0x3 == i2c_addr_) {
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
//    }
#endif
    
    uint8_t pin = button_range_start;
    uint16_t mask = 0b1 << (button_range_start);

    
    // 7   6   5   4   3   2   1   0
    //                             1
    //                             pin
    
    // 7   6   5   4   3   2   1   0
    //                         1   0
    //                         pin

    ////
    
    // 7   6   5   4   3   2   1   0
    //             1   0   0   0   0
    //             pin
    
    // 7   6   5   4   3   2   1   0
    //         1   0
    //         pin

    for (; pin < (button_range_start+button_count); pin++, mask <<= 1) {
      if (! (tmpval & mask)) {
        break;
      }
    }

//    Serial.print("Break at pin "); Serial.flush();
//    Serial.print(pin); Serial.flush();
//    Serial.print(", "); Serial.flush();

    pin -= button_range_start;
    
    if (pin != _button) {
      _button = pin;
      
      if (_button < button_count) {
        Serial.print(F("Pressed button ")); Serial.flush();
        Serial.print(_button); Serial.flush();
        Serial.println(); Serial.flush();

        return true;
      }
    }

//    Serial.print(F("No button, pin = ")); // = ")); Serial.flush();
//    Serial.print(pin); Serial.flush();
//    Serial.print(", button = "); Serial.flush();
//    Serial.print(_button); Serial.flush();
//    Serial.println(); Serial.flush();
    
    return false;
  }

  virtual uint8_t impl_button() const {
    return _button;
  }
};

#endif
