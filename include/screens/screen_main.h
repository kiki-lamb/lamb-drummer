#ifndef SHELF_CLOCK_SCREEN_STATE_MAIN_H
#define SHELF_CLOCK_SCREEN_STATE_MAIN_H

#include <lamb.h>
#include "Arduino.h"
#include "screen.h"
#include "ui_data.h"
#include "track_collection/track_collection.h"

class SSMain : public Screen<UiData<TrackCollection<3, Track> > > {
public:
  SSMain(data_t * data);
private:
  virtual void  impl_enter();
  virtual void  impl_update();
  void          draw_bars();
  void 				  draw_channel_numbers();
  void 				  draw_column(uint8_t step, bool highlit, uint8_t mod_maj);
  void 			 	  draw_line0(bool redraw_bpm = false);
  void 			    draw_page_number();
  unsigned long popup_bpm_time;
  bool          popup_bpm_state;
  static const unsigned long
                popup_bpm_duration = 600;
};


#endif
