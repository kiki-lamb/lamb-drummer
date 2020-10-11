#ifndef LAMB_DRUMMER_SCREEN_STATE_MAIN_H
#define LAMB_DRUMMER_SCREEN_STATE_MAIN_H

#include <lamb.h>
#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "track_collection/track_collection.h"
#include "tracks/euclidean.h"
#include "tracks/x0x.h"

////////////////////////////////////////////////////////////////////////////////

template <typename data_t>
class screen_main :
  public screen<data_t> {
  
private:
  virtual void      impl_enter() override;

  virtual bool      impl_update() override;
};

////////////////////////////////////////////////////////////////////////////////

#include "screen_main_euclidean_3.h"
#include "screen_main_x0x_3.h"

#endif
