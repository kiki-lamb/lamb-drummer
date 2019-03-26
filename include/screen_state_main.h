#ifndef SHELF_CLOCK_SCREEN_STATE_MAIN_H
#define SHELF_CLOCK_SCREEN_STATE_MAIN_H

#include "Arduino.h"
#include "i_screen_state.h"
#include "ui_data.h"
#include "track_state_collection.h"
#include "flag.h"

class SSMain : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
  public:
  SSMain(
    Flag * popup_bpm_requested,
    Flag * redraw_bpm,
    Flag * redraw_playback_state,
    Flag * redraw_selected_track_indicator,
    Flag * redraw_track
  );

  private:
// Application::tracks_t const &
// 	           track_states();
  Flag * popup_bpm_requested;
  Flag * redraw_bpm;
  Flag * redraw_playback_state;
  Flag * redraw_selected_track_indicator;
  Flag * redraw_track;
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


#endif
