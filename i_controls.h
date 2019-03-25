#ifndef SHELF_CLOCK_I_CONTROLS_H
#define SHELF_CLOCK_I_CONTROLS_H

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
  
  virtual void setup() = 0;
  virtual uint8_t queue_count() const = 0;
  virtual ControlEvent dequeue_event() = 0;
  virtual void set_encoder(uint8_t val) = 0; // try to get rid of this
  virtual void poll() = 0;
};

#endif
