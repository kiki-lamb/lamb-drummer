#ifndef LAMB_DRUMMER_XOX_TRACK_STATE_H
#define LAMB_DRUMMER_XOX_TRACK_STATE_H

#include "Arduino.h"
#include <lamb.h>

namespace tracks {
  template <uint8_t length_>
  // length in 16-bit words bytes, not steps! One word per bar.
  class x0x {
  public:
    lamb::flag modified;

    static const uint8_t length = length_;

    uint16_t bars[length];
    
    x0x & operator=(x0x const & other) {
      for (uint8_t ix = 0; ix < length; ix++) {
        bars[ix] = other.bars[ix];
      }

      return *this;
    }

    bool trigger_state(uint8_t const & counter) const {
      return bars[0] & (1 << (counter % 16));
    }

    x0x() : bars() {
      for (uint8_t ix = 0; ix < length; ix++) {
        bars[ix] = 0;
      }
    }
  };
}

#endif
