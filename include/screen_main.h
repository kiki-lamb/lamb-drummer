#ifndef SHELF_CLOCK_SCREEN_STATE_MAIN_H
#define SHELF_CLOCK_SCREEN_STATE_MAIN_H

#include "Arduino.h"
#include "i_screen.h"
#include "ui_data.h"
#include "track_collection.h"
#include "flag.h"

class SSMain : public IScreenState<UiData<TrackStateCollection<3, TrackState> > > {
public:
  SSMain(data_t * data);
private:
  virtual void  impl_enter();
  virtual void  impl_update();
  void          draw_bars();
  void 				  draw_channel_numbers();
  void 				  draw_column(uint8_t step, bool highlit = false, bool log_this = false);
  void 			 	  draw_line0(bool redraw_bpm = false);
  void 			    draw_page_number();
  unsigned long popup_bpm_time;
  bool          popup_bpm_state;
  static const unsigned long
                popup_bpm_duration = 600;
};


#endif
