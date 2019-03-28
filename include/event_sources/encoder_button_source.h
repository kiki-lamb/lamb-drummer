#ifndef SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H
#define SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H

#include <Arduino.h>
#include "controls/encoder_button.h"
#include "polled_event_source.h"
#include "event/event.h"

class EncoderButtonSource : public EncoderButton, public PolledEventSource<EventType>{
public:
  inline EncoderButtonSource(uint8_t pin_, bool adc_state = true) : EncoderButton(pin_, adc_state), event(EVT_NOT_AVAILABLE) {}
  inline virtual ~EncoderButtonSource() {}
private:
  event_t event;

  inline virtual void    impl_poll() {
    if (read())
      event = EVT_PLAYBACK_STATE_TOGGLE;
  }

  inline virtual uint8_t impl_queue_count() const {
    return event == EVT_NOT_AVAILABLE ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    EventType e = event;
    event = EVT_NOT_AVAILABLE;
    return e;
  };
};
#endif
