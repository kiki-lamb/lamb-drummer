#include "application/application.h"
#include "events/application.h"
#include "process_track_control_event.h"
#include "util/util.h"

const events::application::event_type drum_pad_ordering[] = {
  events::application::EVT_PAD_1,
  events::application::EVT_PAD_2,
  events::application::EVT_PAD_3,  
  events::application::EVT_PAD_4,

  events::application::EVT_PAD_5,
  events::application::EVT_PAD_6,
  events::application::EVT_PAD_7,
  events::application::EVT_PAD_8,

  events::application::EVT_PAD_9,
  events::application::EVT_PAD_10,
  events::application::EVT_PAD_11,
  events::application::EVT_PAD_12,

  events::application::EVT_PAD_13,
  events::application::EVT_PAD_14,
  events::application::EVT_PAD_15,
  events::application::EVT_PAD_16,
};

////////////////////////////////////////////////////////////////////////////////

jm_PCF8574                application::_trigger_outputs_device;
application::tracks_type  application::_tracks;
application::ui_data_type application::_ui_data;
application::ui_type      application::_ui(&_ui_data);
eeprom_                   application::_eeprom;
timer1_                   application::_timer1;
timer2_                   application::_timer2;
lamb::flag                application::_controls_flag;
lamb::flag                application::_output_flag;
::x0x_leds                application::_x0x_leds;
::trigger_outputs         application::_trigger_outputs;
Adafruit_MCP23017         application::_x0x_leds_device;
Adafruit_MCP23017         application::_combo_pad_device;
Adafruit_MCP23017         application::_drum_pad_device;
Adafruit_MCP23017         application::_encoder_pad_device;

////////////////////////////////////////////////////////////////////////////////

application::control_event_source_type
                       application::_control_event_source;

events::sources::combine<events::control, application::event_sources_count>
                       application::_combine_event_sources;


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

events::sources::encoder_pad<encoder_pad_mcp23017>
                       application::_encoder_pad_source0(
                         &application::_encoder_pad0,
                         application::encoder_pad_source_mask
                       );

events::sources::encoder_pad<encoder_pad_mcp23017>
                       application::_combo_pad_encoder_source(
                         &application::_combo_pad_encoder_pad,
                         application::combo_pad_encoders_source_mask
                       );

events::sources::button_pad<button_pad_mcp23017>
                       application::_combo_pad_button_source(
                         &application::_combo_pad_button_pad,
                         application::combo_pad_buttons_source_mask
                       );

events::sources::button_pad<button_pad_mcp23017>
                       application::_drum_pad_source(
                         &application::_drum_pad_button_pad,
                         application::drum_pad_buttons_source_mask
                       );

////////////////////////////////////////////////////////////////////////////////

application::application() {};

////////////////////////////////////////////////////////////////////////////////

application::~application() {};

////////////////////////////////////////////////////////////////////////////////

x0x_leds & application::x0x_leds() {
  return _x0x_leds;
}

////////////////////////////////////////////////////////////////////////////////

trigger_outputs & application::trigger_outputs() {
  return _trigger_outputs;
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

  _trigger_outputs_device.begin(trigger_outputs_addr);
  _trigger_outputs.setup(&_trigger_outputs_device);
  
  _ui   .setup();
  _ui   .enter_screen(ui_type::SCREEN_INTRO);
  
  eeprom_::PersistantData<tracks_type> tmp(
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

  _ui    .enter_screen(ui_type::SCREEN_MAIN);

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
    _trigger_outputs.update() || 
    _x0x_leds.update()        ||
    
    _trigger_outputs.update() ||   
    process_application_events()  ||
    
    _trigger_outputs.update() ||
    (update_ui_data(), _ui.update_screen())
  );
}

////////////////////////////////////////////////////////////////////////////////

void application::flag_main_screen() {
  _ui.flag_screen(ui_type::SCREEN_MAIN);
}

////////////////////////////////////////////////////////////////////////////////

