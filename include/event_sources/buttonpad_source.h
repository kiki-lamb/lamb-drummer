#ifndef SHELF_CLOCK_I_BUTTONPAD_SOURCE_H
#define SHELF_CLOCK_I_BUTTONPAD_SOURCE_H

#include <Arduino.h>
#include "polled_event_source.h"
#include "buttonpads/buttonpad.h"
#include "event/event.h"

template <class buttonpad_t_>
class ButtonpadSource : public buttonpad_t_, public PolledEventSource<ControlType>{
public:
  typedef buttonpad_t_ buttonpad_t;
  inline ButtonpadSource() : event(EVT_NOT_AVAILABLE) {}
  inline virtual ~ButtonpadSource() {}
private:
  static  ControlType                  buttonpad_ordering[8];
  event_t event;

  inline virtual void    impl_poll() {
    if (buttonpad_t::read())
      event = buttonpad_ordering[buttonpad_t_::button()];
  }

  inline virtual uint8_t impl_queue_count() const {
    return event == EVT_NOT_AVAILABLE ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    event_t e = event;
    event = EVT_NOT_AVAILABLE;
    return e;
  };
};

#endif
