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
  Flag *  popup_bpm_requested;
  Flag *  redraw_track;
  Flag *  redraw_selected_track_indicator;
  Flag *  redraw_playback_state;

  UiData() {}

  UiData(
    tracks_t const * tracks_,
    uint8_t          page_,
    uint8_t          bpm_,
    double           hz_,
    bool             playback_state_,
    uint8_t          ticker_,
    Flag *           popup_bpm_requested_,
    Flag *           redraw_track_,
    Flag *           redraw_selected_track_indicator_,
    Flag *           redraw_playback_state_
  ) :
    tracks(tracks_),
    page(page_),
    bpm(bpm_),
    hz(hz_),
    playback_state(playback_state_),
    ticker(ticker_),
    popup_bpm_requested(popup_bpm_requested_),
    redraw_track(redraw_track_),
    redraw_selected_track_indicator(redraw_selected_track_indicator_),
    redraw_playback_state(redraw_playback_state)
  {}

  virtual ~UiData() {};
};

#endif
