#ifndef LAMB_DRUMMER_APPLICATION_H
#define LAMB_DRUMMER_APPLICATION_H

#include "Arduino.h"
#include "track_collection/track_collection.h"
#include "trigger_outputs/trigger_outputs.h"
#include "ui/ui.h"
#include "ui_data/ui_data.h"
#include "x0x_leds/x0x_leds.h"
#include "events/application.h"
#include "events/control.h"
#include "events/sources/buffer.h"
#include "events/sources/button_pad.h"
#include "events/sources/encoder_pad.h"
#include "events/sources/combine.h"
#include "controls/button_pad_mcp23017.h"
#include "controls/encoder_pad_mcp23017.h"
#include "timers/timer1.h"
#include "timers/timer2.h"
#include "eeprom/eeprom_.h"
#include <jm_PCF8574.h>

class application {
public:
  static  const uint8_t          tracks_count                     = 3;

  static  const uint8_t          combo_pad_buttons_count          = 8;
  static  const uint8_t          combo_pad_buttons_range_start    = 0;
  static  const uint8_t          combo_pad_buttons_source_mask    = 128;
  
  static  const uint8_t          combo_pad_encoders_count         = 4;
  static  const uint8_t          combo_pad_encoders_range_start   = 8;
  static  const uint8_t          combo_pad_encoders_source_mask   = 128;
  
  static  const uint8_t          drum_pad_buttons_count           = 16;
  static  const uint8_t          drum_pad_buttons_range_start     = 0;
  static  const uint8_t          drum_pad_buttons_source_mask     = 64;
  
  static  const uint8_t          encoder_pad_encoders_count       = 8;
  static  const uint8_t          encoder_pad_encoders_range_start = 0;
  static  const uint8_t          encoder_pad_source_mask          = 64;
  
  static  const uint8_t          event_sources_count              = 4;
  
  static  const uint8_t          combo_pad_addr                   = 0x0;
  static  const uint8_t          drum_pad_addr                    = 0x3;
  static  const uint8_t          encoder_pad_addr                 = 0x5;
  static  const uint8_t          x0x_leds_addr                    = 0x4;
  static  const uint8_t          trigger_outputs_addr             = 0x3a;
  
  typedef ::track_collection<tracks_count>                               track_collection;
  typedef ::ui_data<track_collection>                                    ui_data;
  typedef ::ui<ui_data>                                                  ui;
  typedef eeprom_::PersistantData<track_collection>                      persistant_data;
  typedef events::application                                            application_event;
  typedef events::control                                                control_event;  
  typedef events::sources::buffer<events::control, 8>                    control_source;
  typedef events::sources::button_pad<button_pad_mcp23017>               button_pad_source;
  typedef events::sources::combine<events::control, event_sources_count> combined_source;
  typedef events::sources::encoder_pad<encoder_pad_mcp23017>             encoder_pad_source;

  static  ::x0x_leds & x0x_leds();
  static  ::trigger_outputs & trigger_outputs();
  
private:
  static  encoder_pad_mcp23017                                           _combo_pad_encoder_pad;
  static  encoder_pad_mcp23017                                           _encoder_pad0;
  static  button_pad_mcp23017                                            _combo_pad_button_pad;
  static  button_pad_mcp23017                                            _drum_pad_button_pad;
  static  encoder_pad_source                                             _encoder_pad_source0;
  static  encoder_pad_source                                             _encoder_pad_source1;
  static  encoder_pad_source                                             _combo_pad_encoder_source;
  static  button_pad_source                                              _combo_pad_button_source;
  static  button_pad_source                                              _drum_pad_source;
  static  combined_source                                                _combine_event_sources;
  static  ::trigger_outputs                                              _trigger_outputs;  
  static  ::x0x_leds                                                     _x0x_leds;
  static  Adafruit_MCP23017                                              _x0x_leds_device;
  static  Adafruit_MCP23017                                              _drum_pad_device;
  static  Adafruit_MCP23017                                              _combo_pad_device;
  static  Adafruit_MCP23017                                              _encoder_pad_device;
  static  control_source                                                 _control_event_source;
  static  eeprom_                                                        _eeprom;
  static  jm_PCF8574                                                     _trigger_outputs_device;
  static  lamb::flag                                                     _controls_flag;
  static  lamb::flag                                                     _output_flag;
  static  timer1_                                                        _timer1;
  static  timer2_                                                        _timer2;
  static  track_collection                                               _tracks;
  static  ui_data                                                        _ui_data;
  static  ui                                                             _ui;

                      application();
                      ~application();
  static bool         process_application_event(
    control_source::event_type e
  );
  static bool         process_application_events(); // called by ISR for timer2.
  static void         set_playback_state(bool const & playback_state_);
  static void         setup_controls();
  static void         setup_trigger_outputs();
  static void         update_ui_data();
  static application_event
                      convert_control_event(
                        events::control const & control_event
                      );
public:
  static uint8_t      page();
  static void         flag_controls();       // called by ISR for timer2.
  static void         flag_main_screen();    // called by ISR for timer1.
  void                flag_update_ui_data();
  static void         loop();
  static void         save_state();          // called by ISR for timer2.
  static void         setup();
  static constexpr track_collection const &          // called by ISR for timer1.
                      tracks()  {
    return _tracks;
  }
};

#endif

/* Local Variables:  */
/* fill-column: 100  */
/* End:              */
