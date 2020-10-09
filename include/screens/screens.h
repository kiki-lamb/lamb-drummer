#ifndef LAMB_DRUMMER_SCREEN_STATES_H
#define LAMB_DRUMMER_SCREEN_STATES_H

#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "track_collection/track_collection.h"

class screen_intro : public screen<ui_data<track_collection<3, track> > > {
public:
  explicit screen_intro(data_t * data);
private:
  virtual void impl_enter() override;
  virtual void impl_update() override;
};

class screen_instr : public screen<ui_data<track_collection<3, track> > > {
public:
  explicit screen_instr(data_t * data);
private:
  virtual void impl_enter() override;
  virtual void impl_update() override;
};

class screen_none : public screen<ui_data<track_collection<3, track> > > {
public:
  explicit screen_none(data_t * data);
private:
  virtual void impl_enter() override;
  virtual void impl_update() override;
};

#endif
