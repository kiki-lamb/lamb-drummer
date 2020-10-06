#include "application.h"
#include "process_track_control_event.h"
#include "event_sources/button_pad_source.h"
#include "event_sources/encoder_source.h"
#include "event_sources/button_pad_source.h"
#include "event_sources/encoder_pad_source.h"
#include "event/event.h"
#include "button_pads/button_pad_mcp23017.h"
#include "button_pads/encoder_pad_mcp23017.h"
#include <avr/power.h>

application::control_event_source_t
                          application::control_event_source;
Adafruit_MCP23017         application::x0x_leds;
application::tracks_t     application::_tracks;
application::ui_data_t    application::ui_data_;
application::ui_t         application::ui_(&ui_data_);
eeprom_                   application::eeprom;
timer1_                   application::timer1;
timer2_                   application::timer2;
jm_PCF8574                application::trigger_outputs;
lamb::flag                application::controls_flag;
lamb::flag                application::output_flag;
lamb::flag                application::x0x_leds_flag;
uint16_t                  application::x0x_leds_values_ = 0x00;
uint8_t                   application::queued_output = 0xff;

application::application() {};

application::~application() {};

void application::update_ui_data() {
  ui_data_.page           = page();
  ui_data_.bpm            = timer1.bpm();
  ui_data_.hz             = timer1.hz();
  ui_data_.playback_state = timer1.playback_state();
  ui_data_.ticker         = timer1.ticker();
}

void application::setup_trigger_outputs() {
  clock_prescale_set(clock_div_1);

  trigger_outputs.begin(0x3a);
  
  for (uint8_t ix = 0; ix < 8; ix++) {
    trigger_outputs.pinMode(ix, OUTPUT);
  }

  trigger_outputs.write(0xff);
}

void application::setup_x0x_leds() {

  x0x_leds.begin(0x4);

  for (size_t ix = 0; ix < 16; ix++) {
     x0x_leds.pinMode(ix, OUTPUT);
     x0x_leds.digitalWrite(ix, LOW);
  }
}

void application::setup() {
  Serial .begin(230400);

  Wire   .begin();
  Wire   .setClock(400000);

  setup_x0x_leds();
  
  setup_trigger_outputs();
  
  static const uint16_t step = 150;

  ui_   .setup();
  ui_   .enter_screen(ui_t::SCREEN_INTRO);
  
  eeprom_::PersistantData<tracks_t> tmp(
    &_tracks,
    timer1.bpm(),
    timer1.playback_state()
  );

  eeprom .restore_all(tmp);

  setup_controls(tmp.bpm);
  
  cli();

  Serial.println(F("Stop all interrupts...")); Serial.flush();
  
  timer1 .setup();
  timer1 .set_bpm(120);

  timer2 .setup();
  
  set_playback_state(tmp.playback_state);

  while (_tracks++);

  eeprom .unflag_save_requested();
  eeprom .flag_save_requested();

  save_state();
  
  ui_data_.tracks = &_tracks;

  update_ui_data();

  //Serial.println(F("Enable all interrupts.")); Serial.flush();
  sei();
  
  Serial.println(F("Enter SCREEN_MAIN...")); Serial.flush();

  ui_    .enter_screen(ui_t::SCREEN_MAIN);

  Serial.println(F("Entered SCREEN_MAIN.")); Serial.flush();
}

void application::setup_controls(uint8_t bpm) {
  static button_pad_source<button_pad_mcp23017<0x0, 8, 0> >
    combopad_button_source;

  static encoder_pad_source<encoder_pad_mcp23017<0x0, 4, 8> >
    combopad_encoder_source;

  static button_pad_source<button_pad_mcp23017<0x3> >
    drum_pad_source;
  
//  static EncoderSource encoder_source(EventType::EVT_BPM_SET, bpm);
//  static ButtonSource  button_source(
//    EventType::EVT_PLAYBACK_STATE_TOGGLE,
//    A7
//  );
  
  // static combine_event_sources<event,1>
  static combine_event_sources<event,3>
                       combine_event_sources;

  static Adafruit_MCP23017 device0;
  device0.begin(0x0);
  for (uint8_t ix = 0; ix < 16; ix++) {
    device0.pinMode(ix, INPUT);
    device0.pullUp(ix, HIGH);
  }
  combopad_button_source.setup(&device0);
  combopad_encoder_source.setup(&device0);

  static Adafruit_MCP23017 device1;
  device1.begin(0x3);
  for (uint8_t ix = 0; ix < 16; ix++) {
    device1.pinMode(ix, INPUT);
    device1.pullUp(ix, HIGH);
  }
  drum_pad_source.setup(&device1);

//  encoder_source       .setup();
//  button_source.setup();

  combine_event_sources.sources[0] = &drum_pad_source;
  combine_event_sources.sources[1] = &combopad_button_source;
  combine_event_sources.sources[2] = &combopad_encoder_source;
  
//  combine_event_sources.sources[2] = &encoder_source;
//  combine_event_sources.sources[3] = &button_source

  control_event_source .source     = &combine_event_sources;
}

void application::print_bits(uint8_t t0) {
  {
    for(uint16_t mask = 0x80; mask; mask >>= 1) {
      if (mask & t0) {
        Serial.print('1'); Serial.flush();
      }
      else {
        Serial.print('0'); Serial.flush();
      }
    }
  }
}

void application::print_bits_16(uint16_t t0) {
  {
    for(uint16_t mask = 0x8000; mask; mask >>= 1) {
      if (mask & t0) {
        Serial.print('1'); Serial.flush();
      }
      else {
        Serial.print('0'); Serial.flush();
      }
    }
  }
}

