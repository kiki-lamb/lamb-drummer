#ifndef SHELF_CLOCK_CONTROLS_H
#define SHELF_CLOCK_CONTROLS_H

#include <lamb.h>
#include "buttonpad.h"
#include "encoder_button.h"
#include "encoder.h"
#include "polled_event_source.h"

enum ControlEventType {
  EVT_MIN_UP,
  EVT_MIN_DN,
  EVT_MAJ_UP,
  EVT_MAJ_DN,
  EVT_PHASE_MIN_UP,
  EVT_PHASE_MIN_DN,
  EVT_PHASE_MAJ_UP,
  EVT_PHASE_MAJ_DN,
  EVT_SELECTED_TRACK_UP,
  EVT_SELECTED_TRACK_DN,
  EVT_BPM_SET,
  EVT_PLAYBACK_STATE_TOGGLE,
  EVT_NOT_AVAILABLE
};

struct ControlEvent {
  typedef ControlEventType event_type_t;
  ControlEventType type;
  uint8_t parameter;
};

template <class buttonpad_t>
class ControlEventSource : public PolledEventSource<ControlEvent> {
public:
  ControlEventSource(uint8_t bpm) :
    _bpm(bpm),
    button_pad(new buttonpad_t()),
    encoder_button(A7) {
    Encoder::setup();
    encoder_button.setup();
    button_pad->setup();
    Encoder::set_value(_bpm);
  }

  virtual ~ControlEventSource() {}

private:
  uint8_t _bpm;
  Buttonpad * button_pad;
  EncoderButton encoder_button;
  static  ControlEventType buttonpad_ordering[8];
  lamb::RingBuffer<ControlEvent, 8> event_queue;

  Buttonpad::Button buttonpad_button() const {
    return (Buttonpad::Button)(button_pad->buttonpad_button());
  }

  virtual uint8_t impl_queue_count() const {
    return event_queue.count();
  }

  virtual void impl_poll() {
    uint8_t tmp_bpm = Encoder::value();

    if (tmp_bpm != _bpm) {
      queue_event(EVT_BPM_SET, tmp_bpm);
      _bpm = tmp_bpm;
    }

    if ( encoder_button.read() )
      queue_event( EVT_PLAYBACK_STATE_TOGGLE);

    if ( button_pad->read() )
      queue_event( (event_t::event_type_t)(buttonpad_ordering[buttonpad_button()]) );
  }

  virtual ControlEvent impl_dequeue_event() {
    if (! event_queue.readable() ) {
      ControlEvent e = { EVT_NOT_AVAILABLE};
      return e;
    }

    return event_queue.read();
  }

  void queue_event(ControlEventType t, uint8_t param = 0) {
    if (! event_queue.writeable()) {
      Serial.println(F("Can't queue."));
      return;
    }

    ControlEvent e = { t, param };

    Serial.print(F("Queue "));
    Serial.print(e.type);
    Serial.println();

    event_queue.write(e);
  };
};

#endif
