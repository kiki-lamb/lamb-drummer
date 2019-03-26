#ifndef SHELF_CLOCK_I_SCREEN_STATE_H
#define SHELF_CLOCK_I_SCREEN_STATE_H

#include "lcd.h"
#include "flag.h"

template <class data_t>
class IScreenState {
  private:
    Flag requires_update;

  public:
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

    void update() {
      if (requires_update.consume())
        impl_update();
    }

    void enter() {
      requires_update.consume();

      lcd().clear();

      impl_enter();
    }
  private:
    virtual void impl_update() = 0;
    virtual void impl_enter() = 0;
};

#endif
