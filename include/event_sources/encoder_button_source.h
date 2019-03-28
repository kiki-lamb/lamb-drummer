#ifndef SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H
#define SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H

#include <Arduino.h>
#include "../controls/encoder_button.h"
#include "polled_event_source.h"

class EncoderButtonSource : public EncoderButton, public PolledEventSource<bool>{
public:
  inline EncoderButtonSource(uint8_t pin_, bool adc_state = true) : EncoderButton(pin_, adc_state), event(false) {}
  inline virtual ~EncoderButtonSource() {}
private:
  bool event;

  inline virtual void    impl_poll() {
    if (read())
      event = true;
  }

  inline virtual uint8_t impl_queue_count() const {
    return event ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    if (event) {
      event = false;
      return true;
    }

    return false;
  };
};
#endif
