#include "application/application.h"
#include "event/event.h"
#include "process_track_control_event.h"
#include "util/util.h"

const event_type combo_pad_ordering[] = {
  EVT_NOT_AVAILABLE,
  EVT_NOT_AVAILABLE,
  EVT_NOT_AVAILABLE,
  EVT_NOT_AVAILABLE,

  EVT_NOT_AVAILABLE,
  EVT_NOT_AVAILABLE,
  EVT_NOT_AVAILABLE,
  EVT_PLAYBACK_STATE_TOGGLE, // EVT_PHASE_MIN_DN,
};

const event_type drum_pad_ordering[] = {
  EVT_PAD_1,
  EVT_PAD_2,
  EVT_PAD_3,  
  EVT_PAD_4,

  EVT_PAD_5,
  EVT_PAD_6,
  EVT_PAD_7,
  EVT_PAD_8,

  EVT_PAD_9,
  EVT_PAD_10,
  EVT_PAD_11,
  EVT_PAD_12,

  EVT_PAD_13,
  EVT_PAD_14,
  EVT_PAD_15,
  EVT_PAD_16,
};

////////////////////////////////////////////////////////////////////////////////

jm_PCF8574             application::_trigger_outputs_device;
application::tracks_t  application::_tracks;
application::ui_data_t application::_ui_data;
application::ui_t      application::_ui(&_ui_data);
eeprom_                application::_eeprom;
timer1_                application::_timer1;
timer2_                application::_timer2;
lamb::flag             application::_controls_flag;
lamb::flag             application::_output_flag;
uint8_t                application::_queued_output = 0xff;
::x0x_leds             application::_x0x_leds;
::trigger_outputs      application::_trigger_outputs;
Adafruit_MCP23017      application::_x0x_leds_device;
Adafruit_MCP23017      application::_combo_pad_device;
Adafruit_MCP23017      application::_drum_pad_device;
Adafruit_MCP23017      application::_encoder_pad_device;

////////////////////////////////////////////////////////////////////////////////

application::control_event_source_t
                       application::_control_event_source;

combine_event_sources<event, application::event_sources_count>
                       application::_combine_event_sources;


encoder_pad_mcp23017   application::_combo_pad_encoder_pad(
                         application::combo_pad_encoders_count,
                         8
                       );

encoder_pad_mcp23017   application::_encoder_pad0(
                         application::encoder_pad_encoders_count
                       );

button_pad_mcp23017    application::_combo_pad_button_pad(8);

button_pad_mcp23017    application::_drum_pad_button_pad; 

encoder_pad_source<encoder_pad_mcp23017>
                       application::_encoder_pad_source0(
                         &application::_encoder_pad0,
                         64
                       );

encoder_pad_source<encoder_pad_mcp23017>
                       application::_combo_pad_encoder_source(
                         &application::_combo_pad_encoder_pad
                       );

button_pad_source<button_pad_mcp23017>
                       application::_combo_pad_button_source(
                         &application::_combo_pad_button_pad,
                         combo_pad_ordering,
                         8
                       );

button_pad_source<button_pad_mcp23017>
                       application::_drum_pad_source(
                         &application::_drum_pad_button_pad,
                         drum_pad_ordering,
                         16
                       );

////////////////////////////////////////////////////////////////////////////////

application::application() {};

application::~application() {};

x0x_leds & application::x0x_leds() {
  return _x0x_leds;
}

trigger_outputs & application::trigger_outputs() {
  return _trigger_outputs;
}

void application::update_ui_data() {
  _ui_data.page           = page();
  _ui_data.bpm            = _timer1.bpm();
  _ui_data.millihz        = _timer1.millihz();
  _ui_data.playback_state = _timer1.playback_state();
  _ui_data.ticker         = _timer1.ticker();
}

