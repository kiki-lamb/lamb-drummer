#ifndef LAMB_DRUMMER_I_ENCODER_PAD_SOURCE_H
#define LAMB_DRUMMER_I_ENCODER_PAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"

#include "event/event.h"
#include "lamb.h"

template <class encoder_pad_t_>
class encoder_pad_source : public event_source<event> {
public:
  typedef encoder_pad_t_ encoder_pad_type;
  
private:
  encoder_pad_type * _device;
  uint8_t _button_number_mask;
  
public:
  encoder_pad_source(
    encoder_pad_type * device_,
    uint8_t button_number_mask_ = 034    
  ) :
    _device(device_), _button_number_mask(button_number_mask_) {}

  virtual ~encoder_pad_source() {}

private:
  virtual void    impl_poll() {
    _device->read();
  }

  virtual uint8_t impl_queue_count() const {
    return _device->motion_events_count;
  }

  virtual event_t impl_dequeue_event() {
    if (! light_buffer_readable(_device->motion_events))
      return event { EVT_NOT_AVAILABLE };

    typename encoder_pad_type::motion_event tmp =
      light_buffer_read(_device->motion_events);

    uint16_t event_arg = (
      ((tmp.encoder_number | _button_number_mask) << 8) | ((uint8_t)tmp.motion)
    );

    return event { EVT_ENCODER, event_arg };
  };
};

#endif
