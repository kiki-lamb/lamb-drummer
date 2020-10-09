#ifndef LAMB_DRUMMER_SCREEN_STATE_MAIN_H
#define LAMB_DRUMMER_SCREEN_STATE_MAIN_H

#include <lamb.h>
#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "track_collection/track_collection.h"
#include "tracks/euclidean.h"

class screen_main :
  public screen<ui_data<track_collection<3, tracks::euclidean> > > {
public:
  screen_main(data_t * data);
private:
  virtual void      impl_enter() override;
  virtual void      impl_update() override;
  void              draw_bars();
  void 		    draw_channel_numbers();
  void 		    draw_column(
    uint8_t const & col,
    uint8_t const & mod_maj
  );
  void 		    draw_column(
    uint8_t const & channel,
    uint8_t const & col,
    uint8_t const & mod_maj
  );
  void 		draw_line0(bool const & redraw_bpm = false);
  void 		draw_page_number();

  template <size_t size>
  uint8_t max_mod_maj(
    track_collection<size, tracks::euclidean> const & that
  ) {
    uint8_t max = 0;
    
    for (uint8_t ix = 0; ix < that.size(); ix++)
      if (that[ix].mod_maj() > max)
        max = that[ix].mod_maj();
    
    return max;
  }
                      
  unsigned long popup_bpm_time;
  bool          popup_bpm_state;
  static const unsigned long
                popup_bpm_duration = 600;
};


#endif
