#ifndef LAMB_DRUMMER_APPLICATION_H
#define LAMB_DRUMMER_APPLICATION_H

#include "lamb.h"
#include "Arduino.h"
#include <jm_PCF8574.h>
#include "track_collection/track_collection.h"
#include "ui/ui.h"
#include "ui_data/ui_data.h"
#include "outputs/triggers/triggers.h"
#include "outputs/x0x_leds/x0x_leds.h"
#include "events/application.h"
#include "events/control.h"
#include "timers/timer1.h"
#include "timers/timer2.h"
#include "eeprom/eeprom.h"
#include "tracks/x0x.h"
#include "tracks/euclidean.h"

class application {
public:
  static  const uint8_t            tracks_count                     = 6;
  static  const uint8_t            bars_count                       = 2;

  static  const uint8_t            combo_pad_buttons_count          = 8;
  static  const uint8_t            combo_pad_buttons_range_start    = 0;
  static  const uint8_t            combo_pad_buttons_source_mask    = 128;
  
  static  const uint8_t            combo_pad_encoders_count         = 4;
  static  const uint8_t            combo_pad_encoders_range_start   = 8;
  static  const uint8_t            combo_pad_encoders_source_mask   = 128;
  
  static  const uint8_t            drum_pad_buttons_count           = 16;
  static  const uint8_t            drum_pad_buttons_range_start     = 0;
  static  const uint8_t            drum_pad_buttons_source_mask     = 64;
  
  static  const uint8_t            encoder_pad_encoders_count       = 8;
  static  const uint8_t            encoder_pad_encoders_range_start = 0;
  static  const uint8_t            encoder_pad_source_mask          = 64;
  
  static  const uint8_t            event_sources_count              = 4;
  
  static  const uint8_t            combo_pad_addr                   = 0x0;
  static  const uint8_t            drum_pad_addr                    = 0x3;
  static  const uint8_t            encoder_pad_addr                 = 0x5;
  static  const uint8_t            x0x_leds_addr                    = 0x4;
  static  const uint8_t            triggers_addr                    = 0x3a;

#ifdef XOX
  typedef tracks::x0x                                     track;
#else
  typedef tracks::euclidean                               track;
#endif  

  typedef ::track_collection<tracks_count, track>         track_collection;
  typedef ::ui_data<track_collection>                     ui_data;
  typedef ::ui<ui_data>                                   ui;
  typedef eeprom::PersistentData<track_collection>        persistent_data;
  typedef events::application                             application_event;
  typedef events::control                                 control_event;  
  typedef application_event::event_type                   application_event_type;
  typedef control_event::event_type                       control_event_type;
  typedef lamb::events::sources::buffer<control_event, 8> control_source;
  typedef lamb::controls::mcp23017_encoders               encoders;
  typedef lamb::controls::mcp23017_buttons                buttons;
  
  typedef lamb::events::sources::buttons<
    buttons,
    control_event,
    control_event_type::EVT_BUTTON>                       buttons_source;  

  typedef lamb::events::sources::encoders<
    encoders,
    control_event,
    control_event_type::EVT_ENCODER>                      encoders_source;

  typedef lamb::events::sources::combine<
    control_event,
    event_sources_count>                                  combined_source;
  
private:
  static  encoders                                 _combo_pad_encoder_pad;
  static  encoders                                 _encoder_pad0;
  static  buttons                                  _combo_pad_button_pad;
  static  buttons                                  _drum_pad_button_pad;
  static  encoders_source                          _encoder_pad_source0;
  static  encoders_source                          _combo_pad_encoder_source;
  static  buttons_source                           _combo_pad_button_source;
  static  buttons_source                           _drum_pad_source;
  static  combined_source                          _combine_event_sources;
  static  outputs::triggers                        _triggers;  
  static  outputs::x0x_leds                        _x0x_leds;
  static  Adafruit_MCP23017                        _x0x_leds_device;
  static  Adafruit_MCP23017                        _drum_pad_device;
  static  Adafruit_MCP23017                        _combo_pad_device;
  static  Adafruit_MCP23017                        _encoder_pad_device;
  static  control_source                           _control_event_source;
  static  eeprom                                   _eeprom;
  static  jm_PCF8574                               _triggers_device;
  static  lamb::flag                               _controls_flag;
  static  timer1                                   _timer1;
  static  timer2                                   _timer2;
  static  track_collection                         _tracks;
  static  ui_data                                  _ui_data;
  static  ui                                       _ui;

                                   application();
  static bool                      process_control_events(); // called by ISR for timer2.
  static void                      set_playback_state(bool const & playback_state_);
  static void                      setup_controls();
  static void                      setup_triggers();
  static void                      update_ui_data();
  static bool                      enqueue_data_to_save();
  static bool                      update_screen();
  
  static application_event         process_control_event(
    control_event const & control_event
  );

  static application_event         process_button_event(
    control_event const & control_event
  );

  static application_event         process_encoder_event(
    control_event const & control_event
  );

  static bool                      process_application_event(
    application_event application_event
  );
  
public:
  static outputs::x0x_leds &       x0x_leds();
  static outputs::triggers &       triggers();  
  static uint8_t                   bar();
  static void                      flag_controls();     // called by ISR for timer2.
  static void                      flag_main_screen();  // called by ISR for timer1.
  static void                      loop();
  static void                      flag_save_state();        // called by ISR for timer2.
  static void                      setup();
  static track_collection &        tracks();
};

#endif

/* Local Variables:  */
/* fill-column: 100  */
/* End:              */
