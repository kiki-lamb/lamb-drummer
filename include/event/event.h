#ifndef LAMB_DRUMMER_EVENT_H
#define LAMB_DRUMMER_EVENT_H

#include <Arduino.h>

enum EventType {
  EVT_PAD0_ON = 0,
  EVT_PAD1_ON = 1,
  EVT_PAD2_ON = 2,
  EVT_PAD3_ON = 3,
  
  EVT_PAD4_ON = 4,
  EVT_PAD5_ON = 5,
  EVT_PAD6_ON = 6,
  EVT_PAD7_ON = 7,

  EVT_PAD8_ON = 8,
  EVT_PAD9_ON = 9,
  EVT_PAD10_ON = 10,
  EVT_PAD11_ON = 11,

  EVT_PAD12_ON = 12,
  EVT_PAD13_ON = 13,
  EVT_PAD14_ON = 14,
  EVT_PAD15_ON = 15,

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

  EVT_NOT_AVAILABLE = 32,
};

class Event {
public:
  typedef EventType event_type_t;
  EventType type;
  uint8_t parameter;

  Event(EventType type_ = EVT_NOT_AVAILABLE) : type(type_) {}

  inline operator bool() const {
    return type != EVT_NOT_AVAILABLE;
  }
};

#endif
