#ifndef SHELF_CLOCK_SCREEN_STATES_H
#define SHELF_CLOCK_SCREEN_STATES_H

#include "Arduino.h"
#include "i_screen_state.h"
#include "ui_data.h"
#include "track_state_collection.h"

class SSMain : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  public:
  SSMain();

  private:
  // Application::tracks_t const &
	// 	           track_states();
  virtual void impl_enter(data_t d);
  virtual void impl_update(data_t d);
  void         draw_bars(data_t & d);
  void 				 draw_channel_numbers(data_t & d);
  void 				 draw_column(data_t & d, uint8_t step, bool highlit = false, bool log_this = false);
  void 				 draw_line0(data_t & d);
  void 				 draw_page_number(data_t & d);

  static const unsigned long popup_bpm_duration = 600;
  unsigned long              popup_bpm_time;
  bool                       popup_bpm_state;
};

class SSIntro : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  virtual void impl_enter(data_t d);
  virtual void impl_update(data_t d);
};

class SSInstr : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  virtual void impl_enter(data_t d);
  virtual void impl_update(data_t d);
};

class SSNone : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  virtual void impl_enter(data_t d);
  virtual void impl_update(data_t d);
};

#endif
