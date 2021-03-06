#ifndef LAMB_DRUMMER_APPLICATION_EVENT_H
#define LAMB_DRUMMER_APPLICATION_EVENT_H

#include <Arduino.h>
#include "lamb.h"

namespace events {
  enum application_event_type {
    APP_EVT_NOT_AVAILABLE = 0,
    
    EVT_PAD_1 = 1,
    EVT_PAD_2 = 2,
    EVT_PAD_3 = 3,
    EVT_PAD_4 = 4,
    
    EVT_PAD_5 = 5,
    EVT_PAD_6 = 6,
    EVT_PAD_7 = 7,
    EVT_PAD_8 = 8,
    
    EVT_PAD_9 = 9,
    EVT_PAD_10 = 10,
    EVT_PAD_11 = 11,
    EVT_PAD_12 = 12,
    
    EVT_PAD_13 = 13,
    EVT_PAD_14 = 14,
    EVT_PAD_15 = 15,
    EVT_PAD_16 = 16,
    
    EVT_MIN_UP = 20,
    EVT_MIN_DN = 21,
    
    EVT_MAJ_UP = 22,
    EVT_MAJ_DN = 23,
    
    EVT_PHASE_MIN_UP = 24,
    EVT_PHASE_MIN_DN = 25,
    
    EVT_PHASE_MAJ_UP = 26,
    EVT_PHASE_MAJ_DN = 27,
    
    EVT_SELECTED_TRACK_UP = 28,
    EVT_SELECTED_TRACK_DN = 29,
    
    EVT_BPM_UP = 30,
    EVT_BPM_DN = 31,
    
    EVT_PLAYBACK_STATE_TOGGLE = 32,
    
    EVT_SELECT_TRACK = 33,
    
    EVT_PAGE_UP = 34,
    EVT_PAGE_DN = 35,
    EVT_PAGE_TOGGLE = 36,

    EVT_PAGE_L = 37,
    EVT_PAGE_R = 38,
    
    EVT_UNKNOWN = 64
  };  

  class application :
    public lamb::events::event<application_event_type> {
  public:
    application(
      event_type type_ = event_type::APP_EVT_NOT_AVAILABLE,
      uint16_t arg = 0
    ) :
      event(type_, arg) {}
  };
}

#endif
