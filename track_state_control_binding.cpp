#include "track_state_control_binding.h"

ControlBoundTrackState::ControlBoundTrackState(
      uint8_t _mod_maj   = 0, 
      uint8_t _mod_min   = 1, 
      uint8_t _phase_min = 0,      
      uint8_t _phase_maj = 0      
    ) : TrackState(_mod_maj, _mod_min, _phase_min, _phase_maj) {}

ControlBoundTrackState::~ControlBoundTrackState() {}

ControlBoundTrackState::button_handler ControlBoundTrackState::button_handlers[8] = {
  &ControlBoundTrackState::increase_mod_maj,
  &ControlBoundTrackState::increase_phase_maj, 
  &ControlBoundTrackState::increase_mod_min,
  &ControlBoundTrackState::increase_phase_min,
  &ControlBoundTrackState::decrease_mod_maj,
  &ControlBoundTrackState::decrease_phase_maj,    
  &ControlBoundTrackState::decrease_mod_min,
  &ControlBoundTrackState::decrease_phase_min,
};  
    
bool ControlBoundTrackState::handle_button(IButtonpad::Button button) {
  if (button < 8) {   
    (this->*button_handlers[button])();
    return true;
   }
  else {
    ;
    Serial.print(F("ControlBoundTrackState got unrecognized button: "));
    Serial.println(button);
  }
  return false;
}

void ControlBoundTrackState::increase_mod_maj() {
  Serial.println(F("Do BTN_MAJ_UP"));
  if (mod_maj() <= 32)
    set_mod_maj( mod_maj() << 1);
}

void ControlBoundTrackState::decrease_mod_maj() {
  Serial.println(F("Do BTN_MAJ_DOWN"));
  if (mod_maj() >= 2)
    set_mod_maj( mod_maj() >> 1);
  
  if (phase_maj() >=
      mod_maj())
    set_phase_maj( 0 );

  if (mod_min() >
      mod_maj())
    set_mod_min( mod_maj() );

  if (phase_min() >=
      mod_min())
    set_phase_min( 0 );
}

void ControlBoundTrackState::increase_mod_min() {
  Serial.println(F("Do BTN_MIN_UP"));
  if (mod_min() < 
      mod_maj() 
     )
    set_mod_min( mod_min() + 1 );
}

void ControlBoundTrackState::decrease_mod_min() {
  Serial.println(F("Do BTN_MIN_DOWN"));
  if (mod_min() > 1)
    set_mod_min( mod_min()-1 );

  if (phase_min() >=
      mod_min())
    set_phase_min( 0 );
}

void ControlBoundTrackState::increase_phase_maj() {
  Serial.println(F("Do BTN_PHASE_MAJ_UP"));
  if (phase_maj() < mod_maj() - 1)
    set_phase_maj( phase_maj() + 1);
  else if (phase_maj() ==
      (mod_maj() - 1)
      ) 
    set_phase_maj( 0 );
}

void ControlBoundTrackState::decrease_phase_maj() {
  Serial.println(F("Do BTN_PHASE_MAJ_DOWN"));
  if (phase_maj() > 0)
    set_phase_maj( phase_maj() - 1);
  else if (phase_maj() == 0)
    set_phase_maj( mod_maj() - 1);
}

void ControlBoundTrackState::increase_phase_min() {
  Serial.println(F("Do BTN_PHASE_MIN_UP"));
  if (phase_min() < 
    (mod_min() - 1)
  )
    set_phase_min( phase_min() + 1);
  else if (phase_min() == (mod_min() - 1)) 
    set_phase_min( 0 );
}

void ControlBoundTrackState::decrease_phase_min() {
  Serial.println(F("Do BTN_PHASE_MIN_DOWN"));
  if (phase_min() > 0)
    set_phase_min( phase_min() - 1);
  else if (phase_min() == 0)
    set_phase_min( mod_min() - 1);
}

