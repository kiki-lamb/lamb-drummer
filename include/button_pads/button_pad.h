#ifndef LAMB_DRUMMER_I_BUTTON_PAD_PIN_H
#define LAMB_DRUMMER_I_BUTTON_PAD_PIN_H

#include <Arduino.h>

class button_pad {
public:
  button_pad();
  virtual ~button_pad();
  bool    read();
  uint8_t button() const;
  void    setup();
private:
  virtual bool    impl_read() = 0;
  virtual uint8_t impl_button() const = 0;
  virtual void    impl_setup() = 0;
};

#endif
