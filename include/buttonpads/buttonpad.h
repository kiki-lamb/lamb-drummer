#ifndef LAMB_DRUMMER_I_BUTTONPAD_PIN_H
#define LAMB_DRUMMER_I_BUTTONPAD_PIN_H

#include <Arduino.h>

class Buttonpad {
public:
  Buttonpad();
  virtual ~Buttonpad();
  bool    read();
  uint8_t button() const;
  void    setup();
private:
  virtual bool    impl_read() = 0;
  virtual uint8_t impl_button() const = 0;
  virtual void    impl_setup() = 0;
};

#endif
