#ifndef LAMB_DRUMMER_TRIGGER_OUTPUTS_H
#define LAMB_DRUMMER_TRIGGER_OUTPUTS_H

#include <jm_PCF8574.h>
#include "lamb.h"

namespace outputs {
  class triggers {
  private:
    jm_PCF8574 * _device;
    lamb::flag _flag;
    uint16_t _values;
  
  public:
    bool setup(jm_PCF8574 * device_);
    void flag();
    void write(uint16_t const & values_);
    void clear();
    bool update();
    uint16_t values() const;
  };
}
#endif
