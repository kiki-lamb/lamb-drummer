#ifndef SHELF_CLOCK_UI_DATA_H
#define SHELF_CLOCK_UI_DATA_H

#include "Arduino.h"

template <class tracks_t>
class UiData {
public:
  tracks_t const * track_states;
  uint8_t page;
  uint8_t bpm;
  double  hz;
  bool    playback_state;
  uint8_t ticker;

  UiData(
    tracks_t const * track_states_,
    uint8_t          page_,
    uint8_t          bpm_,
    double           hz_,
    bool             playback_state_,
    uint8_t          ticker_
  ) :
    track_states(track_states_),
    page(page_),
    bpm(bpm_),
    hz(hz_),
    playback_state(playback_state_),
    ticker(ticker_)
  {};

  virtual ~UiData() {};
};

#endif
