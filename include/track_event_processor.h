#ifndef SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H
#define SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H

#include "Arduino.h"
#include "track.h"
#include "i_buttonpad.h"
#include "controls.h"

template <class controls_t>
class TrackEventProcessor {
public:
  static bool handle_event(Track & that, typename controls_t::event_t e) {
    if (e.type < 8) {
      (*button_handlers[e.type])(that);
      return true;
     }
    else {
      ;
      Serial.print(F("Track got unrecognized event: "));
      Serial.println(e.type);
    }

    return false;
  }

private:
  TrackEventProcessor() {}
  ~TrackEventProcessor() {}

  static void increase_mod_maj(Track & that) {
    Serial.println(F("Do BTN_MAJ_UP"));
    if (that.mod_maj() <= 32)
      that.set_mod_maj( that.mod_maj() << 1);
  }

  static void decrease_mod_maj(Track & that) {
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

  static void increase_mod_min(Track & that) {
    Serial.println(F("Do BTN_MIN_UP"));
    if (that.mod_min() <
        that.mod_maj()
       )
      that.set_mod_min( that.mod_min() + 1 );
  }

  static void decrease_mod_min(Track & that) {
    Serial.println(F("Do BTN_MIN_DOWN"));
    if (that.mod_min() > 1)
      that.set_mod_min( that.mod_min()-1 );

    if (that.phase_min() >=
        that.mod_min())
      that.set_phase_min( 0 );
  }

  static void increase_phase_maj(Track & that) {
    Serial.println(F("Do BTN_PHASE_MAJ_UP"));
    if (that.phase_maj() < that.mod_maj() - 1)
      that.set_phase_maj( that.phase_maj() + 1);
    else if (that.phase_maj() ==
        (that.mod_maj() - 1)
        )
      that.set_phase_maj( 0 );
  }

  static void decrease_phase_maj(Track & that) {
    Serial.println(F("Do BTN_PHASE_MAJ_DOWN"));
    if (that.phase_maj() > 0)
      that.set_phase_maj( that.phase_maj() - 1);
    else if (that.phase_maj() == 0)
      that.set_phase_maj( that.mod_maj() - 1);
  }

  static void increase_phase_min(Track & that) {
    Serial.println(F("Do BTN_phase_MIN_UP"));
    if (that.phase_min() <
      (that.mod_min() - 1)
    )
      that.set_phase_min( that.phase_min() + 1);
    else if (that.phase_min() == (that.mod_min() - 1))
      that.set_phase_min( 0 );
  }

  static void decrease_phase_min(Track & that) {
    Serial.println(F("Do BTN_PHASE_MIN_DOWN"));
    if (that.phase_min() > 0)
      that.set_phase_min( that.phase_min() - 1);
    else if (that.phase_min() == 0)
      that.set_phase_min( that.mod_min() - 1);
  }

  typedef void (*button_handler)(Track &);
  static button_handler button_handlers[8];
};

template <class controls_t> typename TrackEventProcessor<controls_t>::button_handler TrackEventProcessor<controls_t>::button_handlers[8] = {
  &TrackEventProcessor::increase_mod_min,
  &TrackEventProcessor::decrease_mod_min,
  &TrackEventProcessor::increase_mod_maj,
  &TrackEventProcessor::decrease_mod_maj,
  &TrackEventProcessor::increase_phase_min,
  &TrackEventProcessor::decrease_phase_min,
  &TrackEventProcessor::increase_phase_maj,
  &TrackEventProcessor::decrease_phase_maj,
};

#endif
