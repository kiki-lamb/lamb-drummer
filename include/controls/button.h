#ifndef LAMB_DRUMMER_button_H
#define LAMB_DRUMMER_button_H

#include "Arduino.h"

class Button {
  public:
    Button(
      uint8_t pin_,
      bool adc_state_ = true
    );
    virtual ~Button();
    bool read();
    void setup();
  private:
   uint8_t pin;
   bool adc_state;
};

#endif
