#ifndef LAMB_DRUMMER_I_BUTTON_PAD_SOURCE_H
#define LAMB_DRUMMER_I_BUTTON_PAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"
#include "button_pads/button_pad.h"
#include "event/event.h"
#include "lamb.h"
#include "application.h"

template <class button_pad_t_, size_t buffer_size = 8>
class button_pad_source : public button_pad_t_, public event_source<event>{
public:
  typedef button_pad_t_ button_pad_type;
  
  button_pad_source() {}

//  template <typename arg_type>
//  button_pad_source(arg_type arg) : button_pad_type(arg) {}
  
  virtual ~button_pad_source() {}

private:
  static  event_t::event_type_t button_pad_ordering[16];
  
  lamb::ring_buffer<event_t::event_type_t, buffer_size> queue;

  void print_bits_16(uint16_t tmpval) const {
    for(uint16_t mask = 32768; mask; mask >>= 1) {
      if(mask  & tmpval) {
        Serial.print('1'); Serial.flush();
      }
      else {
        Serial.print('.'); Serial.flush();
      }
    }
  }

  virtual void    impl_poll() {
    // Serial.println("Poll...");
    
    if (! button_pad_type::read())
      return;
    
    uint16_t tmp_buttons = button_pad_type::buttons();
    uint16_t mask = 1;
    
    // Serial.print("Examine  ");
    // print_bits_16(tmp_buttons);
    // Serial.println();
    
    for (uint8_t ix = 0; ix < 16; ix++, mask <<= 1) {
      if (mask & tmp_buttons) {
        // Serial.print("Enqueue ");
        // Serial.println(button_pad_ordering[ix]);
        
        queue.enqueue(button_pad_ordering[ix]);
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
