#ifndef SHELF_CLOCK_TIMER1_H
#define SHELF_CLOCK_TIMER1_H

#include "Arduino.h"

class Timer1_ {
  private:
    static          void    set_hz_by_bpm(uint8_t bpm);
    static const    uint8_t MIN_BPM;
    
    uint8_t   _bpm;
    bool      _playback_state;    
    uint8_t   _ticker;
    double    _hz;
    
    static   Timer1_ * _instance;
    
  public:
    static Timer1_ & instance();
    void    setup();
    void    set_playback_state(bool playback_state_);
    bool    playback_state() const;
    void    set_bpm(uint8_t bpm);
    uint8_t bpm() const;
    double  hz() const;
    uint8_t ticker() const;
    void    increment_ticker();    
    Timer1_();
    virtual ~Timer1_();
    
};

#endif
