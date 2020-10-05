#ifndef LAMB_DRUMMER_button_SOURCE_H
#define LAMB_DRUMMER_button_SOURCE_H

#include <Arduino.h>
#include "controls/button.h"
#include "event_source.h"
#include "event/event.h"

class ButtonSource : public Button, public EventSource<event>{
public:
  ButtonSource(
    event_t::event_type_t on_push_,
    uint8_t pin_,
    bool adc_state = true
  ) :
  Button(pin_, adc_state),
  on_push(on_push_),
  event_type(EVT_NOT_AVAILABLE) {}
  virtual ~ButtonSource() {}
private:
  event_t::event_type_t on_push;
  event_t::event_type_t event_type;

  virtual void    impl_poll() {
    if (read())
      event_type = on_push;
  }

  virtual uint8_t impl_queue_count() const {
    return event_type == EVT_NOT_AVAILABLE ? 0 : 1;
  }

  virtual event_t impl_dequeue_event() {
    event_t::event_type_t e = event_type;
    event_type = EVT_NOT_AVAILABLE;
    return event { e };
    
  };
};
#endif
