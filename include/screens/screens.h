#ifndef LAMB_DRUMMER_SCREEN_STATES_H
#define LAMB_DRUMMER_SCREEN_STATES_H

#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "track_collection/track_collection.h"

class screen_intro : public screen<UiData<track_collection<3, track> > > {
public:
  screen_intro(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

class screen_instr : public screen<UiData<track_collection<3, track> > > {
public:
  screen_instr(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

class screen_none : public screen<UiData<track_collection<3, track> > > {
public:
  screen_none(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

#endif
