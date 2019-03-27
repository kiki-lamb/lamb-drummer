#ifndef SHELF_CLOCK_UI_DATA_H
#define SHELF_CLOCK_UI_DATA_H

#include "Arduino.h"

template <class tracks_t>
class UiData {
public:
  tracks_t const *
          tracks;
  uint8_t page;
  uint8_t bpm;
  double  hz;
  bool    playback_state;
  uint8_t ticker;
  Flag    popup_bpm_requested;
  Flag    redraw_track;
  Flag    redraw_selected_track_indicator;
  Flag    redraw_playback_state;
  UiData() :
    popup_bpm_requested("pbr", true),
    redraw_track("rt", true),
    redraw_selected_track_indicator("rsti", false),
    redraw_playback_state("rps", false)
  {}
  virtual ~UiData() {};
};

#endif
