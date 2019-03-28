#ifndef SHELF_CLOCK_EVENT_H
#define SHELF_CLOCK_EVENT_H

#include <Arduino.h>

enum EventType {
  EVT_MIN_UP,
  EVT_MIN_DN,
  EVT_MAJ_UP,
  EVT_MAJ_DN,
  EVT_PHASE_MIN_UP,
  EVT_PHASE_MIN_DN,
  EVT_PHASE_MAJ_UP,
  EVT_PHASE_MAJ_DN,
  EVT_SELECTED_TRACK_UP,
  EVT_SELECTED_TRACK_DN,
  EVT_BPM_SET,
  EVT_PLAYBACK_STATE_TOGGLE,
  EVT_NOT_AVAILABLE
};

struct Event {
  typedef EventType event_type_t;
  EventType type;
  uint8_t parameter;

  inline bool valid() const {
    return type != EVT_NOT_AVAILABLE;
  }

  inline void invalidate() {
    type = EVT_NOT_AVAILABLE;
  }
};

#endif
