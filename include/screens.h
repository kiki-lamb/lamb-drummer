#ifndef SHELF_CLOCK_SCREEN_STATES_H
#define SHELF_CLOCK_SCREEN_STATES_H

#include "Arduino.h"
#include "i_screen.h"
#include "ui_data.h"
#include "track_collection.h"

class SSIntro : public IScreen<UiData<TrackCollection<3, Track> > > {
public:
  SSIntro(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

class SSInstr : public IScreen<UiData<TrackCollection<3, Track> > > {
public:
  SSInstr(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

class SSNone : public IScreen<UiData<TrackCollection<3, Track> > > {
public:
  SSNone(data_t * data);
private:
  virtual void impl_enter();
  virtual void impl_update();
};

#endif
