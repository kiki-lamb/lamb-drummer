#ifndef LAMB_DRUMMER_XOX_TRACK_STATE_H
#define LAMB_DRUMMER_XOX_TRACK_STATE_H

#include "Arduino.h"
#include <lamb.h>

namespace tracks {
  template <uint8_t bar_length_>
  class x0x {
    
  public:
    lamb::flag modified;

    static const uint8_t BAR_LENGTH  = bar_length_;
    static const uint8_t STEP_LENGTH = bar_length_ << 4;
    static const uint8_t MOD_MASK    = STEP_LENGTH - 1;

  private:
    uint16_t bars[BAR_LENGTH];

  public:
    x0x() : bars() {}
    
    x0x & operator=(x0x const & other) {
      for (uint8_t ix = 0; ix < BAR_LENGTH; ix++) {
        bars[ix] = other.bars[ix];
      }

      return *this;
    }

    static void position(uint8_t index, uint8_t & bar, uint8_t & step) {
      index  &= MOD_MASK;
      step    = index & 0xf;      
      bar     = index >> 4;
    }

#define GET_POSITIONS(index) \
    uint8_t bar, step; \
    position(index, bar, step)
   
    bool trigger(uint8_t const & index) const {
      GET_POSITIONS(index);

      return bars[bar] & (1 << step);
    }

    void set_trigger(uint8_t const & index) {
      GET_POSITIONS(index);
      
      set_trigger(bar, step);
    }                

    void unset_trigger(uint8_t const & index) {
      GET_POSITIONS(index);
      
      set_trigger(bar, step);
    }
    
    void flip_trigger(uint8_t const & index) {
      GET_POSITIONS(index);
      
      set_trigger(bar, step);
    }                

#undef GET_POSITIONS
    
    void set_trigger(uint8_t const & bar, uint8_t const & step) {
      bars[bar] |= (1 << step);
    };

    void unset_trigger(uint8_t const & bar, uint8_t const & step) {
      bars[bar] &= ~(1 << step);
    };
    
    void flip_trigger(uint8_t const & bar, uint8_t const & step) {
      bars[bar] ^= (1 << step);
    };
  };
}

#endif