uint8_t application::page() {
  return ((_timer1.ticker() >> 1) % _tracks.max_mod_maj()) >> 4;
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
    eeprom_::PersistantData<tracks_type>(
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

bool application::process_application_events() {
  if (! _controls_flag.consume())
    return false;

  _control_event_source.poll();

  while(process_application_event(_control_event_source.dequeue_event()));

  return true;
}

////////////////////////////////////////////////////////////////////////////////

events::application application::convert_control_event(
  events::control const & control_event
) {
  events::application application_event;
  
  if (control_event.type == events::control::EVT_BUTTON) {
    uint8_t button_number = control_event.parameter >> 8;
    int8_t  button_state = (int8_t)(control_event.parameter & 0xff);
      
    Serial.print("Button event, number: ");
    Serial.print(button_number);
    Serial.print(", state: ");
    Serial.print(button_state);
    Serial.println();
    
    if ((button_number >= 64) && (button_number <= 79)) {
      application_event.type = drum_pad_ordering[
        (
          15 - (
            button_number ^
            application::drum_pad_buttons_source_mask
          )
        )
      ];
    }        
    else {
      switch (button_number) {
      case 128:
        application_event.type = events::application::EVT_PLAYBACK_STATE_TOGGLE;
      }
    }
  }

  if (control_event.type == events::control::EVT_ENCODER) {
    uint8_t encoder_number = control_event.parameter >> 8;
    int8_t  motion = (int8_t)(control_event.parameter & 0xff);
      
    Serial.print("Encoder event, number: ");
    Serial.print(encoder_number);
    Serial.print(", motion: ");
    Serial.print(motion);
    Serial.println();

    switch (encoder_number) {
    case 128:
      application_event.type = (
        motion > 0 ?
        events::application::EVT_MAJ_UP :
        events::application::EVT_MAJ_DN
      );
      break;

    case 129:
      application_event.type = (
        motion > 0 ?
        events::application::EVT_MIN_UP :
        events::application::EVT_MIN_DN
      );
      break;

    case 130:
      application_event.type = (
        motion > 0 ?
        events::application::EVT_PHASE_MAJ_UP :
        events::application::EVT_PHASE_MAJ_DN
      );
      break;

    case 131:
      application_event.type = (
        motion > 0 ?
        events::application::EVT_PHASE_MIN_UP :
        events::application::EVT_PHASE_MIN_DN
      );
      break;

    case 71:
      application_event.type = (
        motion > 0 ?
        events::application::EVT_SELECTED_TRACK_DN :
        events::application::EVT_SELECTED_TRACK_UP
      );
      break;
    
    case 64:
      application_event.type = events::application::EVT_BPM_SET;
      application_event.parameter = _timer1.bpm() + motion;

      break;
    }
  }

  return application_event;
}

////////////////////////////////////////////////////////////////////////////////

bool application::process_application_event(
  application::control_event_source_type::event_type e
) {
  if (! e) {
    return false;
  }

  events::application application_event = convert_control_event(e);
  
  if ((application_event.type >= 20) && (application_event.type <= 27)) {
    ProcessTrackControl<events::application::event_type, 8>::apply(
      _tracks.current(),
      ((events::application::event_type)(application_event.type - 20))
    );
    
    _ui_data.redraw_track.set();
    _ui_data.redraw_selected_track_indicator.set();
    
    _eeprom.flag_save_requested();
    
    goto success;
  }
    
  switch (application_event.type) {
  case events::application::EVT_BPM_SET:
  {
    _timer1.set_bpm(application_event.parameter);

    _ui_data.popup_bpm_requested.set();
    
    _eeprom.flag_save_requested();
    
    goto success;
  }

  case events::application::EVT_PAD_1:
  case events::application::EVT_PAD_2:
  case events::application::EVT_PAD_3:
  case events::application::EVT_PAD_4:
  case events::application::EVT_PAD_5:
  case events::application::EVT_PAD_6:
  case events::application::EVT_PAD_7:
  case events::application::EVT_PAD_8:
  case events::application::EVT_PAD_9:
  case events::application::EVT_PAD_10:
  case events::application::EVT_PAD_11:
  case events::application::EVT_PAD_12:
  case events::application::EVT_PAD_13:
  case events::application::EVT_PAD_14:
  case events::application::EVT_PAD_15:
  case events::application::EVT_PAD_16:
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
  case events::application::EVT_SELECTED_TRACK_UP:
  {
    _tracks++;

    _ui_data.redraw_selected_track_indicator.set();

    Serial.print("Trk up -> "); Serial.flush();
    Serial.print(_tracks.index()); //  Serial.flush();
    Serial.println(); Serial.flush();

    goto success;
  }
  case events::application::EVT_SELECTED_TRACK_DN:
  {
    _tracks--;

    _ui_data.redraw_selected_track_indicator.set();
      
    Serial.print("Trk dn -> "); Serial.flush();
    Serial.print(_tracks.index()); Serial.flush();
    Serial.println(); Serial.flush();
      
    goto success;
  }
  case events::application::EVT_PLAYBACK_STATE_TOGGLE:
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

success:
  flag_main_screen();

  return true;
}

////////////////////////////////////////////////////////////////////////////////

