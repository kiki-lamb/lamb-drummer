#ifndef LAMB_DRUMMER_TIMER1_H
#define LAMB_DRUMMER_TIMER1_H

#include "Arduino.h"

class timer1_ {
  private:
    static       void    set_hz_by_bpm(uint8_t const & bpm);
    uint8_t              _bpm;
    bool                 _playback_state;
    uint8_t              _ticker;
    uint16_t             _millihz;
    static timer1_ *     _instance;
  public:
    void                 isr();
    static timer1_ &     instance();
    void                 setup();
    void                 set_playback_state(bool const & playback_state_);
    bool                 playback_state() const;
    void                 set_bpm(uint8_t const & bpm);
    uint8_t              bpm() const;
    uint16_t             millihz() const;
    uint8_t              ticker() const;
    void                 increment_ticker();
    /* virtual */ ~timer1_();
    timer1_();
};

#endif
