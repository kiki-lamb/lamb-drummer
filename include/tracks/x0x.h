#ifndef LAMB_DRUMMER_XOX_TRACK_STATE_H
#define LAMB_DRUMMER_XOX_TRACK_STATE_H

#include "Arduino.h"
#include <lamb.h>

namespace tracks {
  template <uint8_t _word_length_>
  // _word_length in 16-bit words bytes, not steps! One word per bar.
  class x0x {
  public:
    lamb::flag modified;

    static const uint8_t _word_length = _word_length_;

    uint16_t bars[_word_length];
    
    x0x & operator=(x0x const & other) {
      for (uint8_t ix = 0; ix < _word_length; ix++) {
        bars[ix] = other.bars[ix];
      }

      return *this;
    }

    static uint8_t length() {
      return _word_length << 4;
    }
    
    bool trigger_state(uint8_t const & counter) const {
      Serial.print("Look up step ");
      Serial.print(counter);
      
      uint8_t bar  = counter >> 4;
      uint8_t step = counter % 16;

      bar %= _word_length;
      
      Serial.print(" => ");
      Serial.print(bar);
      Serial.print(":");
      Serial.println(step);

      return bars[bar] & (1 << (step % 16));
    }

    x0x() : bars() {
      for (uint8_t ix = 0; ix < _word_length; ix++) {
        bars[ix] = 0;
      }
    }
  };
}

#endif
