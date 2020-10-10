#ifndef LAMB_DRUMMER_XOX_TRACK_STATE_H
#define LAMB_DRUMMER_XOX_TRACK_STATE_H

#include "Arduino.h"
#include <lamb.h>

namespace tracks {
  class x0x {
    
  public:
    lamb::flag modified;

    static const uint8_t BAR_LENGTH  = 2; //bar_length_;
    static const uint8_t STEP_LENGTH = BAR_LENGTH << 4;
    static const uint8_t MOD_MASK    = STEP_LENGTH - 1;

  private:
    uint16_t bars[BAR_LENGTH];

  public:
    x0x();
    
    x0x & operator=(x0x const & other);
    
    static void position(uint8_t index, uint8_t & bar, uint8_t & step);
    
    bool trigger(uint8_t const & index) const;
    void set_trigger(uint8_t const & index);
    void unset_trigger(uint8_t const & index);    
    void flip_trigger(uint8_t const & index);
    void set_trigger(uint8_t const & bar, uint8_t const & step);
    void unset_trigger(uint8_t const & bar, uint8_t const & step);   
    void flip_trigger(uint8_t const & bar, uint8_t const & step);
  };
}

#endif
