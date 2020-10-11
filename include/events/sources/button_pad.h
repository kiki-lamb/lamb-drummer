#ifndef LAMB_DRUMMER_BUTTON_PAD_SOURCE_H
#define LAMB_DRUMMER_BUTTON_PAD_SOURCE_H

#include <Arduino.h>
#include "../control.h"
#include "lamb.h"

namespace events {
  namespace sources {
    
    template <
      class button_pad_t_,
      typename event,
      uint8_t event_number,
      size_t buffer_size = 8
      >
    class button_pad :
      public lamb::events::sources::source<event>{
    public:
      typedef button_pad_t_ button_pad_type;

    private:
      button_pad_type  * _device;
      uint8_t _button_number_mask;

    public:
      button_pad(
        button_pad_t_    * device_,
        uint8_t button_number_mask_
      ) : 
        _device(device_),
        _button_number_mask(button_number_mask_) {}

    private:
      virtual void    impl_poll() {
        _device->read();
      }

      virtual uint8_t impl_queue_count() const {
        return _device->button_events_count;
      }

      virtual event impl_dequeue_event() {
        if (! light_buffer_readable(_device->button_events))
          return event { (typename event::event_type)0 };

        typename button_pad_type::button_event tmp =
          light_buffer_read(_device->button_events);

        uint16_t event_arg = (
          ((tmp.button_number | _button_number_mask) << 8) |
          ((uint8_t)tmp.button_state)
        );

        return event { (typename event::event_type)event_number, event_arg };
      };
    };
  }
}
#endif
