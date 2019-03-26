#ifndef SHELF_CLOCK_SCREEN_STATE_MAIN_H
#define SHELF_CLOCK_SCREEN_STATE_MAIN_H

#include "Arduino.h"
#include "i_screen_state.h"
#include "application.h"

class SSMain : public IScreenState {
  public:
  SSMain();

  template <class collection_t>
  class UiData {
    collection_t * track_states;
    uint8_t const & (*page)();
    uint8_t const & (*bpm)();
    double  const & (*hz)();
    bool    const & (*playback_state)();
    uint8_t const & (*ticker)();
  };

  private:
  Application::track_collection_t const & track_states();
  virtual void impl_enter();
  virtual void impl_update();
  void draw_bars();
  void draw_channel_numbers();
  void draw_column(uint8_t step, bool highlit = false, bool log_this = false);
  void draw_line0();
  void draw_page_number();
  static const unsigned long POP_DURATION;
  unsigned long popup_bpm_time;
  bool     popup_bpm_state;
};

#endif
