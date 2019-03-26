#ifndef SHELF_CLOCK_SCREEN_STATES_H
#define SHELF_CLOCK_SCREEN_STATES_H

#include "Arduino.h"
#include "i_screen_state.h"
#include "ui_data.h"
#include "track_state_collection.h"

class SSIntro : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  virtual void impl_enter();
  virtual void impl_update();
};

class SSInstr : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  virtual void impl_enter();
  virtual void impl_update();
};

class SSNone : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  virtual void impl_enter();
  virtual void impl_update();
};

#endif
