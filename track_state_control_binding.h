#ifndef SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H
#define SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H

#include "Arduino.h"
#include "track_state.h"
#include "i_buttonpad.h"

class TrackStateButtonProcessor {
 public:	
	static bool handle_button(TrackState & that, IButtonpad::Button button);

 private:
  TrackStateButtonProcessor();
  ~TrackStateButtonProcessor();

  static void increase_mod_maj(TrackState & that);
  static void decrease_mod_maj(TrackState & that);
  static void increase_mod_min(TrackState & that);
  static void decrease_mod_min(TrackState & that);
  static void increase_phase_maj(TrackState & that);
  static void decrease_phase_maj(TrackState & that);
  static void increase_phase_min(TrackState & that);
  static void decrease_phase_min(TrackState & that); 

  typedef void (*button_handler)(TrackState &);
  static button_handler button_handlers[8];

};

#endif

