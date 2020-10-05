#ifndef LAMB_DRUMMER_SCREEN_STATES_H
#define LAMB_DRUMMER_SCREEN_STATES_H

#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "track_collection/track_collection.h"

class SSIntro : public Screen<UiData<track_collection<3, track> > > {
public:
  SSIntro(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

class SSInstr : public Screen<UiData<track_collection<3, track> > > {
public:
  SSInstr(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

class SSNone : public Screen<UiData<track_collection<3, track> > > {
public:
  SSNone(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

#endif
