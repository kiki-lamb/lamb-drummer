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
  uint8_t _button_number_mask;
  
  event_type const * _button_ordering;
  uint8_t            _button_ordering_size;

public:
  button_pad_source(
    button_pad_t_    * device_,
    uint8_t button_number_mask_,
    event_type const * button_ordering_,
    uint8_t const    & button_ordering_size_
  ) : 
    _device(device_),
    _button_number_mask(button_number_mask_),
    _button_ordering(button_ordering_),
    _button_ordering_size(button_ordering_size_) {}

  /* virtual */ ~button_pad_source() {}

private:
  virtual void    impl_poll() {
    _device->read();
  }

  virtual uint8_t impl_queue_count() const {
    return _device->button_events_count;
  }

  virtual event_t impl_dequeue_event() {
    if (! light_buffer_readable(_device->button_events))
      return event { EVT_NOT_AVAILABLE };

    typename button_pad_type::button_event tmp =
      light_buffer_read(_device->button_events);

    uint16_t event_arg = (
      ((tmp.button_number | _button_number_mask) << 8) |
      ((uint8_t)tmp.button_state)
    );

    return event { EVT_BUTTON, event_arg };
  };
};

#endif
