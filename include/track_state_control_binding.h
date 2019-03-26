#ifndef SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H
#define SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H

#include "Arduino.h"
#include "track_state.h"
#include "i_buttonpad.h"
#include "controls.h"

template <class controls_t>
class TrackStateEventProcessor {
 public:	
   static bool handle_event(TrackState & that, typename controls_t::ControlEvent e) {
      if (e.type < 8) {   
        (*button_handlers[e.type])(that);
        return true;
       }
      else {
        ;
        Serial.print(F("TrackState got unrecognized event: "));
        Serial.println(e.type);
      }
      
      return false;
   }
   
 private:
   TrackStateEventProcessor() {}
    
   ~TrackStateEventProcessor() {}
        
   static void increase_mod_maj(TrackState & that) {
      Serial.println(F("Do BTN_MAJ_UP"));
      if (that.mod_maj() <= 32)
        that.set_mod_maj( that.mod_maj() << 1);
    }
    
   static void decrease_mod_maj(TrackState & that) {
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
    
    static void increase_mod_min(TrackState & that) {
      Serial.println(F("Do BTN_MIN_UP"));
      if (that.mod_min() < 
          that.mod_maj() 
         )
        that.set_mod_min( that.mod_min() + 1 );
    }
    
    static void decrease_mod_min(TrackState & that) {
      Serial.println(F("Do BTN_MIN_DOWN"));
      if (that.mod_min() > 1)
        that.set_mod_min( that.mod_min()-1 );
    
      if (that.phase_min() >=
          that.mod_min())
        that.set_phase_min( 0 );
    }
    
    static void increase_phase_maj(TrackState & that) {
      Serial.println(F("Do BTN_PHASE_MAJ_UP"));
      if (that.phase_maj() < that.mod_maj() - 1)
        that.set_phase_maj( that.phase_maj() + 1);
      else if (that.phase_maj() ==
          (that.mod_maj() - 1)
          ) 
        that.set_phase_maj( 0 );
    }
    
    static void decrease_phase_maj(TrackState & that) {
      Serial.println(F("Do BTN_PHASE_MAJ_DOWN"));
      if (that.phase_maj() > 0)
        that.set_phase_maj( that.phase_maj() - 1);
      else if (that.phase_maj() == 0)
        that.set_phase_maj( that.mod_maj() - 1);
    }
    
    static void increase_phase_min(TrackState & that) {
      Serial.println(F("Do BTN_phase_MIN_UP"));
      if (that.phase_min() < 
        (that.mod_min() - 1)
      )
        that.set_phase_min( that.phase_min() + 1);
      else if (that.phase_min() == (that.mod_min() - 1)) 
        that.set_phase_min( 0 );
    }
    
    static void decrease_phase_min(TrackState & that) {
      Serial.println(F("Do BTN_PHASE_MIN_DOWN"));
      if (that.phase_min() > 0)
        that.set_phase_min( that.phase_min() - 1);
      else if (that.phase_min() == 0)
        that.set_phase_min( that.mod_min() - 1);
    }

    typedef void (*button_handler)(TrackState &);
    static button_handler button_handlers[8];
};

template <class controls_t> typename TrackStateEventProcessor<controls_t>::button_handler TrackStateEventProcessor<controls_t>::button_handlers[8] = {
  &TrackStateEventProcessor::increase_mod_min,
  &TrackStateEventProcessor::decrease_mod_min,
  &TrackStateEventProcessor::increase_mod_maj,
  &TrackStateEventProcessor::decrease_mod_maj,
  &TrackStateEventProcessor::increase_phase_min,
  &TrackStateEventProcessor::decrease_phase_min,
  &TrackStateEventProcessor::increase_phase_maj, 
  &TrackStateEventProcessor::decrease_phase_maj,    
};  

#endif

