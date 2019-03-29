#ifndef LAMB_DRUMMER_ENCODER_SOURCE_H
#define LAMB_DRUMMER_ENCODER_SOURCE_H

#include <Arduino.h>
#include "controls/encoder.h"
#include "event_source.h"
#include "event/event.h"

class EncoderSource : public Encoder, public EventSource<Event>{
public:
  EncoderSource(
    event_t::event_type_t on_change_,
    uint8_t initial_value = 0
  ) :
    on_change(on_change_),
    _initial_value(initial_value)
  {
    event.type = EVT_NOT_AVAILABLE;
    event.parameter = 0;
  }

  virtual ~EncoderSource() {}

  virtual void setup() {
    Encoder::setup();
    set_value(_initial_value);
  }

private:
  event_t event;
  event_t::event_type_t on_change;
  uint8_t _initial_value;

  virtual void impl_poll() {
    uint8_t tmp_value = value();

    if (tmp_value != _initial_value) {
      event.type = on_change;
      event.parameter = tmp_value;
      _initial_value = tmp_value;
    }
  }

  virtual uint8_t impl_queue_count() const {
    return event.type == EVT_NOT_AVAILABLE ? 0 : 1;
  }

  virtual event_t impl_dequeue_event() {
    event_t e = event;
    event.type = EVT_NOT_AVAILABLE;
    event.parameter = 0;
    return e;
  };
};
#endif
