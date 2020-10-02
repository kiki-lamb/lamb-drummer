#ifndef LAMB_DRUMMER_BUTTONPAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTONPAD_PIN_MCP23017_H

#include <Arduino.h>
#include "buttonpad.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "i2c_lock.h"

template <uint8_t i2c_addr_>
class Buttonpad_MCP23017 : public Buttonpad {
private:
  uint8_t           _button;
  Adafruit_MCP23017 device;

public:
  Buttonpad_MCP23017() : _button(8) {}

  virtual ~Buttonpad_MCP23017() {}

  virtual void impl_setup() {
    Serial.println(F("Setup Buttonpad_MCP23017..."));

    Wire.begin();

    device.begin(i2c_addr_);

    for (uint8_t ix = 0; ix < 8; ix++) {
      device.pinMode(ix, INPUT);
      device.pullUp(ix, HIGH);
    }

    Serial.println(F("Done setup Buttonpad_MCP23017."));
  }

  virtual bool impl_read() {
    /* Serial.print(F("Buttonpad_MCP23017::impl_read ")); */ if (! I2CLock::claim()) return false;

    char cSREG = SREG;    

    sei();

    uint16_t tmpval = device.readGPIOAB();

    /* Serial.print(F("Buttonpad_MCP23017::impl_read ")); */ I2CLock::release();

    SREG = cSREG;    
    
    Serial.print(F("READ: "));
    
    {
      for(uint16_t mask = 0xF0; mask; mask >>= 1) {
        if(mask  & tmpval)
          Serial.print('1');
        else
          Serial.print('0');
      }
    }

    Serial.print(F(" "));
    Serial.println(millis());
          
    uint8_t pin = 0;

    for (uint8_t mask = 0b1; pin < 8; pin++, mask <<= 1) {
      if (! (tmpval & mask)) {
        break;
      }
    }

    if (pin != _button) {
      _button = pin;

      if (_button != 8) {
        //Serial.print(F("Pressed button "));
        //Serial.print(pin);
        //Serial.println();
        return true;
      }
    }

    return false;
  }

  virtual uint8_t impl_button() const {
    return _button;
  }
};

#endif
