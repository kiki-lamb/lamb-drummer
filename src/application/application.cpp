#include "application/application.h"
#include "events/application.h"
#include "process_track_control_event.h"
#include "util/util.h"

////////////////////////////////////////////////////////////////////////////////

jm_PCF8574                    application::_triggers_device;
application::track_collection application::_tracks;
application::ui_data          application::_ui_data;
application::ui               application::_ui(&_ui_data);
eeprom                        application::_eeprom;
timer1                        application::_timer1;
timer2                        application::_timer2;
lamb::flag                    application::_controls_flag;
lamb::flag                    application::_output_flag;
outputs::x0x_leds             application::_x0x_leds;
outputs::triggers             application::_triggers;
Adafruit_MCP23017             application::_x0x_leds_device;
Adafruit_MCP23017             application::_combo_pad_device;
Adafruit_MCP23017             application::_drum_pad_device;
Adafruit_MCP23017             application::_encoder_pad_device;

////////////////////////////////////////////////////////////////////////////////

application::control_source  application::_control_event_source;

application::combined_source application::_combine_event_sources;

////////////////////////////////////////////////////////////////////////////////

encoder_pad_mcp23017   application::_combo_pad_encoder_pad(
                         application::combo_pad_encoders_count,
                         application::combo_pad_encoders_range_start
                       );

button_pad_mcp23017    application::_combo_pad_button_pad(
                         application::combo_pad_buttons_count,
                         application::combo_pad_buttons_range_start
                       );
////////////////////////////////////////////////////////////////////////////////

encoder_pad_mcp23017   application::_encoder_pad0(
                         application::encoder_pad_encoders_count,
                         application::encoder_pad_encoders_range_start
                       );

button_pad_mcp23017    application::_drum_pad_button_pad(
                         application::drum_pad_buttons_count,
                         application::drum_pad_buttons_range_start
                       );

application::encoder_pad_source
                       application::_encoder_pad_source0(
                         &application::_encoder_pad0,
                         application::encoder_pad_source_mask
                       );

application::encoder_pad_source
                       application::_combo_pad_encoder_source(
                         &application::_combo_pad_encoder_pad,
                         application::combo_pad_encoders_source_mask
                       );

application::button_pad_source
                       application::_combo_pad_button_source(
                         &application::_combo_pad_button_pad,
                         application::combo_pad_buttons_source_mask
                       );

application::button_pad_source
                       application::_drum_pad_source(
                         &application::_drum_pad_button_pad,
                         application::drum_pad_buttons_source_mask
                       );

////////////////////////////////////////////////////////////////////////////////

application::application() {};

////////////////////////////////////////////////////////////////////////////////

// application::~application() {};

////////////////////////////////////////////////////////////////////////////////

outputs::x0x_leds & application::x0x_leds() {
  return _x0x_leds;
}

////////////////////////////////////////////////////////////////////////////////

outputs::triggers & application::triggers() {
  return _triggers;
}

////////////////////////////////////////////////////////////////////////////////

void application::update_ui_data() {
  _ui_data.page           = page();
  _ui_data.bpm            = _timer1.bpm();
  _ui_data.millihz        = _timer1.millihz();
  _ui_data.playback_state = _timer1.playback_state();
  _ui_data.ticker         = _timer1.ticker();
}

////////////////////////////////////////////////////////////////////////////////

void application::setup() {
  Serial .begin(230400);

  Wire   .begin();
  Wire   .setClock(400000);

  _x0x_leds_device.begin(x0x_leds_addr);
  _x0x_leds.setup(&_x0x_leds_device);

  _triggers_device.begin(triggers_addr);
  _triggers.setup(&_triggers_device);
  
  _ui   .setup();
  _ui   .enter_screen(ui::SCREEN_INTRO);
  
  persistant_data tmp(
    &_tracks,
    _timer1.bpm(),
    _timer1.playback_state()
  );

  _eeprom .restore_all(tmp);

  setup_controls();
  
  cli();

  Serial.println(F("Stop all interrupts...")); Serial.flush();
  
  _timer1 .setup();
  _timer2 .setup();
  
  set_playback_state(tmp.playback_state);

  while (_tracks++);

  _eeprom .unflag_save_requested();
  _eeprom .flag_save_requested();

  save_state();
  
  _ui_data.tracks = &_tracks;

  update_ui_data();

  _timer1.set_bpm(tmp.bpm);

  sei();
  
  Serial.println(F("Enter SCREEN_MAIN...")); Serial.flush();

  _ui    .enter_screen(ui::SCREEN_MAIN);

  Serial.println(F("Entered SCREEN_MAIN.")); Serial.flush();
}

