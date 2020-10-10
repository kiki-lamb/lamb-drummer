#ifndef LAMB_DRUMMER_EVENT_BASE_H
#define LAMB_DRUMMER_EVENT_BASE_H

#include <inttypes.h>

namespace events {
  template <typename event_t_>
    class event {
  public:
    typedef event_t_ event_type;   
    
    event_type type;
    uint16_t parameter;

    inline event(
      event_type type_ = ((event_type)0),
      uint16_t parameter_ = 0
    ) :
      type(type_),
      parameter(parameter_) {}
    
    inline uint8_t parameter_hi() const {
      return parameter >> 8;
    }

    inline uint8_t parameter_lo() const {
      return parameter & 0xf;
    }

    inline operator bool() const {
      return type != ((event_type)0);
    }
  };
}

#endif
