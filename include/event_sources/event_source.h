#ifndef LAMB_DRUMMER_EVENT_SOURCE_H
#define LAMB_DRUMMER_EVENT_SOURCE_H

#include <Arduino.h>

// event_t must have default constructor, operator bool() returning false
// when no more events are availale. default must be false.

namespace events {
  template<class event_t_>
  class event_source {
  public:
    typedef event_t_ event_t;

    event_source() {}

    /* virtual */ ~event_source() {}

    bool poll() {
      impl_poll();
    
      return ready();
    }

    bool ready() const {
      return !!queue_count();
    }

    uint8_t queue_count() const {
      return impl_queue_count();
    }

    event_t dequeue_event(){
      return impl_dequeue_event();
    }

  private:
    virtual void    impl_poll() = 0;
    virtual uint8_t impl_queue_count() const = 0;
    virtual event_t impl_dequeue_event() = 0;
  };
}

#endif
