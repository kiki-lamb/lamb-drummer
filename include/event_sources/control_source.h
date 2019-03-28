#ifndef SHELF_CLOCK_CONTROLS_H
#define SHELF_CLOCK_CONTROLS_H

#include <lamb.h>
#include "controls/encoder.h"
#include "event/event.h"
#include "polled_event_source.h"
#include "encoder_source.h"
#include "encoder_button_source.h"
#include "buttonpad_source.h"

template <class buttonpad_t>
class ControlSource : public PolledEventSource<Event> {
public:
  ControlSource(uint8_t bpm) :
    encoder_button_source(A7),
    encoder_source(bpm)
  {
    encoder_source.setup();
    encoder_button_source.setup();
    buttonpad_source.setup();
  }

  virtual ~ControlSource() {}

private:
  typedef ButtonpadSource<buttonpad_t> buttonpad_source_t;
  typedef EncoderButtonSource          encoder_button_source_t;
  typedef EncoderSource                encoder_source_t;

  buttonpad_source_t                   buttonpad_source;
  encoder_button_source_t              encoder_button_source;
  encoder_source_t                     encoder_source;

  lamb::RingBuffer<Event, 8>           event_queue;

  virtual uint8_t impl_queue_count() const {
    return event_queue.count();
  }

  template <typename child_t>
  void poll_child_and_queue_events(child_t & child) {
    child.poll();
    auto e = child.dequeue_event();
    if ( e.type != EVT_NOT_AVAILABLE )
      queue_event(e);
  }

  virtual void impl_poll() {
    poll_child_and_queue_events( encoder_source );
    poll_child_and_queue_events( encoder_button_source );
    poll_child_and_queue_events( buttonpad_source );
  }

  virtual event_t impl_dequeue_event() {
    if (! event_queue.readable() ) {
      event_t e = { EVT_NOT_AVAILABLE};
      return e;
    }

    return event_queue.read();
  }

  void queue_event(event_t e) {
    event_queue.write(e);
  }

  void queue_event(event_t::event_type_t t, uint8_t param = 0) {
    if (! event_queue.writeable()) {
      Serial.println(F("Can't queue."));
      return;
    }

    event_t e = { t, param };

    Serial.print(F("Queue "));
    Serial.print(e.type);
    Serial.println();
    queue_event(e);
  };
};

#endif
