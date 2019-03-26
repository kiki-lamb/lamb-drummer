#ifndef SHELF_CLOCK_I_CONTROLS_H
#define SHELF_CLOCK_I_CONTROLS_H

#include "Arduino.h"

class IControls {
public:
  IControls();
  virtual ~IControls();
  enum ControlEventType {
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
  struct ControlEvent {
    ControlEventType type;
    uint8_t parameter;
  };
  void                 setup();
  uint8_t              queue_count() const;
  ControlEvent         dequeue_event();
  void                 set_encoder(uint8_t val); // try to get rid of this
  void                 poll();
private:
  virtual void         impl_setup() = 0;
  virtual uint8_t      impl_queue_count() const = 0;
  virtual ControlEvent impl_dequeue_event() = 0;
  virtual void         impl_set_encoder(uint8_t val) = 0; // try to get rid of this
  virtual void         impl_poll() = 0;
};

#endif
