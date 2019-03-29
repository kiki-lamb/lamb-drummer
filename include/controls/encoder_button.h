#ifndef LAMB_DRUMMER_ENCODER_BUTTON_H
#define LAMB_DRUMMER_ENCODER_BUTTON_H

#include "Arduino.h"

class EncoderButton {
  public:
    EncoderButton(
      uint8_t pin_,
      bool adc_state_ = true
    );
    virtual ~EncoderButton();
    bool read();
    void setup();
  private:
   uint8_t pin;
   bool adc_state;
};

#endif
