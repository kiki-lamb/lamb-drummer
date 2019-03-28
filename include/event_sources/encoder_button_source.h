#ifndef SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H
#define SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H

#include <Arduino.h>
#include "controls/encoder_button.h"
#include "polled_event_source.h"
#include "event/event.h"

class EncoderButtonSource : public EncoderButton, public PolledEventSource<Event>{
public:
  inline EncoderButtonSource(uint8_t pin_, bool adc_state = true) : EncoderButton(pin_, adc_state), event_type(EVT_NOT_AVAILABLE) {}
  inline virtual ~EncoderButtonSource() {}
private:
  event_t::event_type_t event_type;

  inline virtual void    impl_poll() {
    if (read())
      event_type = EVT_PLAYBACK_STATE_TOGGLE;
  }

  inline virtual uint8_t impl_queue_count() const {
    return event_type == EVT_NOT_AVAILABLE ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    event_t::event_type_t e = event_type;
    event_type = EVT_NOT_AVAILABLE;
    return Event { e };
  };
};
#endif
