#ifndef SHELF_CLOCK_SCREEN_STATE_MAIN_H
#define SHELF_CLOCK_SCREEN_STATE_MAIN_H

#include "Arduino.h"
#include "i_screen_state.h"
#include "application.h"

class SSMain : public IScreenState { 
  public:
  SSMain();
  
  private:
  Application::collection_t const & track_states();
  virtual void impl_enter();  
  virtual void impl_update();
  void draw_bars() const; 
  void draw_channel_numbers() const;
  void draw_column(uint8_t step, bool highlit = false, bool log_this = false) const;
  void draw_line0() const;
  void draw_page_number() const;  
  static const unsigned long POP_DURATION;
  unsigned long popup_bpm_time;
  bool     popup_bpm_state;
};

#endif