////////////////////////////////////////////////////////////////////////////////

void application::setup_controls() {
  _combo_pad_device     .begin(combo_pad_addr);
  _drum_pad_device      .begin(drum_pad_addr);
  _encoder_pad_device   .begin(encoder_pad_addr);

  Serial.println(F("\nInit drum buttons..."));
  _drum_pad_button_pad  .setup      ( &_drum_pad_device);
  _combine_event_sources.sources[0] = &_drum_pad_source;
  
  Serial.println(F("\nInit combo buttons..."));
  _combo_pad_button_pad .setup      ( &_combo_pad_device);
  _combine_event_sources.sources[1] = &_combo_pad_button_source;
  
  Serial.println(F("\nInit combo encoders..."));
  _combo_pad_encoder_pad.setup      ( &_combo_pad_device);
  _combine_event_sources.sources[2] = &_combo_pad_encoder_source;
  
  Serial.println(F("\nInit encoders..."));
  _encoder_pad0         .setup      ( &_encoder_pad_device);
  _combine_event_sources.sources[3] = &_encoder_pad_source0;

  Serial.println();
  
  _control_event_source .source     = &_combine_event_sources;
}

////////////////////////////////////////////////////////////////////////////////

void application::loop() {
  (
    _triggers.update() || 
    _x0x_leds.update()        ||
    
    _triggers.update() ||   
    process_control_events()  ||
    
    _triggers.update() ||
    (update_ui_data(), _ui.update_screen())
  );
}

////////////////////////////////////////////////////////////////////////////////

void application::flag_main_screen() {
  _ui.flag_screen(ui::SCREEN_MAIN);
}

////////////////////////////////////////////////////////////////////////////////

uint8_t application::page() {
  uint8_t max = 0;
  auto tracks = application::tracks();
  
  for (uint8_t ix = 0; ix < tracks.size(); ix++) {
    if (tracks[ix].mod_maj() > max) {
      max = tracks[ix].mod_maj();
    }
  }
  
  return ((_timer1.ticker() >> 1) % max) >> 4;
}

////////////////////////////////////////////////////////////////////////////////

void application::set_playback_state(bool const & playback_state_) {
  _timer1.set_playback_state(playback_state_);

  _ui_data.redraw_playback_state.set();

  flag_main_screen();

  _eeprom.flag_save_requested();
}

////////////////////////////////////////////////////////////////////////////////

void application::save_state() {
  _eeprom.save_all(
    persistant_data(
      &_tracks,
      _timer1.bpm(),
      _timer1.playback_state()
    )
  );
}

////////////////////////////////////////////////////////////////////////////////

void application::flag_controls() {
  _controls_flag.set();
}

////////////////////////////////////////////////////////////////////////////////

bool application::process_control_events() {
  if (! _controls_flag.consume())
    return false;

  _control_event_source.poll();

  while(
    process_application_event(
      process_control_event(
        _control_event_source.dequeue_event()
      )
    )
  );

  return true;
}

////////////////////////////////////////////////////////////////////////////////

application::application_event application::process_control_event(
  application::control_event const & control_event
) {
  application_event application_event;
  
  if (control_event.type == control_event::EVT_BUTTON) {
    uint8_t button_number = control_event.parameter >> 8;
    int8_t  button_state  = (int8_t)(control_event.parameter & 0xff);
      
    Serial.print("Button event, number: ");
    Serial.print(button_number);
    Serial.print(", state: ");
    Serial.print(button_state);
    Serial.println();
    
    if ((button_number >= 64) && (button_number <= 79)) { // Drum pad buttons
      application_event.type = (application_event::event_type)(
        16 - (
          button_number ^
          application::drum_pad_buttons_source_mask
        )
      );
    }        
    else {
      switch (button_number) {
      case 128:
        application_event.type = application_event::EVT_PLAYBACK_STATE_TOGGLE;
      }
    }
  }
  else if (control_event.type == control_event::EVT_ENCODER) {
    uint8_t encoder_number = control_event.parameter >> 8;
    int8_t  encoder_motion = (int8_t)(control_event.parameter & 0xff);
      
    Serial.print("Encoder event, number: ");
    Serial.print(encoder_number);
    Serial.print(", encoder_motion: ");
    Serial.print(encoder_motion);
    Serial.println();

    switch (encoder_number) {
    case 128:
      application_event.type = (
        encoder_motion > 0 ?
        application_event::EVT_MAJ_UP :
        application_event::EVT_MAJ_DN
      );
      break;

    case 129:
      application_event.type = (
        encoder_motion > 0 ?
        application_event::EVT_MIN_UP :
        application_event::EVT_MIN_DN
      );
      break;

    case 130:
      application_event.type = (
        encoder_motion > 0 ?
        application_event::EVT_PHASE_MAJ_UP :
        application_event::EVT_PHASE_MAJ_DN
      );
      break;

    case 131:
      application_event.type = (
        encoder_motion > 0 ?
        application_event::EVT_PHASE_MIN_UP :
        application_event::EVT_PHASE_MIN_DN
      );
      break;

    case 71:
      application_event.type = (
        encoder_motion > 0 ?
        application_event::EVT_SELECTED_TRACK_DN :
        application_event::EVT_SELECTED_TRACK_UP
      );
      break;
    
    case 64:
      application_event.type = (
        encoder_motion > 0 ?
        application_event::EVT_BPM_UP :
        application_event::EVT_BPM_DN
      );
      break;
    }
  }

  return application_event;
}

