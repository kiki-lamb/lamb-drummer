#include "i_controls.h"

IControls::IControls() {};
IControls::~IControls() {};

void IControls::setup() {
  impl_setup();
}

uint8_t IControls::queue_count() const {
  return impl_queue_count();
}

IControls::ControlEvent IControls::dequeue_event(){
  return impl_dequeue_event();
}

void IControls::set_encoder(uint8_t val) { // try to get rid of this
  impl_set_encoder(val);
}

void IControls::poll() {
  impl_poll();
}

