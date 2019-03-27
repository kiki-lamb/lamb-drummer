#ifndef SHELF_CLOCK_I_CONTROLS_H
#define SHELF_CLOCK_I_CONTROLS_H

#include "Arduino.h"

template<class event_t_>
class PolledEventSource {
public:
  typedef event_t_ event_t;

  PolledEventSource() {}

  virtual ~PolledEventSource() {}

  void setup() {
    impl_setup();
  }

  void poll() {
    impl_poll();
  }

  uint8_t queue_count() const {
    return impl_queue_count();
  }

  event_t dequeue_event(){
    return impl_dequeue_event();
  }

private:
  virtual void    impl_setup() = 0;
  virtual void    impl_poll() = 0;
  virtual uint8_t impl_queue_count() const = 0;
  virtual event_t impl_dequeue_event() = 0;
};

#endif
