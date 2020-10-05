#ifndef LAMB_DRUMMER_UI_DATA_H
#define LAMB_DRUMMER_UI_DATA_H

#include "Arduino.h"

template <class tracks_t>
class ui_data {
public:
  tracks_t const * tracks;
  uint8_t          page;
  uint8_t          bpm;
  double           hz;
  bool             playback_state;
  uint8_t          ticker;
  lamb::flag       popup_bpm_requested;
  lamb::flag       redraw_track;
  lamb::flag       redraw_selected_track_indicator;
  lamb::flag       redraw_playback_state;
  ui_data() :
    popup_bpm_requested            ("pbr" , true),
    redraw_track                   ("rt"  , true),
    redraw_selected_track_indicator("rsti", true),
    redraw_playback_state          ("rps" , true)
  {}
  virtual ~ui_data() {};
};

#endif
