#ifndef LAMB_DRUMMER_UI_DATA_H
#define LAMB_DRUMMER_UI_DATA_H

#include "Arduino.h"

template <class tracks_t_>
class ui_data {
public:
  typedef tracks_t_ tracks_t;
  
  tracks_t const * tracks;
  uint8_t          bar;
  uint8_t          page;
  uint8_t          bpm;
  uint16_t         millihz;
  bool             playback_state;
  uint8_t          ticker;
  lamb::flag       popup_bpm_requested;
  lamb::flag       redraw_bar;
  lamb::flag       redraw_track;
  lamb::flag       redraw_selected_track_indicator;
  lamb::flag       redraw_playback_state;

  ui_data() :
    tracks(),
    bar(0),
    page(0),
    bpm(120),
    millihz(0),
    playback_state(false),
    ticker(0),
    popup_bpm_requested            (true),
    redraw_track                   (true),
    redraw_selected_track_indicator(true),
    redraw_playback_state          (true)
  {}
};

#endif
