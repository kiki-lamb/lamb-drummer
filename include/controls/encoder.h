#ifndef LAMB_DRUMMER_ENCODER_H
#define LAMB_DRUMMER_ENCODER_H

#include "Arduino.h"
#include <lamb.h>

class encoder {
  private:
    static const    uint8_t                                                     encoderA = 2;
    static const    uint8_t                                                     encoderB = 3;
    static const    uint8_t                                                     ENC_SIG_BITS = 8;
    typedef         lamb::encoders::states::uint<ENC_SIG_BITS>                  enc_state_t;
    typedef         lamb::encoders::interfaces::native_pins<encoderA, encoderB>  enc_interface_t;
    typedef         lamb::encoders::custom<enc_state_t, enc_interface_t>        enc_t;
    static enc_t                                                                _encoder;
  public:
    encoder();
    virtual      ~encoder();
    virtual void setup();
    void         set_value(uint8_t value);
    uint8_t      value();
};

#endif
