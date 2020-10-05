#include "application.h"
#include "process_track_control_event.h"
#include "event_sources/button_source.h"
#include "event_sources/encoder_source.h"
#include "event_sources/button_pad_source.h"
#include "event/event.h"
#include <avr/power.h>

application::control_event_source_t
                          application::control_event_source;
Adafruit_MCP23017         application::x0x_leds;
application::tracks_t     application::_tracks;
application::ui_data_t    application::ui_data;
application::ui_t         application::ui(&ui_data);
Eeprom                    application::eeprom;
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
  ui_data.page           = page();
  ui_data.bpm            = timer1.bpm();
  ui_data.hz             = timer1.hz();
  ui_data.playback_state = timer1.playback_state();
  ui_data.ticker         = timer1.ticker();
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

  ui     .setup();
  ui     .enter_screen(ui_t::SCREEN_INTRO);
  
  Eeprom::PersistantData<tracks_t> tmp(
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
  
  ui_data.tracks = &_tracks;

  update_ui_data();

  //Serial.println(F("Enable all interrupts.")); Serial.flush();
  sei();
  
  Serial.println(F("Enter SCREEN_MAIN...")); Serial.flush();

  ui     .enter_screen(ui_t::SCREEN_MAIN);

  Serial.println(F("Entered SCREEN_MAIN.")); Serial.flush();
}

void application::setup_controls(uint8_t bpm) {
  static button_pad_source<button_pad_mcp23017<0x0, 8,  8> > button_pad_source0;
  static button_pad_source<button_pad_mcp23017<0x3, 16, 0> > button_pad_source1;
//  static EncoderSource encoder_source(EventType::EVT_BPM_SET, bpm);
//  static ButtonSource  button_source(
//    EventType::EVT_PLAYBACK_STATE_TOGGLE,
//    A7
//  );
  static combine_event_sources<event,2>
                       combine_event_sources;
  button_pad_source0     .setup();
  button_pad_source1     .setup();

//  encoder_source       .setup();
//  button_source.setup();

  combine_event_sources.sources[0] = &button_pad_source0;
  combine_event_sources.sources[1] = &button_pad_source1;

//  combine_event_sources.sources[1] = &encoder_source;
//  combine_event_sources.sources[2] = &button_source;

  control_event_source .source     = &combine_event_sources; //combine_event_sources;
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
  ui.update_screen();

  update_x0x_leds();
}

void application::update_x0x_leds() {
  if (! x0x_leds_flag.consume())
    return;
  
  Serial.print("Write x0x_leds: ");
  
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
  ui.flag_screen(ui_t::SCREEN_MAIN);
}

uint8_t application::page() {
  uint8_t tmp_tick        = timer1.ticker() >> 1;
  uint8_t tmp_inside_tick = tmp_tick % _tracks.max_mod_maj();

  return                    tmp_inside_tick /  16;
}

void application::set_playback_state(bool playback_state_) {
  timer1.set_playback_state(playback_state_);

  ui_data.redraw_playback_state.set();

  flag_main_screen();

  eeprom.flag_save_requested();
}

void application::save_state() {
   eeprom.save_all(
     Eeprom::PersistantData<tracks_t>(
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
    
    ui_data.redraw_track.set();
    ui_data.redraw_selected_track_indicator.set();

    eeprom.flag_save_requested();
    
    goto success;
  }
  else {
    switch (e.type) {
    case EVT_PAD0_ON:
    case EVT_PAD1_ON:
    case EVT_PAD2_ON:
    case EVT_PAD3_ON:
    case EVT_PAD4_ON:
    case EVT_PAD5_ON:
    case EVT_PAD6_ON:
    case EVT_PAD7_ON:
    case EVT_PAD8_ON:
    case EVT_PAD9_ON:
    case EVT_PAD10_ON:
    case EVT_PAD11_ON:
    case EVT_PAD12_ON:
    case EVT_PAD13_ON:
    case EVT_PAD14_ON:
    case EVT_PAD15_ON:
    {
      Serial.print("Light up ");
      Serial.print(e.type);
      Serial.println();
      Serial.flush();      

      uint16_t tmp = flip_bytes(((uint16_t)1) << e.type);
      
      x0x_leds_values_ = x0x_leds_values() ^ tmp;
      
      x0x_leds_flag.set();

      goto success;
    }
    case event_type::EVT_SELECTED_TRACK_UP:
    {
      _tracks++;

      ui_data.redraw_track.set();
      ui_data.redraw_selected_track_indicator.set();

      Serial.print("GO UP A TRACK TO "); Serial.flush();
      Serial.print(_tracks.index()); //  Serial.flush();
      Serial.println(); Serial.flush();

      break;
    }
    case event_type::EVT_SELECTED_TRACK_DN:
    {
      _tracks--;
      
      ui_data.redraw_track.set();
      ui_data.redraw_selected_track_indicator.set();
      
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

      ui_data.popup_bpm_requested.set();
      
      eeprom.flag_save_requested();
      
      goto success;
    }
    }
    return false;

  success:
      flag_main_screen();
      return true;
  }
}
