#ifndef LAMB_DRUMMER_TIMER1_H
#define LAMB_DRUMMER_TIMER1_H

#include "Arduino.h"

class timer1 {
private:
  static       void    set_hz_by_bpm(uint8_t const & bpm);
  uint8_t              _track_count;
  uint8_t              _bpm;
  bool                 _playback_state;
  uint8_t              _ticker;
  uint16_t             _millihz;
  static timer1 *      _instance;
  void                 draw_track_on_x0x_leds();
public:
  void                 isr();
  static timer1 &      instance();
  void                 setup();
  void                 set_playback_state(bool const & playback_state_);
  bool                 playback_state() const;
  void                 set_bpm(uint8_t const & bpm);
  uint8_t              bpm() const;
  uint16_t             millihz() const;
  uint8_t              ticker() const;
  void                 increment_ticker();
  timer1(uint8_t const & track_count_);
};

#endif
