#ifndef SHELF_CLOCK_CONTROLS_H
#define SHELF_CLOCK_CONTROLS_H

#include <lamb.h>
#include "controls/encoder.h"
#include "event/event.h"
#include "polled_event_source.h"
#include "encoder_button_source.h"
#include "buttonpad_source.h"

template <class buttonpad_t>
class ControlSource : public PolledEventSource<Event> {
public:
  ControlSource(uint8_t bpm) :
    _bpm(bpm),
    encoder_button_source(A7) {
    Encoder::setup();
    encoder_button_source.setup();
    buttonpad_source.setup();
    Encoder::set_value(_bpm);
  }

  virtual ~ControlSource() {}

private:
  typedef ButtonpadSource<buttonpad_t> buttonpad_source_t;
  typedef EncoderButtonSource          encoder_button_source_t;
  uint8_t                              _bpm;
  buttonpad_source_t                   buttonpad_source;
  EncoderButtonSource                  encoder_button_source;
  lamb::RingBuffer<Event, 8>           event_queue;

  virtual uint8_t impl_queue_count() const {
    return event_queue.count();
  }

  virtual void impl_poll() {
    uint8_t tmp_bpm = Encoder::value();

    if (tmp_bpm != _bpm) {
      queue_event(EVT_BPM_SET, tmp_bpm);
      _bpm = tmp_bpm;
    }

    encoder_button_source.poll();
    {
      auto e = encoder_button_source.dequeue_event();
      if ( e != EVT_NOT_AVAILABLE )
        queue_event(e);
    }

    buttonpad_source.poll();
    {
      auto e = buttonpad_source.dequeue_event();
      if ( e != EVT_NOT_AVAILABLE )
        queue_event(e);
    }
  }

  virtual event_t impl_dequeue_event() {
    if (! event_queue.readable() ) {
      Event e = { EVT_NOT_AVAILABLE};
      return e;
    }

    return event_queue.read();
  }

  void queue_event(EventType t, uint8_t param = 0) {
    if (! event_queue.writeable()) {
      Serial.println(F("Can't queue."));
      return;
    }

    Event e = { t, param };

    Serial.print(F("Queue "));
    Serial.print(e.type);
    Serial.println();

    event_queue.write(e);
  };
};

#endif
