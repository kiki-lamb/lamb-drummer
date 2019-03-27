#ifndef SHELF_CLOCK_ENCODER_H
#define SHELF_CLOCK_ENCODER_H

#include "Arduino.h"
#include <lambos.h>

class Encoder {
  private:
    Encoder();
    ~Encoder();

    static const    uint8_t                                                       encoderA = 2;
    static const    uint8_t                                                       encoderB = 3;
    static const    uint8_t                                                       ENC_SIG_BITS = 8;
    typedef         lamb::Encoders::States::UInt<ENC_SIG_BITS>                  enc_state_t;
    typedef         lamb::Encoders::Interfaces::NativePins<encoderA, encoderB>  enc_interface_t;
    typedef         lamb::Encoders::Custom<enc_state_t, enc_interface_t>        enc_t;
    static          enc_t                                                         encoder;
    
  public:
    static void setup();
    static void set_value(uint8_t value);
    static uint8_t value();
};

#endif
