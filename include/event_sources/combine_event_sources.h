#ifndef LAMB_DRUMMER_EVENT_SOURCE_COMBINE_H
#define LAMB_DRUMMER_EVENT_SOURCE_COMBINE_H

#include "event_source.h"

namespace events {
  namespace sources {
    template <class event_type, size_t sources_count_>
    class combine : public source<event_type> {
    public:
      source<event_type> * sources[sources_count_];

      combine() : sources() {}
      /* virtual */ ~combine() {}

    private:
      virtual uint8_t impl_queue_count() const {
        size_t tmp = 0;
        for (size_t ix = 0; ix < sources_count_; ix++)
          tmp += sources[ix]->queue_count();
        return tmp;
      }

      virtual void impl_poll() {
        for (size_t ix = 0; ix < sources_count_; ix++) {
//      Serial.print("Poll combined source ");
//      Serial.println(ix);
//      Serial.flush();
      
          sources[ix]->poll();
        }
      }

      virtual event_type impl_dequeue_event() {
        for (size_t ix = 0; ix < sources_count_; ix++) {
          if (sources[ix]->ready()) {
            return sources[ix]->dequeue_event();
          }
        }

        return event_type();
      }
    };
  }
}

#endif
