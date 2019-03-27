#ifndef SHELF_CLOCK_I_BUTTONPAD_SOURCE_H
#define SHELF_CLOCK_I_BUTTONPAD_SOURCE_H

#include "Arduino.h"
#include "polled_event_source.h"
#include "buttonpad.h"

template <class buttonpad_t_>
class ButtonpadSource : public buttonpad_t_, public PolledEventSource<uint8_t>{
public:
  typedef buttonpad_t_ buttonpad_t;
  inline ButtonpadSource() : event(8) {}
  inline virtual ~ButtonpadSource() {}
private:
  uint8_t event;
  inline virtual void    impl_poll() {
    if (buttonpad_t::read())
      event = buttonpad_t_::button();
  }

  inline virtual uint8_t impl_queue_count() const {
    return event == 0 ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    uint8_t e = event;
    event = 0;
    return e;
  };
};

#endif
