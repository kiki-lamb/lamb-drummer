#ifndef SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H
#define SHELF_CLOCK_ENCODER_BUTTON_SOURCE_H

#include "Arduino.h"
#include "encoder_button.h"
#include "polled_event_source.h"

enum EncoderButtonEventType { EBE_ON, EBE_OFF, EBE_NOT_AVAILABLE };

struct EncoderButtonEvent {
  typedef EncoderButtonEventType event_type_t;
  event_type_t event_type;
};

class EncoderButtonSource : public EncoderButton, public PolledEventSource<EncoderButtonEvent>{
public:
  inline EncoderButtonSource(uint8_t pin_, bool adc_state = true) : EncoderButton(pin_, adc_state) {
    event.event_type = EncoderButtonEventType::EBE_NOT_AVAILABLE;
  }
  inline virtual ~EncoderButtonSource() {}
private:
  EncoderButtonEvent event;

  inline virtual void    impl_poll() {
    if (read())
      event.event_type = EncoderButtonEventType::EBE_ON;
  }

  inline virtual uint8_t impl_queue_count() const {
    return event.event_type == EncoderButtonEventType::EBE_NOT_AVAILABLE ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    event_t e = event;
    event.event_type = EncoderButtonEventType::EBE_NOT_AVAILABLE;
    return e;
  };
};
#endif
