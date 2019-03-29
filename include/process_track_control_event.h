#ifndef SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H
#define SHELF_CLOCK_TRACK_STATE_CONTROL_BINDING_H

#include "Arduino.h"
#include "track/track.h"
#include "buttonpads/buttonpad.h"

template <class event_type_t, size_t handlers_count_>
class ProcessTrackControl {
public:
  static void apply(Track & that, event_type_t e) {
      (*button_handlers[e])(that);
  }

private:
  ProcessTrackControl() {}

  virtual ~ProcessTrackControl() {}

  static void increase_mod_maj(Track & that) {
    //Serial.println(F("Do BTN_MAJ_UP"));
    if (that.mod_maj() <= 32)
      that.set_mod_maj( that.mod_maj() << 1);
  }

  static void decrease_mod_maj(Track & that) {
    //Serial.println(F("Do BTN_MAJ_DOWN"));
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
    //Serial.println(F("Do BTN_MIN_UP"));
    if (that.mod_min() <
        that.mod_maj()
       )
      that.set_mod_min( that.mod_min() + 1 );
  }

  static void decrease_mod_min(Track & that) {
    //Serial.println(F("Do BTN_MIN_DOWN"));
    if (that.mod_min() > 1)
      that.set_mod_min( that.mod_min()-1 );

    if (that.phase_min() >=
        that.mod_min())
      that.set_phase_min( 0 );
  }

  static void increase_phase_maj(Track & that) {
    //Serial.println(F("Do BTN_PHASE_MAJ_UP"));
    if (that.phase_maj() < that.mod_maj() - 1)
      that.set_phase_maj( that.phase_maj() + 1);
    else if (that.phase_maj() ==
        (that.mod_maj() - 1)
        )
      that.set_phase_maj( 0 );
  }

  static void decrease_phase_maj(Track & that) {
    //Serial.println(F("Do BTN_PHASE_MAJ_DOWN"));
    if (that.phase_maj() > 0)
      that.set_phase_maj( that.phase_maj() - 1);
    else if (that.phase_maj() == 0)
      that.set_phase_maj( that.mod_maj() - 1);
  }

  static void increase_phase_min(Track & that) {
    //Serial.println(F("Do BTN_phase_MIN_UP"));
    if (that.phase_min() <
      (that.mod_min() - 1)
    )
      that.set_phase_min( that.phase_min() + 1);
    else if (that.phase_min() == (that.mod_min() - 1))
      that.set_phase_min( 0 );
  }

  static void decrease_phase_min(Track & that) {
    //Serial.println(F("Do BTN_PHASE_MIN_DOWN"));
    if (that.phase_min() > 0)
      that.set_phase_min( that.phase_min() - 1);
    else if (that.phase_min() == 0)
      that.set_phase_min( that.mod_min() - 1);
  }

  typedef void (*button_handler)(Track &);
  static button_handler button_handlers[handlers_count_];
};

// template <class event_type_t, size_t hc>
// typename ProcessTrackControl<event_type_t, hc>::button_handler
// ProcessTrackControl<event_type_t, hc>::button_handlers[hc] = {
template <>
typename ProcessTrackControl<EventType, 8>::button_handler
ProcessTrackControl<EventType, 8>::button_handlers[8] = {
  &ProcessTrackControl::increase_mod_min,
  &ProcessTrackControl::decrease_mod_min,
  &ProcessTrackControl::increase_mod_maj,
  &ProcessTrackControl::decrease_mod_maj,
  &ProcessTrackControl::increase_phase_min,
  &ProcessTrackControl::decrease_phase_min,
  &ProcessTrackControl::increase_phase_maj,
  &ProcessTrackControl::decrease_phase_maj,
};

#endif
