#ifndef SHELF_CLOCK_ENCODER_BUTTON_H
#define SHELF_CLOCK_ENCODER_BUTTON_H

#include "Arduino.h"
#include "polled_event_source.h"

class EncoderButton {
  public:
    EncoderButton(
      uint8_t pin_,
      bool adc_state_ = true
    );
    virtual ~EncoderButton();
    bool read();
    void setup();
  private:
   uint8_t pin;
   bool adc_state;
};

enum EncoderButtonEventType { EBET_ON, EBET_OFF, EBET_NOT_AVAILABLE };

struct EncoderButtonEvent {
  typedef EncoderButtonEventType event_type_t;
  event_type_t event_type;
};

class EncoderButtonSource : public EncoderButton, public PolledEventSource<EncoderButtonEvent>{
public:
  inline EncoderButtonSource(uint8_t pin_, bool adc_state = true) : EncoderButton(pin_, adc_state) {}
  inline virtual ~EncoderButtonSource() {
    event.event_type = EncoderButtonEventType::EBET_NOT_AVAILABLE;
  }
private:
  EncoderButtonEvent event;

  inline virtual void    impl_poll() {
    if (read())
      event.event_type = EncoderButtonEventType::EBET_ON;
  }

  inline virtual uint8_t impl_queue_count() const {
    return event.event_type == EncoderButtonEventType::EBET_NOT_AVAILABLE ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    event_t e = event;
    e.event_type = EncoderButtonEventType::EBET_NOT_AVAILABLE;
    return event;
  };
};
#endif
