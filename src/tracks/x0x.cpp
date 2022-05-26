#include "tracks/x0x.h"

tracks::x0x::x0x(uint8_t bars_count_) :
  _bars_count(0),
  _steps_count(0),
  _mod_mask(0),
  _bars(NULL)
{
  clear(bars_count_);
}

void tracks::x0x::clear(uint8_t new_size) {
  if (new_size == bars_count())
    return;
  else if (new_size > 4) {
    Serial.print(F("Refusing to resize to "));
    Serial.print(new_size);
    Serial.print(F(" bars. Using 2 instead."));
    Serial.println();

    new_size = 4;
  }

  if (bars_count() != 0) {
    modified.set();
  }
  
  free(_bars);
  
  _bars_count  = new_size;
  _steps_count = bars_count() << 4;
  _mod_mask    = _steps_count - 1;

  _bars = static_cast<uint16_t *>(
    calloc(
      bars_count(),
      sizeof(uint16_t)
    )
  );
};

tracks::x0x & tracks::x0x::operator=(tracks::x0x const & other) {
  clear(other.bars_count());
  
  for (uint8_t ix = 0; ix < bars_count(); ix++) {
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
  uint16_t tmp = (1 << step);

  if (! (_bars[bar] & tmp)) {
    _bars[bar] |= tmp;

    modified.set();
  }
};

void tracks::x0x::unset_trigger(uint8_t const & bar, uint8_t const & step) {
  uint16_t tmp = (1 << step);

  if (_bars[bar] & tmp) {    
    _bars[bar] &= ~tmp;

    modified.set();
  }
};

void tracks::x0x::flip_trigger(uint8_t const & bar, uint8_t const & step) {
  _bars[bar] ^= (1 << step);
  
  modified.set();  
};

uint8_t tracks::x0x::bars_count() const {
  return _bars_count;
}

uint16_t tracks::x0x::bar(uint8_t bar_) const {
  bar_ %= bars_count();

  return _bars[bar_];
}

void tracks::x0x::set_bar(uint8_t bar_, uint16_t data_) {
  bar_ %= bars_count();

  if (_bars[bar_] != data_) {
    _bars[bar_] = data_;
    
    modified.set();
  }
}
