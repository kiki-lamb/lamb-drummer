#ifndef SHELF_CLOCK_I_SCREEN_STATE_H
#define SHELF_CLOCK_I_SCREEN_STATE_H

#include "lcd.h"
#include "flag.h"

class IScreenState {      
  public:
  IScreenState();
  virtual ~IScreenState();

  void flag();
  void update();
  void enter();

  static LiquidCrystal & lcd();

  private:
  Flag requires_update;
  virtual void impl_update() = 0;
  virtual void impl_enter() = 0;

};

#endif
