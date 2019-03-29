#ifndef LAMB_DRUMMER_EVENT_SOURCE_BUFFER_H
#define LAMB_DRUMMER_EVENT_SOURCE_BUFFER_H

#include <lamb.h>
#include "event_source.h"

template <class event_t, size_t queue_size_>
class BufferEventSource : public EventSource<event_t> {
public:
  BufferEventSource() {}
  virtual ~BufferEventSource() {}
  EventSource<event_t> * source;

private:
  lamb::RingBuffer<event_t, queue_size_> event_queue;

  virtual uint8_t impl_queue_count() const {
    return event_queue.count();
  }

  virtual void impl_poll() {
    if (source->poll()) {
      for (auto e = source->dequeue_event(); e; e = source->dequeue_event())
          event_queue.write(e);
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