#ifndef LAMB_DRUMMER_EVENT_SOURCE_BUFFER_H
#define LAMB_DRUMMER_EVENT_SOURCE_BUFFER_H

#include <lamb.h>
#include "source.h"

namespace events {
  namespace sources {
    template <class event_type, size_t queue_size_>
    class buffer : public source<event_type> {
    public:
      events::sources::source<event_type> * source;

      buffer() : source(NULL) {}

      /* virtual */ ~buffer() {}

    private:
      declare_light_buffer(event_type, queue_size_, event_queue);

      virtual uint8_t impl_queue_count() const {
        return event_queue_count;
      }

      virtual void impl_poll() {
        if (! source->poll())
          return;
    
        // for (auto e = source->dequeue_event(); e; e = source->dequeue_event()) {
        while (event_type e = source->dequeue_event())
          light_buffer_write(event_queue, e);
      }

      virtual event_type impl_dequeue_event() {
        if (! light_buffer_readable(event_queue) ) {
          return event_type();
        }

        return light_buffer_read(event_queue);
      }
    };
  }
}

#endif
