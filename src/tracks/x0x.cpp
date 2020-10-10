#include "tracks/x0x.h"

tracks::x0x::x0x(uint8_t bars_count_) :
  _bars_count(0),
  _steps_count(0),
  _mod_mask(0),
  _bars(NULL)
{
  allocate(bars_count_);
}

void tracks::x0x::allocate(uint8_t bars_count_) {
  _bars_count  = bars_count_;
  _steps_count = _bars_count << 4;
  _mod_mask    = _steps_count - 1;

  _bars = static_cast<uint16_t *>(
    calloc(
      _bars_count,
      sizeof(uint16_t)
    )
  );
}

void tracks::x0x::clear() {
  clear(_bars_count);
}

void tracks::x0x::clear(uint8_t const & new_size) {
  free(_bars);
  
  allocate(new_size);
};

tracks::x0x & tracks::x0x::operator=(tracks::x0x const & other) {
  clear(other._bars_count);
  
  for (uint8_t ix = 0; ix < _bars_count; ix++) {
    _bars[ix] = other._bars[ix];
  }
  
  return *this;
}

void tracks::x0x::position(uint8_t index, uint8_t & bar, uint8_t & step) const {
  index  &= _mod_mask;
  step    = index & 0xf;      
  bar     = index >> 4;
}

#define GET_POSITIONS(index)                    \
  uint8_t bar, step;                            \
  position(index, bar, step)

bool tracks::x0x::trigger(uint8_t const & index) const {
  GET_POSITIONS(index);
  
  return _bars[bar] & (1 << step);
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
  _bars[bar] |= (1 << step);
};

void tracks::x0x::unset_trigger(uint8_t const & bar, uint8_t const & step) {
  _bars[bar] &= ~(1 << step);
};

void tracks::x0x::flip_trigger(uint8_t const & bar, uint8_t const & step) {
  _bars[bar] ^= (1 << step);
};
