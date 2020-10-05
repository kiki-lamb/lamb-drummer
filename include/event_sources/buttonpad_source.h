#ifndef LAMB_DRUMMER_I_BUTTONPAD_SOURCE_H
#define LAMB_DRUMMER_I_BUTTONPAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"
#include "buttonpads/buttonpad.h"
#include "event/event.h"
#include "lamb.h"

template <class buttonpad_t_, size_t buffer_size = 8>
class ButtonpadSource : public buttonpad_t_, public EventSource<Event>{
public:
  typedef buttonpad_t_ buttonpad_t;
  
  ButtonpadSource() {}
  virtual ~ButtonpadSource() {}

private:
  static  event_t::event_type_t buttonpad_ordering[16];
  
  lamb::ring_buffer<event_t::event_type_t, buffer_size> queue;
  
  virtual void    impl_poll() {    
    while (queue.writable() && buttonpad_t::read()) {
      queue.enqueue(buttonpad_ordering[buttonpad_t_::button()]);
    }
  }

  virtual uint8_t impl_queue_count() const {
    return queue.count();
  }

  virtual event_t impl_dequeue_event() {
    return Event {
      queue.readable() ?
        queue.dequeue() :
        EVT_NOT_AVAILABLE
    };    
  };
};

#endif
