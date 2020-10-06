#ifndef LAMB_DRUMMER_I_SCREEN_STATE_H
#define LAMB_DRUMMER_I_SCREEN_STATE_H

#include <lamb.h>
#include "lcd.h"

template <class data_t_>
class screen {
private:
  lamb::flag requires_update;

public:
  typedef data_t_ data_t;
  data_t * data;

  screen(data_t * data_) :
    requires_update("ru", true),
    data(data_) {
    flag();
  }

  virtual ~screen() {
  }

  void flag() {
    requires_update.set();
  }

  void update() {
    if (!requires_update.consume())
      return;
    
    unsigned long now = micros();

    impl_update();
    
    unsigned long delta = micros() - now;;

    Serial.print(F("Update took "));
    Serial.print(delta);
    Serial.println(F(" us."));
  }

  void enter() {
    requires_update.consume();

    lcd::clear();

    impl_enter();
  }

private:
  virtual void impl_update() = 0;

  virtual void impl_enter() = 0;
};

#endif
