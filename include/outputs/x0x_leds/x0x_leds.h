#ifndef LAMB_DRUMMER_X0X_LEDS_H
#define LAMB_DRUMMER_X0X_LEDS_H

#include <Adafruit_MCP23017.h>
#include "lamb.h"

class x0x_leds {
private:
  Adafruit_MCP23017 * _device;
  lamb::flag _flag;
  uint16_t _values;
  
public:
  x0x_leds();
//  /* virtual */ ~x0x_leds();
  bool setup(Adafruit_MCP23017 * device_);
  void flag();
  void xor_write(uint16_t const & values_, bool const & immediate = false);
  void or_write(uint16_t const & values_, bool const & immediate = false);
  void write(uint16_t const & values_, bool const & immediate = false);
  void clear(bool const & immediate = false);
  bool update(bool const & immediate = false);
  uint16_t values() const;
};

#endif
