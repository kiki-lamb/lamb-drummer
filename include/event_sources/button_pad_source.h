#ifndef LAMB_DRUMMER_BUTTON_PAD_SOURCE_H
#define LAMB_DRUMMER_BUTTON_PAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"
#include "button_pads/button_pad.h"
#include "event/event.h"
#include "lamb.h"

template <class button_pad_t_, size_t buffer_size = 8>
class button_pad_source : public event_source<event>{
public:
  typedef button_pad_t_ button_pad_type;

private:
  button_pad_type * _device;
  event_type      * _button_ordering;
  uint8_t           _button_ordering_size;
  
public:
  button_pad_source(
    button_pad_t_ * device_,
    event_type    * button_ordering_,
    uint8_t const & button_ordering_size_
  ) : 
    _device(device_),
    _button_ordering(button_ordering_),
    _button_ordering_size(button_ordering_size_) {}

  virtual ~button_pad_source() {}

private:
  lamb::ring_buffer<event_t::event_type_t, buffer_size> queue;

  virtual void    impl_poll() {
    // Serial.println("Poll...");
    
    if (! _device->read())
      return;
    
    uint16_t tmp_buttons = _device->buttons();
    uint16_t mask = 1;
    
    // Serial.print("Examine  ");
    // print_bits_16(tmp_buttons);
    // Serial.println();
    
    for (
      uint8_t ix = 0;
      ix < _button_ordering_size;
      ix++, mask <<= 1
    ) {
      if (mask & tmp_buttons) {
        // Serial.print("Enqueue ");
        // Serial.println(button_ordering[ix]);
        
        queue.enqueue(_button_ordering[ix]);
      }
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
