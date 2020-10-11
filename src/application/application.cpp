#include "application/application.h"
#include "events/application.h"
#include "process_track_control_event.h"

////////////////////////////////////////////////////////////////////////////////

jm_PCF8574                    application::_triggers_device;
application::track_collection application::_tracks;
application::ui_data          application::_ui_data;
application::ui               application::_ui(&_ui_data);
eeprom                        application::_eeprom;
timer1                        application::_timer1(application::tracks_count);
timer2                        application::_timer2;
lamb::flag                    application::_controls_flag;
outputs::x0x_leds             application::_x0x_leds;
outputs::triggers             application::_triggers;
Adafruit_MCP23017             application::_x0x_leds_device;
Adafruit_MCP23017             application::_combo_pad_device;
Adafruit_MCP23017             application::_drum_pad_device;
Adafruit_MCP23017             application::_encoder_pad_device;

////////////////////////////////////////////////////////////////////////////////

lamb::controls::encoder_pad_mcp23017
application::_combo_pad_encoder_pad(
  application::combo_pad_encoders_count,
  application::combo_pad_encoders_range_start
);

lamb::controls::button_pad_mcp23017
application::_combo_pad_button_pad(
  application::combo_pad_buttons_count,
  application::combo_pad_buttons_range_start
);

lamb::controls::encoder_pad_mcp23017
application::_encoder_pad0(
  application::encoder_pad_encoders_count,
  application::encoder_pad_encoders_range_start
);

lamb::controls::button_pad_mcp23017
application::_drum_pad_button_pad(
  application::drum_pad_buttons_count,
  application::drum_pad_buttons_range_start
);

////////////////////////////////////////////////////////////////////////////////

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

application::control_source
application::_control_event_source;

application::combined_source
application::_combine_event_sources;

////////////////////////////////////////////////////////////////////////////////

application::application() {};

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
  _ui_data.bar            = bar();
  _ui_data.bpm            = _timer1.bpm();
  _ui_data.millihz        = _timer1.millihz();
  _ui_data.playback_state = _timer1.playback_state();
  _ui_data.ticker         = _timer1.ticker();
}

////////////////////////////////////////////////////////////////////////////////

void application::setup() {
  Serial .begin(230400);

  Wire   .begin();
  Wire   .setClock(1000000);

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

  _eeprom .unflag_save_requested();

  save_state();
  
  _ui_data.tracks = &_tracks;

  update_ui_data();

  _timer1.set_bpm(tmp.bpm);
  
#ifdef XOX
  for (uint8_t ix; ix < tracks_count; ix++) {
    // For some absolutely mystifying reason, bars_count becomes undefined
    // without this cast...
    
    tracks()[ix].clear((typeof(bars_count))bars_count);
  }
#endif
  
  sei();
  
  Serial.println(F("Enter SCREEN_MAIN...")); Serial.flush();

  _ui    .enter_screen(ui::SCREEN_MAIN);

  Serial.println(F("Entered SCREEN_MAIN.")); Serial.flush();
}

////////////////////////////////////////////////////////////////////////////////

application::track_collection & application::tracks()
{
  return _tracks;
}

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
  if (! (
        _triggers.update()       || 
        _x0x_leds.update()       ||    
        _triggers.update()       ||   
        process_control_events() ||    
        _triggers.update())
  ) {
    update_ui_data();
    _ui.update_screen();
  }
}

////////////////////////////////////////////////////////////////////////////////

void application::flag_main_screen() {
  _ui.flag_screen(ui::SCREEN_MAIN);
}

////////////////////////////////////////////////////////////////////////////////

