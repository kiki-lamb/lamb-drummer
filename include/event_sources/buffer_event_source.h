#ifndef LAMB_DRUMMER_EVENT_SOURCE_BUFFER_H
#define LAMB_DRUMMER_EVENT_SOURCE_BUFFER_H

#include <lamb.h>
#include "event_source.h"

template <class event_t, size_t queue_size_>
class buffer_event_source : public event_source<event_t> {
public:
  event_source<event_t> * source;
  buffer_event_source() : source(NULL) {}
  virtual ~buffer_event_source() {}

private:
  lamb::ring_buffer<event_t, queue_size_> event_queue;

  virtual uint8_t impl_queue_count() const {
    return event_queue.count();
  }

  virtual void impl_poll() {
    if (! source->poll())
      return;
    
    for (auto e = source->dequeue_event(); e; e = source->dequeue_event()) {
      event_queue.enqueue(e);
    }
  }

  virtual event_t impl_dequeue_event() {
    if (! event_queue.readable() ) {
      return event_t();
    }

    return event_queue.dequeue();
  }
};

#endif
