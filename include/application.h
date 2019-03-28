#ifndef SHELF_CLOCK_APPLICATION_H
#define SHELF_CLOCK_APPLICATION_H

#include "Arduino.h"
#include "track_collection.h"
#include "ui_data.h"
#include "ui/ui.h"
#include "eeprom/eeprom_.h"
#include "timers/timer1.h"
#include "timers/timer2.h"
#include "event_sources/combine_event_sources.h"
#include "buttonpads/buttonpad_resistor_ladder.h"
#include "buttonpads/buttonpad_pcf8574.h"
#include "event/event.h"

class Application {
private:
  static  const size_t                   tracks_count = 3;
public:
  typedef TrackCollection<tracks_count>  tracks_t; // Public because tracks() returns it.
private:
  Application();
  ~Application();
  typedef UiData<tracks_t>               ui_data_t;
  typedef Ui<ui_data_t>                  ui_t;
  typedef CombineEventSources<Event,3,8> control_event_source_t;
private:
  static  tracks_t                       _tracks;
  static  ui_data_t                      ui_data;
  static  ui_t                           ui;
  static  control_event_source_t         control_event_source;
  static  Eeprom                         eeprom;
  static  Timer1_                        timer1;
  static  Timer2_                        timer2;
  static  void                           setup_controls(uint8_t bpm);
  static  void                           set_playback_state(bool playback_state_);
  static  bool                           process_control_event(control_event_source_t::event_t e);
  static  void                           update_ui_data();
  static  uint8_t                        page();
public:
  static  void                           setup();
  static  void                           loop();
  static  void                           process_control_events(); // called by ISR for timer2.
  static  void                           save_state();             // called by ISR for timer2.
  static  void                           flag_main_screen();       // called by ISR for timer1.
  static  constexpr tracks_t const &     tracks()  {               // called by ISR for time 1.
    return _tracks;
  }
};

#endif
