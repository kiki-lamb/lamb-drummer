#ifndef LAMB_DRUMMER_EVENT_BASE_H
#define LAMB_DRUMMER_EVENT_BASE_H

#include <inttypes.h>

namespace events {
  class event {
  public:
    uint16_t parameter;

    inline event(uint16_t parameter_) : parameter(parameter_) {}
    
    inline uint8_t parameter_hi() const {
      return parameter >> 8;
    }

    inline uint8_t parameter_lo() const {
      return parameter & 0xf;
    }
  };
}

#endif
