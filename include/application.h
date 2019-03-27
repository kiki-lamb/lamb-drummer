#ifndef SHELF_CLOCK_APPLICATION_H
#define SHELF_CLOCK_APPLICATION_H

#include "Arduino.h"
#include "buttonpad_resistor_ladder.h"
#include "buttonpad_pcf8574.h"
#include "track_event_processor.h"
#include "track_collection.h"
#include "controls.h"
#include "eeprom_.h"
#include "timer1.h"
#include "timer2.h"
#include "ui_data.h"
#include "ui.h"

class Application {
public:
  static const    size_t           track_count = 3;
  typedef TrackCollection<track_count>
                                   tracks_t;
private:
  Application();
  ~Application();
  ////////////////////////////////////////////////////////////////////////////////
  typedef Buttonpad_PCF8754<0x3F>         buttonpad_t;
  typedef PolledEventSource<ControlEvent> controls_t;
  typedef UiData<tracks_t>                ui_data_t;
  typedef Ui<ui_data_t>                   ui_t;
////////////////////////////////////////////////////////////////////////////////
  static          controls_t *     controls;
  static          ui_t             ui;
  static          ui_data_t        ui_data;
  static          Eeprom           eeprom;
  static          Timer1_          timer1;
  static          Timer2_          timer2;
  static          tracks_t         _tracks;
  static          void             restore_state();
  static          void             set_playback_state(bool playback_state_);
  static          bool             process_control(controls_t::event_t e);
  static          void             update_ui_data();
  static          uint8_t          page();
  static          uint8_t          bpm();
public:
  static          void             save_state();
  static          void             setup();
  static          void             loop();
  static          void             process_controls();
  static          void             flag_main_screen();
  static          tracks_t const & tracks();
};

#endif
