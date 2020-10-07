#ifndef LAMB_DRUMMER_SCREEN_STATE_MAIN_H
#define LAMB_DRUMMER_SCREEN_STATE_MAIN_H

#include <lamb.h>
#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "track_collection/track_collection.h"

class screen_main : public screen<ui_data<track_collection<3, track> > > {
public:
  screen_main(data_t * data);
private:
  virtual void      impl_enter() override;
  virtual void      impl_update() override;
  void              draw_bars();
  void 		    draw_channel_numbers();
  void 		    draw_column(
    uint8_t const & step,
    bool    const & highlit,
    uint8_t const & mod_maj
  );
  void 		draw_line0(bool const & redraw_bpm = false);
  void 		draw_page_number();
  unsigned long popup_bpm_time;
  bool          popup_bpm_state;
  static const unsigned long
                popup_bpm_duration = 600;
};


#endif
