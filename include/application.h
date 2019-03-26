#ifndef SHELF_CLOCK_APPLICATION_H
#define SHELF_CLOCK_APPLICATION_H

#include "Arduino.h"
#include "buttonpad_resistor_ladder.h"
#include "buttonpad_pcf8574.h"
#include "track_state_control_binding.h"
#include "track_state_collection.h"
#include "controls.h"
#include "eeprom_.h"
#include "timer1.h"
#include "timer2.h"
#include "ui.h"

class Application {
public:
  static const    size_t           track_count = 3;
  typedef TrackStateCollection<track_count>
                                   tracks_t;

private:
  Application();
  ~Application();
  typedef Buttonpad_PCF8754<0x3F>  buttonpad_t;
  typedef Controls<buttonpad_t>    controls_t;
  static          IControls *      controls;
  static          Eeprom           eeprom;
  static          Timer1_          timer1;
  static          Timer2_          timer2;
  static          tracks_t         tracks;
  static          void             restore_state();
  static          void             set_playback_state(bool playback_state_);
  static          void             process_control(controls_t::ControlEvent & e);
  static          Ui::UiData<tracks_t>
                                   ui_data();

public:
  static          void             save_state();
  static          void             setup();
  static          void             loop();
  static          void             process_controls();
  static          uint8_t          page();
  // fwds to timer1:
  static          double           hz();
  static          uint8_t          bpm();
  static          uint8_t          ticker();
  static          bool             playback_state();
  // fwd to Ui:
  static          void             flag_main_screen();
  // fwd to tracks:
  static          tracks_t const & track_states();
};

#endif
