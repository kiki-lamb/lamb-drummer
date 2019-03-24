#ifndef SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H
#define SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H

#include "Arduino.h"
#include "track_state.h"
#include "i_buttonpad.h"

class ControlBoundTrackState : public TrackState {
 public:
	ControlBoundTrackState(
      uint8_t _mod_maj = 0, 
      uint8_t _mod_min = 1, 
      uint8_t _phase_min = 0,
      uint8_t _phase_maj = 0 
  );
  
	~ControlBoundTrackState();

	bool handle_button(IButtonpad::Button button);

 private:
  void increase_mod_maj();
  void decrease_mod_maj();
  void increase_mod_min();
  void decrease_mod_min();
  void increase_phase_maj();
  void decrease_phase_maj();
  void increase_phase_min();
  void decrease_phase_min(); 

  typedef void (ControlBoundTrackState::*button_handler)();
  static button_handler button_handlers[8];

};

#endif

