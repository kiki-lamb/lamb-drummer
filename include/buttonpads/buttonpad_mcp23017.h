#ifndef LAMB_DRUMMER_BUTTONPAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTONPAD_PIN_MCP23017_H

#include <Arduino.h>
#include "buttonpad.h"
#include "Adafruit_MCP23017.h"

template <uint8_t i2c_addr_>
class Buttonpad_MCP23017 : public Buttonpad {
  private:
    uint8_t  _button;
    Adafruit_MCP23017 device;

  public:
    Buttonpad_MCP23017() : _button(8) {}

    virtual ~Buttonpad_MCP23017() {}

    virtual void impl_setup() {
      Serial.println(F("Setup Buttonpad_MCP23017..."));

      device.begin(i2c_addr_);

      for (uint8_t ix = 0; ix < 8; ix++) {
        device.pinMode(ix, INPUT);
        device.pullUp(ix, HIGH);
      }

      Serial.print(F("Done setup Buttonpad_MCP23017."));
    }

    virtual bool impl_read() {
      sei();
      uint8_t tmpval0 = device.readGPIO(0);
      uint8_t tmpval1 = device.readGPIO(1);
      cli();

      Serial.print("A: ");
      Serial.println(tmpval0, BIN);
      
      Serial.print("B: ");
      Serial.println(tmpval1, BIN);
      
      
      uint8_t pin = 0;

      for (uint8_t mask = 0b1; pin < 8; pin++, mask <<= 1) {
          if (! (tmpval0 & mask)) {
            break;
          }
      }

      if (pin != _button) {
        _button = pin;

        if (_button != 8) {
          Serial.print(F("Pressed button "));
          Serial.print(pin);
          Serial.println();
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
