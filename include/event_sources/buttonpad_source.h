#ifndef LAMB_DRUMMER_I_BUTTONPAD_SOURCE_H
#define LAMB_DRUMMER_I_BUTTONPAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"
#include "buttonpads/buttonpad.h"
#include "event/event.h"

template <class buttonpad_t_>
class ButtonpadSource : public buttonpad_t_, public EventSource<Event>{
public:
  typedef buttonpad_t_ buttonpad_t;
  ButtonpadSource() : event_type(EVT_NOT_AVAILABLE) {}
  virtual ~ButtonpadSource() {}

private:
  static  event_t::event_type_t buttonpad_ordering[16];

  event_t::event_type_t event_type;

  virtual void    impl_poll() {    
    if (! buttonpad_t::read())
      return;
    
    event_type = buttonpad_ordering[buttonpad_t_::button()];
  }

  virtual uint8_t impl_queue_count() const {
    return event_type == EVT_NOT_AVAILABLE ? 0 : 1;
  }

  virtual event_t impl_dequeue_event() {
    event_t::event_type_t et = event_type;

    event_type = EVT_NOT_AVAILABLE;

    return Event { et };
  };
};

#endif
