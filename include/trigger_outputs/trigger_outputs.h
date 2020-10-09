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
//  ~trigger_outputs();
  bool setup(jm_PCF8574 * device_);
  void flag();
  void write(uint16_t const & values_);
  void clear();
  bool update();
  uint16_t values() const;
};

#endif
