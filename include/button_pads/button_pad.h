#ifndef LAMB_DRUMMER_I_BUTTON_PAD_PIN_H
#define LAMB_DRUMMER_I_BUTTON_PAD_PIN_H

#include <Arduino.h>

template <typename T>
class button_pad {
public:
  typedef T button_mask_type;

  button_pad() {}

  virtual ~button_pad() {}

  virtual bool read() {
    return impl_read();
  }

  virtual uint16_t buttons() const {
    return impl_buttons();
  }
  
  virtual void setup() {
    impl_setup();
  }
  
private:
  virtual bool             impl_read() = 0;
  virtual button_mask_type impl_buttons() const = 0;
  virtual void             impl_setup() = 0;
};

#endif
