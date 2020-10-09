#ifndef LAMB_DRUMMER_I_ENCODER_PAD_SOURCE_H
#define LAMB_DRUMMER_I_ENCODER_PAD_SOURCE_H

#include <Arduino.h>
#include "source.h"
#include "../control.h"
#include "lamb.h"

namespace events {
  namespace sources {
    template <class encoder_pad_t_>
    class encoder_pad : public source<events::control> {
    public:
      typedef encoder_pad_t_ encoder_pad_type;
  
    private:
      encoder_pad_type * _device;
      uint8_t _button_number_mask;
  
    public:
      encoder_pad(
        encoder_pad_type * device_,
        uint8_t button_number_mask_
      ) :
        _device(device_),
        _button_number_mask(button_number_mask_) {}

      /* virtual */ ~encoder_pad() {}

    private:
      virtual void    impl_poll() {
        _device->read();
      }

      virtual uint8_t impl_queue_count() const {
        return _device->motion_events_count;
      }

      virtual event_type impl_dequeue_event() {
        if (! light_buffer_readable(_device->motion_events))
          return events::control {
            events::control::EVT_NOT_AVAILABLE
              };

        typename encoder_pad_type::motion_event tmp =
          light_buffer_read(_device->motion_events);

        uint16_t event_arg = (
          ((tmp.encoder_number | _button_number_mask) << 8) |
          ((uint8_t)tmp.motion)
        );

        return events::control {
          events::control::EVT_ENCODER, event_arg
            };
      };
    };
  }
}
#endif
