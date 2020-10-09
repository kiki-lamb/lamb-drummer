#ifndef LAMB_DRUMMER_EVENT_H
#define LAMB_DRUMMER_EVENT_H

#include <Arduino.h>

enum event_type {
  EVT_NOT_AVAILABLE = 0,

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

  EVT_BPM_SET = 30,

  EVT_PLAYBACK_STATE_TOGGLE = 31,

  EVT_ENCODER = 32,
  EVT_BUTTON = 33, 
};

class event {
public:
  typedef event_type event_type_t;
  event_type type;
  uint16_t parameter;

  event(event_type type_ = EVT_NOT_AVAILABLE, uint16_t arg = 0) :
    type(type_), parameter(arg) {}

  inline operator bool() const {
    return type != EVT_NOT_AVAILABLE;
  }
};

#endif
