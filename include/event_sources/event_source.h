#ifndef LAMB_DRUMMER_I_CONTROLS_H
#define LAMB_DRUMMER_I_CONTROLS_H

#include <Arduino.h>

// event_t must have default constructor, operator bool() returning false
// when no more event are availale. default must be false.

template<class event_t_>
class EventSource {
public:
  typedef event_t_ event_t;

  EventSource() {}

  virtual ~EventSource() {}

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

#endif
