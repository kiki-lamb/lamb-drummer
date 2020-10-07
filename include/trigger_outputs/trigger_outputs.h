#ifndef LAMB_DRUMMER_TRIGGER_OUTPUTS_H
#define LAMB_DRUMMER_TRIGGER_OUTPUTS_H

#include <jm_PCF8574.h>
#include "lamb.h"

class trigger_outputs {
private:
  jm_PCF8574 * _device;
  lamb::flag _flag;
  uint16_t _values;
  
public:
  trigger_outputs();
  virtual ~trigger_outputs();
  bool setup(jm_PCF8574 * device_);
  void flag();
  // void xor_write(uint16_t values_, bool immediate = false);
  // void or_write(uint16_t values_, bool immediate = false);
  void write(uint16_t const & values_); // , bool immediate = false);
  void clear(); //bool immediate = false);
  bool update(); //bool immediate = false);
  uint16_t values() const;
};

#endif
