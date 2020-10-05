#ifndef LAMB_DRUMMER_I_BUTTON_PAD_SOURCE_H
#define LAMB_DRUMMER_I_BUTTON_PAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"
#include "button_pads/button_pad.h"
#include "event/event.h"
#include "lamb.h"

template <class button_pad_t_, size_t buffer_size = 8>
class button_pad_source : public button_pad_t_, public event_source<event>{
public:
  typedef button_pad_t_ button_pad_t;
  
  button_pad_source() {}
  virtual ~button_pad_source() {}

private:
  static  event_t::event_type_t button_pad_ordering[16];
  
  lamb::ring_buffer<event_t::event_type_t, buffer_size> queue;
  
  virtual void    impl_poll() {    
    while (queue.writable() && button_pad_t::read()) {
      queue.enqueue(button_pad_ordering[button_pad_t_::button()]);
    }
  }

  virtual uint8_t impl_queue_count() const {
    return queue.count();
  }

  virtual event_t impl_dequeue_event() {
    return event {
      queue.readable() ?
        queue.dequeue() :
        EVT_NOT_AVAILABLE
    };    
  };
};

#endif
