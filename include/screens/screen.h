#ifndef LAMB_DRUMMER_I_SCREEN_STATE_H
#define LAMB_DRUMMER_I_SCREEN_STATE_H

#include <lamb.h>
#include "lcd.h"

template <class data_t_>
class screen {
protected:
  lamb::flag requires_update;

public:
  typedef data_t_ data_t;
  data_t * data;

  explicit screen(data_t * data_) :
    requires_update(true),
    data(data_) {
    flag();
  }

  void flag() {
    requires_update.set();
  }

  bool update() {
    if (requires_update.consume()) {
      if (!  impl_update()) {
        requires_update.set();
        return false;
      }

      return true;
    }
    
    return false;
  }

  void enter() {
    requires_update.consume();

    lcd::clear();

    impl_enter();
  }

private:
  virtual bool impl_update() = 0;

  virtual void impl_enter() = 0;
};

#endif
