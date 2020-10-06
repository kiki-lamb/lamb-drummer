#ifndef LAMB_DRUMMER_I_ENCODER_PAD_SOURCE_H
#define LAMB_DRUMMER_I_ENCODER_PAD_SOURCE_H

#include <Arduino.h>
#include "event_source.h"
#include "event/event.h"
#include "lamb.h"
#include "application.h"

template <class encoder_pad_t_>
class encoder_pad_source : public encoder_pad_t_, public event_source<event>{
public:
  typedef encoder_pad_t_ encoder_pad_type;
  
  encoder_pad_source() {}

  virtual ~encoder_pad_source() {}

private:
  virtual void    impl_poll() {
    encoder_pad_type::read();
  }

  virtual uint8_t impl_queue_count() const {
    return encoder_pad_type::motion_events.count();
  }

  virtual event_t impl_dequeue_event() {
    if (! encoder_pad_type::motion_events.readable())
      return event { EVT_NOT_AVAILABLE };

    typename encoder_pad_type::motion_event tmp =
      encoder_pad_type::motion_events.dequeue();

    uint16_t event_arg = (tmp.encoder_number << 8) | ((uint8_t)tmp.motion);

    return event { EVT_ENCODER, event_arg };
  };
};

#endif
