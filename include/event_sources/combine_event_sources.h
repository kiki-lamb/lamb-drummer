#ifndef LAMB_DRUMMER_EVENT_SOURCE_COMBINE_H
#define LAMB_DRUMMER_EVENT_SOURCE_COMBINE_H

#include <lamb.h>
#include "event_source.h"

// event_t must have default constructor, operator bool() returning false
// when no more event are availale. default must be false.

template <class event_t, size_t count_>
class CombineEventSources : public EventSource<event_t> {
public:
  CombineEventSources() {}
  virtual ~CombineEventSources() {}
  EventSource<event_t> * sources[count_];

private:
  lamb::RingBuffer<event_t, 8>   event_queue;

  virtual uint8_t impl_queue_count() const {
    return event_queue.count();
  }

  virtual void impl_poll() {
    for (size_t ix = 0; ix < count_; ix++) {
      EventSource<event_t> & source = *(sources[ix]);
      if (source.poll()) {
        for (auto e = source.dequeue_event(); e; e = source.dequeue_event())
            event_queue.write(e);
      }
    }
  }

  virtual event_t impl_dequeue_event() {
    if (! event_queue.readable() ) {
      return event_t();
    }
    return event_queue.read();
  }
};

#endif
