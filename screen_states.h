#ifndef SHELF_CLOCK_SCREEN_STATES_H
#define SHELF_CLOCK_SCREEN_STATES_H

#include "Arduino.h"
#include "i_screen_state.h"

class SSIntro : public IScreenState {      
  virtual void impl_enter();
  virtual void impl_update();
};

class SSInstr : public IScreenState {
  virtual void impl_enter();
  virtual void impl_update();
};

class SSNone : public IScreenState {
  virtual void impl_enter();
  virtual void impl_update();
};

#endif
