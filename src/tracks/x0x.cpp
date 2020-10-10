#include "tracks/x0x.h"

tracks::x0x::x0x() : bars() {}
    
tracks::x0x & tracks::x0x::operator=(tracks::x0x const & other) {
  for (uint8_t ix = 0; ix < BAR_LENGTH; ix++) {
    bars[ix] = other.bars[ix];
  }
  
  return *this;
}

void tracks::x0x::position(uint8_t index, uint8_t & bar, uint8_t & step) {
  index  &= MOD_MASK;
  step    = index & 0xf;      
  bar     = index >> 4;
}

#define GET_POSITIONS(index)                    \
  uint8_t bar, step;                            \
  position(index, bar, step)

bool tracks::x0x::trigger(uint8_t const & index) const {
  GET_POSITIONS(index);
  
  return bars[bar] & (1 << step);
}

void tracks::x0x::set_trigger(uint8_t const & index) {
  GET_POSITIONS(index);
  
  set_trigger(bar, step);
}                

void tracks::x0x::unset_trigger(uint8_t const & index) {
  GET_POSITIONS(index);
  
  unset_trigger(bar, step);
}

void tracks::x0x::flip_trigger(uint8_t const & index) {
  GET_POSITIONS(index);
  
  flip_trigger(bar, step);
}                

#undef GET_POSITIONS
    
void tracks::x0x::set_trigger(uint8_t const & bar, uint8_t const & step) {
  bars[bar] |= (1 << step);
};

void tracks::x0x::unset_trigger(uint8_t const & bar, uint8_t const & step) {
  bars[bar] &= ~(1 << step);
};

void tracks::x0x::flip_trigger(uint8_t const & bar, uint8_t const & step) {
  bars[bar] ^= (1 << step);
};
