#ifndef SHELF_CLOCK_UI_DATA_H
#define SHELF_CLOCK_UI_DATA_H

#include "Arduino.h"

template <class tracks_t>
class UiData {
public:
  tracks_t const *
                tracks;
  uint8_t       page;
  uint8_t       bpm;
  double        hz;
  bool          playback_state;
  uint8_t       ticker;
  lamb::Flag    popup_bpm_requested;
  lamb::Flag    redraw_track;
  lamb::Flag    redraw_selected_track_indicator;
  lamb::Flag    redraw_playback_state;
  UiData() :
    popup_bpm_requested            ("pbr", true),
    redraw_track                   ("rt", true),
    redraw_selected_track_indicator("rsti", true),
    redraw_playback_state          ("rps", true)
  {}
  virtual ~UiData() {};
};

#endif
