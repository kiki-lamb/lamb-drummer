#include "track_state_control_binding.h"

TrackStateButtonProcessor::TrackStateButtonProcessor() {}

TrackStateButtonProcessor::~TrackStateButtonProcessor() {}

    
bool TrackStateButtonProcessor::handle_button(TrackState & that, IButtonpad::Button button) {
  if (button < 8) {   
    (*button_handlers[button])(that);
    return true;
   }
  else {
    ;
    Serial.print(F("TrackState got unrecognized button: "));
    Serial.println(button);
  }
  return false;
}

void TrackStateButtonProcessor::increase_mod_maj(TrackState & that) {
  Serial.println(F("Do BTN_MAJ_UP"));
  if (that.mod_maj() <= 32)
    that.set_mod_maj( that.mod_maj() << 1);
}

void TrackStateButtonProcessor::decrease_mod_maj(TrackState & that) {
  Serial.println(F("Do BTN_MAJ_DOWN"));
  if (that.mod_maj() >= 2)
    that.set_mod_maj( that.mod_maj() >> 1);
  
  if (that.phase_maj() >=
      that.mod_maj())
    that.set_phase_maj( 0 );

  if (that.mod_min() >
      that.mod_maj())
    that.set_mod_min( that.mod_maj() );

  if (that.phase_min() >=
      that.mod_min())
    that.set_phase_min( 0 );
}

void TrackStateButtonProcessor::increase_mod_min(TrackState & that) {
  Serial.println(F("Do BTN_MIN_UP"));
  if (that.mod_min() < 
      that.mod_maj() 
     )
    that.set_mod_min( that.mod_min() + 1 );
}

void TrackStateButtonProcessor::decrease_mod_min(TrackState & that) {
  Serial.println(F("Do BTN_MIN_DOWN"));
  if (that.mod_min() > 1)
    that.set_mod_min( that.mod_min()-1 );

  if (that.phase_min() >=
      that.mod_min())
    that.set_phase_min( 0 );
}

void TrackStateButtonProcessor::increase_phase_maj(TrackState & that) {
  Serial.println(F("Do BTN_phase_MAJ_UP"));
  if (that.phase_maj() < that.mod_maj() - 1)
    that.set_phase_maj( that.phase_maj() + 1);
  else if (that.phase_maj() ==
      (that.mod_maj() - 1)
      ) 
    that.set_phase_maj( 0 );
}

void TrackStateButtonProcessor::decrease_phase_maj(TrackState & that) {
  Serial.println(F("Do BTN_phase_MAJ_DOWN"));
  if (that.phase_maj() > 0)
    that.set_phase_maj( that.phase_maj() - 1);
  else if (that.phase_maj() == 0)
    that.set_phase_maj( that.mod_maj() - 1);
}

void TrackStateButtonProcessor::increase_phase_min(TrackState & that) {
  Serial.println(F("Do BTN_phase_MIN_UP"));
  if (that.phase_min() < 
    (that.mod_min() - 1)
  )
    that.set_phase_min( that.phase_min() + 1);
  else if (that.phase_min() == (that.mod_min() - 1)) 
    that.set_phase_min( 0 );
}

void TrackStateButtonProcessor::decrease_phase_min(TrackState & that) {
  Serial.println(F("Do BTN_PHASE_MIN_DOWN"));
  if (that.phase_min() > 0)
    that.set_phase_min( that.phase_min() - 1);
  else if (that.phase_min() == 0)
    that.set_phase_min( that.mod_min() - 1);
}

TrackStateButtonProcessor::button_handler TrackStateButtonProcessor::button_handlers[8] = {
  &TrackStateButtonProcessor::increase_mod_maj,
  &TrackStateButtonProcessor::increase_phase_maj, 
  &TrackStateButtonProcessor::increase_mod_min,
  &TrackStateButtonProcessor::increase_phase_min,
  &TrackStateButtonProcessor::decrease_mod_maj,
  &TrackStateButtonProcessor::decrease_phase_maj,    
  &TrackStateButtonProcessor::decrease_mod_min,
  &TrackStateButtonProcessor::decrease_phase_min,
};  

