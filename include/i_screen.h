#ifndef SHELF_CLOCK_I_SCREEN_STATE_H
#define SHELF_CLOCK_I_SCREEN_STATE_H

#include "lcd.h"
#include "flag.h"

template <class data_t_>
class IScreen {
private:
  Flag requires_update;

public:
  typedef data_t_ data_t;
  data_t * data;

  IScreen(data_t * data_) :
    requires_update("requires_update", true),
    data(data_) {
    flag();
  }

  virtual ~IScreen() {
  }

  void flag() {
    requires_update.flag();
  }

  void update() {
    if (requires_update.consume())
      impl_update();
  }

  void enter() {
    requires_update.consume();

    lcd().clear();

    impl_enter();
  }
protected:
  LiquidCrystal & lcd() {
    return Lcd::lcd;
  }
private:
  virtual void impl_update() = 0;
  virtual void impl_enter() = 0;
};

#endif
