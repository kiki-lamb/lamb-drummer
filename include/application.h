#ifndef SHELF_CLOCK_APPLICATION_H
#define SHELF_CLOCK_APPLICATION_H

#include "Arduino.h"
#include "buttonpads/buttonpad_resistor_ladder.h"
#include "buttonpads/buttonpad_pcf8574.h"
#include "process_track_control_event.h"
#include "event_sources/control_source.h"
#include "timers/timer1.h"
#include "timers/timer2.h"
#include "eeprom/eeprom_.h"
#include "ui/ui.h"
#include "ui_data.h"
#include "track_collection.h"

class Application {
private:
  static const size_t      tracks_count = 3;
public:
  typedef TrackCollection<tracks_count> // Public because tracks() returns it.
                           tracks_t;
private:
  Application();
  ~Application();
  typedef Buttonpad_PCF8754<0x3F>
                           buttonpad_t;
  typedef UiData<tracks_t> ui_data_t;
  typedef Ui<ui_data_t>    ui_t;
  typedef PolledEventSource<Event>
                           control_event_source_t;
public:
  typedef ControlSource<buttonpad_t>
                           control_event_source_real_t;
  static control_event_source_real_t *
                           control_event_source;
private:
  static ui_t              ui;
  static ui_data_t         ui_data;
  static Eeprom            eeprom;
  static Timer1_           timer1;
  static Timer2_           timer2;
  static tracks_t          _tracks;
  static void              set_playback_state(bool playback_state_);
  static bool              process_control_event(control_event_source_t::event_t e);
  static void              update_ui_data();
  static uint8_t           page();
  static uint8_t           bpm();
public:
  static void              setup();
  static void              loop();
  static void              flag_main_screen(); // called by ISR for timer1.
  static constexpr tracks_t const &
                           tracks()  {         // called by ISR for time 1.
    return _tracks;
  }
  static void              process_control_events(); // called by ISR for timer2.
  static void              save_state();             // called by ISR for timer2.
};

#endif
