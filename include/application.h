#ifndef LAMB_DRUMMER_APPLICATION_H
#define LAMB_DRUMMER_APPLICATION_H

#include "Arduino.h"
#include "track_collection/track_collection.h"
#include "ui_data/ui_data.h"
#include "ui/ui.h"
#include "eeprom/eeprom_.h"
#include "timers/timer1.h"
#include "timers/timer2.h"
#include "event_sources/combine_event_sources.h"
#include "event_sources/buffer_event_source.h"
#include "buttonpads/buttonpad_resistor_ladder.h"
#include "buttonpads/buttonpad_mcp23017.h"
#include "event/event.h"
#include <jm_PCF8574.h>

class Application {
private:
  static  const size_t  tracks_count = 3;
  static  const uint8_t encBtn = D7;
  static  const uint8_t encA = A0;
  static  const uint8_t encB = A1;

public:
  typedef TrackCollection<tracks_count>
                       tracks_t; // Public because tracks() returns it.
private:
  Application();
  ~Application();
  typedef UiData<tracks_t>
                       ui_data_t;
  typedef Ui<ui_data_t>
                       ui_t;
  typedef BufferEventSource<Event,8>
                       control_event_source_t;
  static  control_event_source_t
                       control_event_source;
  static  tracks_t     _tracks;
  static  ui_data_t    ui_data;
  static  ui_t         ui;
  static  Eeprom       eeprom;
  static  Timer1_      timer1;
  static  Timer2_      timer2;
  static  lamb::Flag   controls_flag;
  static  lamb::Flag   output_flag;
  static  jm_PCF8574   output_device;
  static  uint8_t      queued_output;  
  static  void         setup_controls(uint8_t bpm);
  static  void         set_playback_state(bool playback_state_);
  static  bool         process_control_event(control_event_source_t::event_t e);
  static  void         update_ui_data();
  static  uint8_t      page();
  static  void         process_control_events(); // called by ISR for timer2.
public:
  static  void         print_bits(uint8_t t0);
  static  void         setup();
  static  void         loop();
  static  void         save_state();             // called by ISR for timer2.
  static  void         flag_main_screen();       // called by ISR for timer1.
  static  void         flag_controls();       // called by ISR for timer2.
  static  void         flag_output(uint8_t output);       // called by ISR for timer1.
  static  constexpr tracks_t const &             // called by ISR for timer1.
                       tracks()  {
    return _tracks;
  }
};

#endif