uint8_t application::bar() {
#ifdef XOX
  auto track = application::tracks()[0];
  
  uint8_t bar;
  uint8_t step;
  
  track.position((_timer1.ticker() >> 1), bar, step);

  return bar;
#else
  auto tracks = application::tracks();

  uint8_t max = 0;
    
  for (uint8_t ix = 0; ix < tracks.size(); ix++) {
    if (tracks[ix].mod_maj() > max) {
      max = tracks[ix].mod_maj();
    }
  }

  return ((_timer1.ticker() >> 1) % max) >> 4;
#endif
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
  application_event.type = application_event_type::EVT_UNKNOWN;

  if (control_event.type == control_event_type::CTL_EVT_NOT_AVAILABLE) {
    application_event.type = application_event_type::APP_EVT_NOT_AVAILABLE;
  }
  else if (control_event.type == control_event_type::EVT_BUTTON) {
    uint8_t button_number = control_event.parameter_hi();
    int8_t  button_state  = (int8_t)control_event.parameter_lo(); 
      
    Serial.print(F("Button event, number: "));
    Serial.print(button_number);
    Serial.print(F(", state: "));
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
      case 132:
        application_event.type =
          application_event_type::EVT_PAGE_TOGGLE;

        break;
      
      case 135:
        application_event.type =
          application_event_type::EVT_PLAYBACK_STATE_TOGGLE;

        break;
      
      case 130:
        application_event.type =
          application_event_type::EVT_SELECT_TRACK;
        
        application_event.parameter  = 0;

        break;
        
      case 129:
        application_event.type =
          application_event_type::EVT_SELECT_TRACK;
        
        application_event.parameter  = 1;

        break;
        
      case 128:
        application_event.type =
          application_event_type::EVT_SELECT_TRACK;
        
        application_event.parameter  = 2;

        break;
      }
    }
  }
  else if (control_event.type == control_event_type::EVT_ENCODER) {
    uint8_t encoder_number = control_event.parameter >> 8;
    int8_t  encoder_motion = (int8_t)(control_event.parameter & 0xff);

    Serial.print(F("Encoder event, number: "));
    Serial.print(encoder_number);
    Serial.print(F(", encoder_motion: "));
    Serial.print(encoder_motion);
    Serial.println();

    switch (encoder_number) {
    case 128:
      application_event.type = (
        encoder_motion > 0 ?
#ifdef XOX
        application_event_type::EVT_BPM_UP :
        application_event_type::EVT_BPM_DN
#else
        application_event_type::EVT_MAJ_UP :
        application_event_type::EVT_MAJ_DN
#endif        
      );

      break;

    case 129:
      application_event.type = (
        encoder_motion > 0 ?
        application_event_type::EVT_MIN_UP :
        application_event_type::EVT_MIN_DN
      );

      break;

    case 130:
#ifdef XOX
      application_event.type = (
        encoder_motion > 0 ?
        application_event_type::EVT_PAGE_UP :
        application_event_type::EVT_PAGE_DN
      );
#else
      application_event.type = (
        encoder_motion > 0 ?
        application_event_type::EVT_PHASE_MAJ_UP :
        application_event_type::EVT_PHASE_MAJ_DN
      );
#endif
      
      break;

    case 131:
#ifdef XOX
      application_event.type = (
        encoder_motion > 0 ?
        application_event_type::EVT_SELECTED_TRACK_UP :
        application_event_type::EVT_SELECTED_TRACK_DN
      );
#else
      application_event.type = (
        encoder_motion > 0 ?
        application_event_type::EVT_PHASE_MIN_UP :
        application_event_type::EVT_PHASE_MIN_DN
      );
#endif
      
      break;

      
#ifndef XOX    
    case 64:
      application_event.type = (
        encoder_motion > 0 ?
        application_event_type::EVT_BPM_UP :
        application_event_type::EVT_BPM_DN
      );

      break;
#endif
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
#ifdef XOX
    Serial.println(F("IMPLEMENT PTC FOR XOX."));
#else
    ProcessTrackControl<application_event::event_type, 8>::apply(
      _tracks.current(),
      ((application_event::event_type)(application_event.type - 20))
    );

    _ui_data.redraw_track.set();
    _ui_data.redraw_selected_track_indicator.set();
    
    _eeprom.flag_save_requested();
    
    goto success;
#endif    
  }
    
  switch (application_event.type) {
  case application_event_type::EVT_BPM_UP:
  {
    uint8_t current_bpm = _timer1.bpm();
    
    if (current_bpm == 0xff) {
      application_event.type = application_event_type::APP_EVT_NOT_AVAILABLE;

      break;
    }
    else {
      _timer1.set_bpm(current_bpm + 1);

      goto after_bpm_set;
    }
  }
  case application_event_type::EVT_BPM_DN:
  {
    uint8_t current_bpm = _timer1.bpm();
    
    if (current_bpm == 0) {
      application_event.type = application_event_type::APP_EVT_NOT_AVAILABLE;

      break;
    }
    else {
      _timer1.set_bpm(current_bpm - 1);

      goto after_bpm_set;      
    }
  }
  
  case application_event_type::EVT_PAD_1:
  case application_event_type::EVT_PAD_2:
  case application_event_type::EVT_PAD_3:
  case application_event_type::EVT_PAD_4:
  case application_event_type::EVT_PAD_5:
  case application_event_type::EVT_PAD_6:
  case application_event_type::EVT_PAD_7:
  case application_event_type::EVT_PAD_8:
  case application_event_type::EVT_PAD_9:
  case application_event_type::EVT_PAD_10:
  case application_event_type::EVT_PAD_11:
  case application_event_type::EVT_PAD_12:
  case application_event_type::EVT_PAD_13:
  case application_event_type::EVT_PAD_14:
  case application_event_type::EVT_PAD_15:
  case application_event_type::EVT_PAD_16:
  {
#ifdef XOX
    uint8_t step = ((uint8_t)application_event.type)-1;

    _tracks.current().flip_trigger(bar(), step);
    
    _ui_data.redraw_track.set();

    _eeprom.flag_save_requested();
    
    goto success;
#endif
  }


  case application_event_type::EVT_PAGE_TOGGLE:
  {
    Serial.print(F("Page before: "));
    Serial.println(_ui_data.page);

    if (tracks().index() < 3) {
      tracks().jump(tracks().index() + 3);
    }
    else {
      tracks().jump(tracks().index() - 3);
    }
    
    goto after_track_select;
  }

  case application_event_type::EVT_PAGE_UP:
  {
    _ui_data.page = 1;

    if (tracks().index() < 3) {
      tracks().jump(tracks().index() + 3);
    }
    
    goto after_track_select;
  }

  case application_event_type::EVT_PAGE_DN:
  {
    _ui_data.page = 0;
    
     if (tracks().index() > 2) {
       tracks().jump(tracks().index() - 3);
     }
    
    goto after_track_select;
  }

  case application_event_type::EVT_SELECT_TRACK:
  {
    if (_tracks.jump(application_event.parameter + 3 * _ui_data.page)) {
      Serial.print(F("Jump to track "));
      Serial.print(application_event.parameter);
      Serial.println();

      goto after_track_select;
    }
    
    Serial.print(F("Can't jump to track "));
    Serial.print(application_event.parameter);
    Serial.println();
    
    goto failure;
  }
  
  case application_event_type::EVT_SELECTED_TRACK_UP:
  {
    _tracks++;

    Serial.print(F("Trk up -> "));

    goto after_track_select;
  }
  
  case application_event_type::EVT_SELECTED_TRACK_DN:
  {
    _tracks--;

    Serial.print(F("Trk dn -> "));

    goto after_track_select;
  }

  case application_event_type::EVT_PLAYBACK_STATE_TOGGLE:
  {
    set_playback_state(! _timer1.playback_state());

    if (_timer1.playback_state()) {
      Serial.println(F("Play."));
    }
    else {
      Serial.println(F("Stop."));
    }
    
    _eeprom.flag_save_requested();
      
    goto success;
  }

  default:
    Serial.print(F("Unrecognized event: "));
    Serial.print(application_event.type);
    Serial.println();
    Serial.flush();
  }

failure:
  return false;

after_track_select:
  if (tracks().index() > 2) {
    _ui_data.page = 1;
  }
  else {
    _ui_data.page = 0;
  }
  
 
  _ui_data.redraw_selected_track_indicator.set();
  Serial.print(_tracks.index()); Serial.flush();
  Serial.println(); Serial.flush();
  
  Serial.print(F("Page = "));
  Serial.print(_ui_data.page);
  Serial.println();

  goto success;

after_bpm_set:      
  _ui_data.popup_bpm_requested.set();

  _eeprom.flag_save_requested();
  
success:
  flag_main_screen();

  return true;
}

////////////////////////////////////////////////////////////////////////////////

