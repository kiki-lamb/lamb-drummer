#ifndef SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H
#define SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H

#include <Arduino.h>
#include "controls/encoder_button.h"
#include "event_source.h"
#include "event/event.h"

class EncoderButtonSource : public EncoderButton, public EventSource<Event>{
public:
  EncoderButtonSource(
    event_t::event_type_t on_push_,
    uint8_t pin_,
    bool adc_state = true
  ) :
  EncoderButton(pin_, adc_state),
  on_push(on_push_),
  event_type(EVT_NOT_AVAILABLE) {}
  virtual ~EncoderButtonSource() {}
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
    return Event { e };
  };
};
#endif
