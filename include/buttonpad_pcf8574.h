#ifndef SHELF_CLOCK_BUTTONPAD_PIN_PCF8574_H
#define SHELF_CLOCK_BUTTONPAD_PIN_PCF8574_H

#include "Arduino.h"
#include "buttonpad.h"
#include <Wire.h>
#include <jm_PCF8574.h>

template <uint8_t i2c_addr_>
class Buttonpad_PCF8754 : public Buttonpad {
  private:
    uint8_t  button;
    jm_PCF8574 device;

  public:
    Buttonpad_PCF8754() : button(8) {}

    virtual ~Buttonpad_PCF8754() {}

    virtual void impl_setup() {
      Serial.println(F("Setup Buttonpad_PCF8754..."));

      Wire.begin();
      device.begin(i2c_addr_);

      for (uint8_t ix = 0; ix < 8; ix++)
      device.pinMode(ix, INPUT);

      Serial.print(F("Done setup Buttonpad_PCF8754."));
    }

    virtual bool impl_poll() {
      sei();
      uint8_t tmpval = device.read();
      cli();

      uint8_t pin = 0;

      for (uint8_t mask = 0b1; pin < 8; pin++, mask <<= 1) {
          if (! (tmpval & mask)) {
            break;
          }
      }

      if (pin != button) {
        button = pin;

        if (button != 8) {
          Serial.print(F("Pressed button "));
          Serial.print(pin);
          Serial.println();
          return true;
        }
      }

      return false;
    }

    virtual uint8_t impl_button() const {
      return button;
    }
};

#endif
