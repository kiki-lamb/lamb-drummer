#ifndef LAMB_DRUMMER_TRACK_STATE_CONTROL_BINDING_H
#define LAMB_DRUMMER_TRACK_STATE_CONTROL_BINDING_H

#include "Arduino.h"
#include "track/track.h"

template <class event_type_t, size_t handlers_count_>
class ProcessTrackControl {
public:
  static void apply(track & that, event_type_t e) {
      (*button_handlers[e])(that);
  }

private:
  ProcessTrackControl() {}

  /* virtual */ ~ProcessTrackControl() {}

  static void increase_mod_maj(track & that) {
    Serial.println(F("BMMU"));

    uint8_t tmm = that.mod_maj();
    bool    eq  = tmm == that.mod_min();
    
    if (tmm <= 32) {
      that.set_mod_maj(tmm << 1);

      if (eq) {
        that.set_mod_min(tmm << 1);
      }
    }
  }

  static void decrease_mod_maj(track & that) {
    Serial.println(F("BMMD"));
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

  static void increase_mod_min(track & that) {
    Serial.println(F("BMmU"));
    if (that.mod_min() <
        that.mod_maj()
       )
      that.set_mod_min( that.mod_min() + 1 );
  }

  static void decrease_mod_min(track & that) {
    Serial.println(F("BMmD"));
    if (that.mod_min() > 1)
      that.set_mod_min( that.mod_min()-1 );

    if (that.phase_min() >=
        that.mod_min())
      that.set_phase_min( 0 );
  }

  static void increase_phase_maj(track & that) {
    Serial.println(F("BPMU"));
    if (that.phase_maj() < that.mod_maj() - 1)
      that.set_phase_maj( that.phase_maj() + 1);
    else if (that.phase_maj() ==
        (that.mod_maj() - 1)
        )
      that.set_phase_maj( 0 );
  }

  static void decrease_phase_maj(track & that) {
    Serial.println(F("BPMD"));
    if (that.phase_maj() > 0)
      that.set_phase_maj( that.phase_maj() - 1);
    else if (that.phase_maj() == 0)
      that.set_phase_maj( that.mod_maj() - 1);
  }

  static void increase_phase_min(track & that) {
    Serial.println(F("BPmU"));
    if (that.phase_min() <
      (that.mod_min() - 1)
    )
      that.set_phase_min( that.phase_min() + 1);
    else if (that.phase_min() == (that.mod_min() - 1))
      that.set_phase_min( 0 );
  }

  static void decrease_phase_min(track & that) {
    Serial.println(F("BPmD"));
    if (that.phase_min() > 0)
      that.set_phase_min( that.phase_min() - 1);
    else if (that.phase_min() == 0)
      that.set_phase_min( that.mod_min() - 1);
  }

  typedef void (*button_handler)(track &);
  
  static button_handler button_handlers[handlers_count_];
};

template <>
typename ProcessTrackControl<events::application::event_type, 8>::button_handler
ProcessTrackControl<events::application::event_type, 8>::button_handlers[8] = {
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
