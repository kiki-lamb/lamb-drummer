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
#include "button_pads/button_pad_mcp23017.h"
#include "event/event.h"
#include <jm_PCF8574.h>

class application {
private:
  static  const size_t                   tracks_count = 3;
  static  const uint8_t                  encA = A0;
  static  const uint8_t                  encB = A1;
  static  const uint8_t                  encBtn = D7;

public:
  typedef track_collection<tracks_count> tracks_t;

private:
  typedef ui_data<tracks_t>              ui_data_t;
  typedef ui<ui_data_t>                  ui_t;
  typedef buffer_event_source<event,8>   control_event_source_t;
  static  Adafruit_MCP23017              x0x_leds;
  static  eeprom_                        eeprom;
  static  timer1_                        timer1;
  static  timer2_                        timer2;
  static  control_event_source_t         control_event_source;
  static  jm_PCF8574                     trigger_outputs;
  static  lamb::flag                     controls_flag;
  static  lamb::flag                     output_flag;
  static  lamb::flag                     x0x_leds_flag;
  static  lamb::flag                     update_ui_data_flag;  
  static  tracks_t                       _tracks;
  static  ui_data_t                      ui_data_;
  static  ui_t                           ui_;
  static  uint16_t                       x0x_leds_values_;
  static  uint8_t                        queued_output;  

private:
  ~application();  
  application();

  static  bool         output();
  static  bool         process_control_event(control_event_source_t::event_t e);
  static  bool         process_control_events(); // called by ISR for timer2.
  static  uint8_t      page();
  static  void         set_playback_state(bool playback_state_);
  static  void         setup_controls(uint8_t bpm);
  static  void         setup_trigger_outputs();
  static  void         setup_x0x_leds();
  static  void         update_x0x_leds();
  static  uint16_t     x0x_leds_values();
  static  void         write_x0x_leds(uint16_t const & value);
  
public:
  static  void         update_ui_data(bool force = false);
  static  uint16_t     flip_bytes(uint16_t value);
  static  void         flag_controls();       // called by ISR for timer2.
  static  void         flag_update_ui_data();       //
  static  void         flag_main_screen();       // called by ISR for timer1.
  static  void         flag_output(uint8_t output);       // called by ISR for timer1.
  static  void         loop();
  static  void         print_bits(uint8_t t0);
  static  void         print_bits_16(uint16_t t0);
  static  void         save_state();             // called by ISR for timer2.
  static  void         setup();
  static  void         write_x0x_leds_xor(uint16_t const & value);
  static  constexpr tracks_t const &             // called by ISR for timer1.
                       tracks()  {
    return _tracks;
  }
};

#endif
