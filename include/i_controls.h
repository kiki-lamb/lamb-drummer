#ifndef SHELF_CLOCK_I_CONTROLS_H
#define SHELF_CLOCK_I_CONTROLS_H

#include "Arduino.h"

template<class event_t_>
class IControls {
public:
  typedef event_t_ event_t;
  IControls() {}

  virtual ~IControls() {}

  void setup() {
    impl_setup();
  }

  uint8_t queue_count() const {
    return impl_queue_count();
  }

  event_t dequeue_event(){
    return impl_dequeue_event();
  }

  void set_encoder(uint8_t val) { // try to get rid of this
    impl_set_encoder(val);
  }

  void poll() {
    impl_poll();
  }

private:
  virtual void         impl_setup() = 0;
  virtual uint8_t      impl_queue_count() const = 0;
  virtual event_t impl_dequeue_event() = 0;
  virtual void         impl_set_encoder(uint8_t val) = 0; // try to get rid of this
  virtual void         impl_poll() = 0;
};

#endif
