#ifndef SHELF_CLOCK_ENCODER_SOURCE_H
#define SHELF_CLOCK_ENCODER_SOURCE_H

#include <Arduino.h>
#include "controls/encoder.h"
#include "polled_event_source.h"
#include "event/event.h"

class EncoderSource : public Encoder, public PolledEventSource<Event>{
public:
  inline EncoderSource(uint8_t bpm) : _bpm(bpm) {
    event.type = EVT_NOT_AVAILABLE;
    event.parameter = 0;
  }

  inline virtual ~EncoderSource() {}

  inline virtual void setup() {
    Encoder::setup();
    set_value(_bpm);
  }

private:
  event_t event;
  uint8_t _bpm;

  inline virtual void impl_poll() {
    uint8_t tmp_bpm = value();

    if (tmp_bpm != _bpm) {
      event.type = EVT_BPM_SET;
      event.parameter = tmp_bpm;
      _bpm = tmp_bpm;
    }
  }

  inline virtual uint8_t impl_queue_count() const {
    return event.type == EVT_NOT_AVAILABLE ? 0 : 1;
  }

  inline virtual event_t impl_dequeue_event() {
    event_t e = event;
    event.type = EVT_NOT_AVAILABLE;
    event.parameter = 0;
    return e;
  };
};
#endif