void application::setup() {
  Serial .begin(230400);

  Wire   .begin();
  Wire   .setClock(400000);

  _x0x_leds_device.begin(x0x_leds_addr);
  _x0x_leds.setup(&_x0x_leds_device);

  _trigger_outputs_device.begin(trigger_outputs_addr);
  _trigger_outputs.setup(&_trigger_outputs_device);
  
  _ui   .setup();
  _ui   .enter_screen(ui_t::SCREEN_INTRO);
  
  eeprom_::PersistantData<tracks_t> tmp(
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

  _ui    .enter_screen(ui_t::SCREEN_MAIN);

  Serial.println(F("Entered SCREEN_MAIN.")); Serial.flush();
}

void application::setup_controls() {
  _combo_pad_device     .begin(combo_pad_addr);
  _drum_pad_device      .begin(drum_pad_addr);
  _encoder_pad_device   .begin(encoder_pad_addr);
  
  _drum_pad_button_pad  .setup      ( &_drum_pad_device);
  _combine_event_sources.sources[0] = &_drum_pad_source;
  
  _combo_pad_button_pad .setup      ( &_combo_pad_device);
  _combine_event_sources.sources[1] = &_combo_pad_button_source;
  
  _combo_pad_encoder_pad.setup      ( &_combo_pad_device);
  _combine_event_sources.sources[2] = &_combo_pad_encoder_source;
  
  _encoder_pad0         .setup      ( &_encoder_pad_device);
  _combine_event_sources.sources[3] = &_encoder_pad_source0;

  _control_event_source .source     = &_combine_event_sources;
}

void application::loop() {
  (
    _trigger_outputs.update() || 
    _x0x_leds.update()        ||
    
    _trigger_outputs.update() ||   
    process_control_events()  ||
    
    _trigger_outputs.update() ||
    (update_ui_data(), _ui.update_screen())
  );
}

void application::flag_main_screen() {
  _ui.flag_screen(ui_t::SCREEN_MAIN);
}

uint8_t application::page() {
  return ((_timer1.ticker() >> 1) % _tracks.max_mod_maj()) >> 4;
}

void application::set_playback_state(bool const & playback_state_) {
  _timer1.set_playback_state(playback_state_);

  _ui_data.redraw_playback_state.set();

  flag_main_screen();

  _eeprom.flag_save_requested();
}

void application::save_state() {
  _eeprom.save_all(
    eeprom_::PersistantData<tracks_t>(
      &_tracks,
      _timer1.bpm(),
      _timer1.playback_state()
    )
  );
}

void application::flag_controls() {
  _controls_flag.set();
}

bool application::process_control_events() {
  if (! _controls_flag.consume())
    return false;

  _control_event_source.poll();

  while(process_control_event(_control_event_source.dequeue_event()));

  return true;
}

bool application::process_control_event(
  application::control_event_source_t::event_t e
) {
  if (! e) {
    return false;
  }

  if (e.type == event_type::EVT_ENCODER) {
    uint8_t encoder_number = e.parameter >> 8;
    int8_t  motion = (int8_t)(e.parameter & 0xff);
      
    Serial.print("Encoder event, number: ");
    Serial.print(encoder_number);
    Serial.print(", motion: ");
    Serial.print(motion);
    Serial.println();

    switch (encoder_number) {
    case 0:
      e.type = motion > 0 ? EVT_MAJ_UP : EVT_MAJ_DN;
      break;

    case 1:
      e.type = motion > 0 ? EVT_MIN_UP : EVT_MIN_DN;
      break;

    case 2:
      e.type = motion > 0 ? EVT_PHASE_MAJ_UP : EVT_PHASE_MAJ_DN;
      break;

    case 3:
      e.type = motion > 0 ? EVT_PHASE_MIN_UP : EVT_PHASE_MIN_DN;
      break;

    case 71:
      e.type = motion > 0 ? EVT_SELECTED_TRACK_DN : EVT_SELECTED_TRACK_UP;
      break;
    
    case 64:
      e.type = event_type::EVT_BPM_SET;
      e.parameter = _timer1.bpm() + motion;

      break;
    }
  }

  if ((e.type >= 20) && (e.type <= 27)) {
    ProcessTrackControl<event::event_type_t, 8>::apply(
      _tracks.current(),
      ((event_type)(e.type - 20))
    );
    
    _ui_data.redraw_track.set();
    _ui_data.redraw_selected_track_indicator.set();
    
    _eeprom.flag_save_requested();
    
    goto success;
  }
    
  switch (e.type) {
  case event_type::EVT_BPM_SET:
  {
    _timer1.set_bpm(e.parameter);

    _ui_data.popup_bpm_requested.set();
    
    _eeprom.flag_save_requested();
    
    goto success;
  }

  case EVT_PAD_1:
  case EVT_PAD_2:
  case EVT_PAD_3:
  case EVT_PAD_4:
  case EVT_PAD_5:
  case EVT_PAD_6:
  case EVT_PAD_7:
  case EVT_PAD_8:
  case EVT_PAD_9:
  case EVT_PAD_10:
  case EVT_PAD_11:
  case EVT_PAD_12:
  case EVT_PAD_13:
  case EVT_PAD_14:
  case EVT_PAD_15:
  case EVT_PAD_16:
  {
    static uint16_t light_states = 0;

    _x0x_leds.xor_write(light_states);
      
    uint16_t tmp = util::flip_bytes(((uint16_t)1) << (((uint8_t)e.type) - 1));
    light_states ^= tmp;
      
    Serial.print("Light up ");
    util::print_bits_16(light_states);
    Serial.println();

    _x0x_leds.or_write(light_states, true);

    goto success;
  }
  case event_type::EVT_SELECTED_TRACK_UP:
  {
    _tracks++;

    _ui_data.redraw_selected_track_indicator.set();

    Serial.print("Trk up -> "); Serial.flush();
    Serial.print(_tracks.index()); //  Serial.flush();
    Serial.println(); Serial.flush();

    goto success;
  }
  case event_type::EVT_SELECTED_TRACK_DN:
  {
    _tracks--;

    _ui_data.redraw_selected_track_indicator.set();
      
    Serial.print("Trk dn -> "); Serial.flush();
    Serial.print(_tracks.index()); Serial.flush();
    Serial.println(); Serial.flush();
      
    goto success;
  }
  case event_type::EVT_PLAYBACK_STATE_TOGGLE:
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
    Serial.print(e.type, HEX);
    Serial.println();
    Serial.flush();
  }
  return false;

success:
  flag_main_screen();
  return true;
}