////////////////////////////////////////////////////////////////////////////////

bool application::process_application_event(
  application::application_event application_event
) {
  if (! application_event) return false;

  if ((application_event.type >= 20) && (application_event.type <= 27)) {
    ProcessTrackControl<application_event::event_type, 8>::apply(
      _tracks.current(),
      ((application_event::event_type)(application_event.type - 20))
    );
    
    _ui_data.redraw_track.set();
    _ui_data.redraw_selected_track_indicator.set();
    
    _eeprom.flag_save_requested();
    
    goto success;
  }
    
  switch (application_event.type) {
  case application_event::EVT_BPM_UP:
  {
    uint8_t current_bpm = _timer1.bpm();
    
    if (current_bpm == 0xff) {
      application_event.type = application_event::EVT_NOT_AVAILABLE;

      break;
    }
    else {
      _timer1.set_bpm(current_bpm + 1);

      goto after_bpm_set;
    }
  }
  case application_event::EVT_BPM_DN:
  {
    uint8_t current_bpm = _timer1.bpm();
    
    if (current_bpm == 0) {
      application_event.type = application_event::EVT_NOT_AVAILABLE;

      break;
    }
    else {
      _timer1.set_bpm(current_bpm - 1);

      goto after_bpm_set;      
    }
  }
  
  case application_event::EVT_PAD_1:
  case application_event::EVT_PAD_2:
  case application_event::EVT_PAD_3:
  case application_event::EVT_PAD_4:
  case application_event::EVT_PAD_5:
  case application_event::EVT_PAD_6:
  case application_event::EVT_PAD_7:
  case application_event::EVT_PAD_8:
  case application_event::EVT_PAD_9:
  case application_event::EVT_PAD_10:
  case application_event::EVT_PAD_11:
  case application_event::EVT_PAD_12:
  case application_event::EVT_PAD_13:
  case application_event::EVT_PAD_14:
  case application_event::EVT_PAD_15:
  case application_event::EVT_PAD_16:
  {
    static uint16_t light_states = 0;

    _x0x_leds.xor_write(light_states);
      
    uint16_t tmp = util::flip_bytes(
      ((uint16_t)1) <<
      (((uint8_t)application_event.type) - 1)
    );

    light_states ^= tmp;
      
    Serial.print("Light up ");
    util::print_bits_16(light_states);
    Serial.println();

    _x0x_leds.or_write(light_states, true);

    goto success;
  }
  case application_event::EVT_SELECTED_TRACK_UP:
  {
    _tracks++;

    Serial.print("Trk up -> ");

    goto after_track_select;
  }
  case application_event::EVT_SELECTED_TRACK_DN:
  {
    _tracks--;

    Serial.print("Trk dn -> ");

    goto after_track_select;
  }
  case application_event::EVT_PLAYBACK_STATE_TOGGLE:
  {
    set_playback_state(! _timer1.playback_state());

    if (_timer1.playback_state()) {
      Serial.println("Play.");
    }
    else {
      Serial.println("Stop.");
    }
    
    _eeprom.flag_save_requested();
      
    goto success;
  }
  default:
    Serial.print("Unrecognized event: ");
    Serial.print(application_event.type, HEX);
    Serial.println();
    Serial.flush();
  }

  return false;

after_track_select:
  _ui_data.redraw_selected_track_indicator.set();
  Serial.print(_tracks.index()); Serial.flush();
  Serial.println(); Serial.flush();
  
  goto success;

after_bpm_set:      
  _ui_data.popup_bpm_requested.set();

  _eeprom.flag_save_requested();
  
success:
  flag_main_screen();

  return true;
}

////////////////////////////////////////////////////////////////////////////////

