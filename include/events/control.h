#ifndef LAMB_DRUMMER_CONTROL_EVENT_H
#define LAMB_DRUMMER_CONTROL_EVENT_H

#include <Arduino.h>
#include "events/event.h"

namespace events {
  enum control_event_type {
    CTL_EVT_NOT_AVAILABLE = 0,       
    EVT_ENCODER       = 1,
    EVT_BUTTON        = 2,
  };

  class control :
    public event<control_event_type> {
  public:
    control(
      event_type type_ = event_type::CTL_EVT_NOT_AVAILABLE,
      uint16_t arg = 0
    ) :
      event(type_, arg) {}
  };
}

#endif
