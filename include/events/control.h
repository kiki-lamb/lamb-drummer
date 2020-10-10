#ifndef LAMB_DRUMMER_CONTROL_EVENT_H
#define LAMB_DRUMMER_CONTROL_EVENT_H

#include <Arduino.h>
#include "events/application.h"
#include "events/event.h"

namespace events {
  class control: public event {
  public:
    enum event_type {
      EVT_NOT_AVAILABLE = 0,       
      EVT_ENCODER       = 1,
      EVT_BUTTON        = 2,
    };

    event_type type;
   
    control(event_type type_ = event_type::EVT_NOT_AVAILABLE, uint16_t arg = 0) :
      event(arg), type(type_) {}

    inline operator bool() const {
      return type != event_type::EVT_NOT_AVAILABLE;
    }

  };
}

#endif
