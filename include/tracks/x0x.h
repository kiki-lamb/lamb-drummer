#ifndef LAMB_DRUMMER_XOX_TRACK_STATE_H
#define LAMB_DRUMMER_XOX_TRACK_STATE_H

#include "Arduino.h"
#include <lamb.h>

namespace tracks {
  class x0x {
    
  public:
    lamb::flag modified;

  protected:
    uint8_t    _bars_count; //  = 2; //bars_count_;
    uint8_t    _steps_count; //= BARS_COUNT << 4;
    uint8_t    _mod_mask; //    = STEPS_COUNT - 1;
    uint16_t * _bars;

  public:
    x0x(uint8_t bars_count_ = 1);

    uint8_t bars_count() const;

    uint16_t bar(uint8_t bar_) const;
    
    void set_bar(uint8_t bar_, uint16_t data_);
    
    void clear(uint8_t bars_count_ = 0);
    
    x0x & operator=(x0x const & other);
    
    void position(uint8_t index, uint8_t & bar, uint8_t & step) const;
    
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