bool application::output() {
  if (! output_flag.consume())
    return false;
  
#ifdef LOG_OUTPUT
  if (application::timer1.ticker() & 0b1) {
    Serial.print(application::timer1.ticker()); Serial.flush();
    Serial.print(F(" ")); Serial.flush();
    Serial.print(F("Output: ")); Serial.flush();

    print_bits(queued_output);
    
    Serial.println(); Serial.flush();
  }
#endif
  
  trigger_outputs.write(queued_output);

  return true;
}

void application::loop() {
//  Serial.print(F("output();")); Serial.flush();
  output();
  
//  Serial.println(F("process_control_events();")); Serial.flush();
  process_control_events();
    
//  Serial.println(F("update_ui_data();")); Serial.flush();
  update_ui_data();

//  Serial.println(F("ui.update_screen();")); Serial.flush();
  ui_.update_screen();

  update_x0x_leds();
}

void application::update_x0x_leds() {
  if (! x0x_leds_flag.consume())
    return;
  
  x0x_leds.writeGPIOAB(x0x_leds_values());
}

uint16_t application::x0x_leds_values() {
  return x0x_leds_values_;
}

void application::write_x0x_leds_xor(uint16_t const & value) {
  write_x0x_leds(x0x_leds_values() ^ value);
}

void application::write_x0x_leds(uint16_t const & value) {
  x0x_leds.writeGPIOAB(value);
}

void application::flag_main_screen() {
  ui_.flag_screen(ui_t::SCREEN_MAIN);
}

uint8_t application::page() {
  uint8_t tmp_tick        = timer1.ticker() >> 1;
  uint8_t tmp_inside_tick = tmp_tick % _tracks.max_mod_maj();

  return                    tmp_inside_tick /  16;
}

void application::set_playback_state(bool playback_state_) {
  timer1.set_playback_state(playback_state_);

  ui_data_.redraw_playback_state.set();

  flag_main_screen();

  eeprom.flag_save_requested();
}

void application::save_state() {
   eeprom.save_all(
     eeprom_::PersistantData<tracks_t>(
       &_tracks,
       timer1.bpm(),
       timer1.playback_state()
     )
   );
}

void application::flag_controls() {
  controls_flag.set();
}

void application::flag_output(uint8_t output) {
#ifdef LOG_OUTPUT
  Serial.print(F("Flagging: ")); Serial.flush();
  
  print_bits(output);

  Serial.println(); Serial.flush();
#endif
  
  queued_output = output;

  output_flag.set();
}

bool application::process_control_events() {
  if (! controls_flag.consume())
    return false;

  // Serial.println(F("control_event_source.poll();")); Serial.flush();
  control_event_source.poll();

  // Serial.println(F("dequeue...")); Serial.flush();
  while(process_control_event(control_event_source.dequeue_event()));

  // Serial.println(F("return...")); Serial.flush();
  return true;
}

uint16_t application::flip_bytes(uint16_t value) {
  uint8_t a = value >> 8;
  uint8_t b = value &  0xff;
  
  return (((uint16_t)b) << 8) | a; 
}

bool application::process_control_event(
  application::control_event_source_t::event_t e
) {
  if (! e) {
    return false;
  }
  if ((e.type >= 20) && (e.type <= 27)) {
    ProcessTrackControl<event::event_type_t, 8>::apply(
      _tracks.current(),
      ((event_type)(e.type - 20))
    );
    
    ui_data_.redraw_track.set();
    ui_data_.redraw_selected_track_indicator.set();

    eeprom.flag_save_requested();
    
    goto success;
  }
  else {
    switch (e.type) {
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
//      Serial.print("Light up ");
//      Serial.print(e.type);
//      Serial.println();
//      Serial.flush();      

      uint16_t tmp = flip_bytes(((uint16_t)1) << (((uint8_t)e.type) - 1));
      
      x0x_leds_values_ = x0x_leds_values() ^ tmp;
      
      x0x_leds_flag.set();

      goto success;
    }
    case event_type::EVT_SELECTED_TRACK_UP:
    {
      _tracks++;

      ui_data_.redraw_track.set();
      ui_data_.redraw_selected_track_indicator.set();

      Serial.print("GO UP A TRACK TO "); Serial.flush();
      Serial.print(_tracks.index()); //  Serial.flush();
      Serial.println(); Serial.flush();

      break;
    }
    case event_type::EVT_SELECTED_TRACK_DN:
    {
      _tracks--;
      
      ui_data_.redraw_track.set();
      ui_data_.redraw_selected_track_indicator.set();
      
      Serial.print("GO DOWN A TRACK TO "); Serial.flush();
      Serial.print(_tracks.index()); Serial.flush();
      Serial.println(); Serial.flush();
      
      break;
    }
    case event_type::EVT_PLAYBACK_STATE_TOGGLE:
    {
      set_playback_state(! timer1.playback_state());
      
      eeprom.flag_save_requested();
      
      goto success;
    }
    case event_type::EVT_BPM_SET:
    {
      timer1.set_bpm(e.parameter);

      ui_data_.popup_bpm_requested.set();
      
      eeprom.flag_save_requested();
      
      goto success;
    }
    case event_type::EVT_ENCODER:
    {
      Serial.print("Encoder event, number: ");
      Serial.print(e.parameter >> 8);
      Serial.print(", motion: ");
      Serial.print(e.parameter & 0xff);
      Serial.println();
      
      goto success;
    }
    default:
      Serial.print("Unrecognized event: ");
      Serial.print(e.type, HEX);
      Serial.print(" ");
      Serial.print(e.parameter, HEX);
      Serial.println();
      Serial.flush();
    }
    return false;

  success:
      flag_main_screen();
      return true;
  }
}
