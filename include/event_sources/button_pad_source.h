#ifndef LAMB_DRUMMER_BUTTON_PAD_SOURCE_H
#define LAMB_DRUMMER_BUTTON_PAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"
#include "event/event.h"
#include "lamb.h"

template <class button_pad_t_, size_t buffer_size = 8>
class button_pad_source : public event_source<event>{
public:
  typedef button_pad_t_ button_pad_type;

private:
  button_pad_type  * _device;
  event_type const * _button_ordering;
  uint8_t            _button_ordering_size;

  event_t::event_type_t queue[buffer_size];
  uint8_t               queue_write_ix;
  uint8_t               queue_read_ix;
  uint8_t               queue_count;
  uint8_t               queue_length;       
  
public:
  button_pad_source(
    button_pad_t_    * device_,
    event_type const * button_ordering_,
    uint8_t const    & button_ordering_size_
  ) : 
    _device(device_),
    _button_ordering(button_ordering_),
    _button_ordering_size(button_ordering_size_),
    queue(),
    queue_write_ix(0),
    queue_read_ix(0),  
    queue_count(0),
    queue_length(0) {}      

  virtual ~button_pad_source() {}

private:
  // lamb::ring_buffer<event_t::event_type_t, buffer_size> queue;
  
  
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

        queue[queue_write_ix %= queue_length, queue_count++, queue_write_ix++] =
          _button_ordering[ix];
      }
    }
  }

  virtual uint8_t impl_queue_count() const {
    return queue_count;
  }

  virtual event_t impl_dequeue_event() {
    return event {
      (queue_count) ?
        (queue[queue_read_ix %= queue_length, queue_count--, queue_read_ix++]) :
        EVT_NOT_AVAILABLE
    };    
  };
};

#endif
