#ifndef SHELF_CLOCK_ENCODER_SOURCE_H
#define SHELF_CLOCK_ENCODER_SOURCE_H

#include <Arduino.h>
#include "controls/encoder.h"
#include "polled_event_source.h"
#include "event/event.h"

class EncoderSource : public Encoder, public PolledEventSource<Event>{
public:
  EncoderSource(uint8_t bpm) : _bpm(bpm) {
    event.type = EVT_NOT_AVAILABLE;
    event.parameter = 0;
  }

  virtual ~EncoderSource() {}

  virtual void setup() {
    Encoder::setup();
    set_value(_bpm);
  }

private:
  event_t event;
  uint8_t _bpm;

  virtual void impl_poll() {
    uint8_t tmp_bpm = value();

    if (tmp_bpm != _bpm) {
      event.type = EVT_BPM_SET;
      event.parameter = tmp_bpm;
      _bpm = tmp_bpm;
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
