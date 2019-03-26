#ifndef SHELF_CLOCK_I_SCREEN_STATE_H
#define SHELF_CLOCK_I_SCREEN_STATE_H

#include "lcd.h"
#include "flag.h"

template <class data_t_>
class IScreenState {
private:
  Flag requires_update;

public:
  typedef data_t_ data_t;

  IScreenState() :
    requires_update("requires_update", true) {
    flag();
  }

  virtual ~IScreenState() {
  }

  void flag() {
    requires_update.flag();
  }

  LiquidCrystal & lcd() {
    return Lcd::lcd;
  }

  void update(data_t d) {
    if (requires_update.consume())
      impl_update(d);
  }

  void enter(data_t d) {
    requires_update.consume();

    lcd().clear();

    impl_enter(d);
  }
private:
  virtual void impl_update(data_t d) = 0;
  virtual void impl_enter(data_t d) = 0;
};

#endif
