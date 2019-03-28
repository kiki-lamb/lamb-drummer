#ifndef LAMB_DRUMMER_EVENT_SOURCE_COMBINE_H
#define LAMB_DRUMMER_EVENT_SOURCE_COMBINE_H

#include <lamb.h>
#include "polled_event_source.h"

template <class event_t, size_t count_>
class Combine : public PolledEventSource<event_t> {
public:
  Combine() {}
  virtual ~Combine() {}

private:
  PolledEventSource<event_t>   event_sources[size_t];
  lamb::RingBuffer<Event, 8>   event_queue;

  virtual uint8_t impl_queue_count() const {
    return event_queue.count();
  }

  virtual void impl_poll() {
    for (size_t ix = 0; ix < count_; ix++) {
      PolledEventSource<event_t> const & source;
      if (source.poll()) {
        while (source.ready()) {
          auto e = source.dequeue_event();
          if ( e.valid() )
          event_queue.write(e);
        }
      }
    }
  }

  virtual event_t impl_dequeue_event() {
    if (! event_queue.readable() ) {
      event_t e = { EVT_NOT_AVAILABLE};
      return e;
    }
    return event_queue.read();
  }
};

#endif
