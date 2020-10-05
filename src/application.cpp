#include "application.h"
#include "process_track_control_event.h"
#include "event_sources/button_source.h"
#include "event_sources/encoder_source.h"
#include "event_sources/buttonpad_source.h"
#include "event/event.h"

Application::control_event_source_t
                          Application::control_event_source;
Application::tracks_t     Application::_tracks;
Eeprom                    Application::eeprom;
Timer1_                   Application::timer1;
Timer2_                   Application::timer2;
Application::ui_t         Application::ui(&ui_data);
Application::ui_data_t    Application::ui_data;
lamb::Flag                Application::controls_flag;
lamb::Flag                Application::output_flag;
jm_PCF8574                Application::trigger_outputs;
uint8_t                   Application::queued_output = 0xff;
Adafruit_MCP23017         Application::x0x_leds;
uint16_t                  Application::x0x_leds_values_ = 0x00;
lamb::Flag                Application::x0x_leds_flag;


Application::Application() {};

Application::~Application() {};

void Application::update_ui_data() {
  ui_data.page           = page();
  ui_data.bpm            = timer1.bpm();
  ui_data.hz             = timer1.hz();
  ui_data.playback_state = timer1.playback_state();
  ui_data.ticker         = timer1.ticker();
}

void Application::setup_trigger_outputs() {
  trigger_outputs.begin(0x3a);
  
  for (uint8_t ix = 0; ix < 8; ix++) {
    trigger_outputs.pinMode(ix, OUTPUT);
  }

  trigger_outputs.write(0xff);
}

void Application::setup_x0x_leds() {

  x0x_leds.begin(0x4);

  for (size_t ix = 0; ix < 16; ix++) {
     x0x_leds.pinMode(ix, OUTPUT);
     x0x_leds.digitalWrite(ix, LOW);
  }
}

void Application::setup() {
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

void Application::setup_controls(uint8_t bpm) {
  static ButtonpadSource<Buttonpad_MCP23017<0x0, 8,  8> > buttonpad_source0;
  static ButtonpadSource<Buttonpad_MCP23017<0x3, 16, 0> > buttonpad_source1;
//  static EncoderSource encoder_source(EventType::EVT_BPM_SET, bpm);
//  static ButtonSource  button_source(
//    EventType::EVT_PLAYBACK_STATE_TOGGLE,
//    A7
//  );
  static CombineEventSources<Event,2>
                       combine_event_sources;
  buttonpad_source0     .setup();
  buttonpad_source1     .setup();

//  encoder_source       .setup();
//  button_source.setup();

  combine_event_sources.sources[0] = &buttonpad_source0;
  combine_event_sources.sources[1] = &buttonpad_source1;

//  combine_event_sources.sources[1] = &encoder_source;
//  combine_event_sources.sources[2] = &button_source;

  control_event_source .source     = &combine_event_sources; //combine_event_sources;
}

void Application::print_bits(uint8_t t0) {
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

bool Application::output() {
  if (! output_flag.consume())
    return false;
  
#ifdef LOG_OUTPUT
  if (Application::timer1.ticker() & 0b1) {
    Serial.print(Application::timer1.ticker()); Serial.flush();
    Serial.print(F(" ")); Serial.flush();
    Serial.print(F("Output: ")); Serial.flush();

    print_bits(queued_output);
    
    Serial.println(); Serial.flush();
  }
#endif
  
  trigger_outputs.write(queued_output);

  return true;
}

void Application::loop() {
//  Serial.print(F("output();")); Serial.flush();
  output();
  
//  Serial.println(F("process_control_events();")); Serial.flush();
  process_control_events();
    
//  Serial.println(F("update_ui_data();")); Serial.flush();
  update_ui_data();

//  Serial.println(F("ui.update_screen();")); Serial.flush();
  ui.update_screen();

  if (x0x_leds_flag.consume()) {
    Serial.print("Write x0x_leds: ");
    
    x0x_leds.writeGPIOAB(x0x_leds_values_);
  }
}

uint16_t Application::x0x_leds_values() {
  return x0x_leds_values_;
}

void Application::write_x0x_leds_xor(uint16_t const & value) {
  write_x0x_leds(x0x_leds_values() ^ value);
}

void Application::write_x0x_leds(uint16_t const & value) {
  x0x_leds.writeGPIOAB(value);
}

void Application::flag_main_screen() {
  ui.flag_screen(ui_t::SCREEN_MAIN);
}

uint8_t Application::page() {
  uint8_t tmp_tick        = timer1.ticker() >> 1;
  uint8_t tmp_inside_tick = tmp_tick % _tracks.max_mod_maj();

  return                    tmp_inside_tick /  16;
}

void Application::set_playback_state(bool playback_state_) {
  timer1.set_playback_state(playback_state_);

  ui_data.redraw_playback_state.flag();

  flag_main_screen();

  eeprom.flag_save_requested();
}

void Application::save_state() {
   eeprom.save_all(
     Eeprom::PersistantData<tracks_t>(
       &_tracks,
       timer1.bpm(),
       timer1.playback_state()
     )
   );
}

void Application::flag_controls() {
  controls_flag.flag();
}

void Application::flag_output(uint8_t output) {
#ifdef LOG_OUTPUT
  Serial.print(F("Flagging: ")); Serial.flush();
  
  print_bits(output);

  Serial.println(); Serial.flush();
#endif
  
  queued_output = output;

  output_flag.flag();
}

bool Application::process_control_events() {
  if (! controls_flag.consume())
    return false;

  // Serial.println(F("control_event_source.poll();")); Serial.flush();
  control_event_source.poll();

  // Serial.println(F("dequeue...")); Serial.flush();
  while(process_control_event(control_event_source.dequeue_event()));

  // Serial.println(F("return...")); Serial.flush();
  return true;
}

uint16_t flip_bytes(uint16_t value) {
  uint8_t a = value >> 8;
  uint8_t b = value &  0xff;
  
  return (((uint16_t)b) << 8) | a; 
}

bool Application::process_control_event(
  Application::control_event_source_t::event_t e
) {
  if (! e) {
    return false;
  }
  if ((e.type >= 20) && (e.type <= 27)) {
    ProcessTrackControl<Event::event_type_t, 8>::apply(
      _tracks.current(),
      ((EventType)(e.type - 20))
    );
    
    ui_data.redraw_track.flag();
    ui_data.redraw_selected_track_indicator.flag();

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
      
      x0x_leds_flag.flag();

      goto success;
    }
    case EventType::EVT_SELECTED_TRACK_UP:
    {
      _tracks++;

      ui_data.redraw_track.flag();
      ui_data.redraw_selected_track_indicator.flag();

      Serial.print("GO UP A TRACK TO "); Serial.flush();
      Serial.print(_tracks.index()); //  Serial.flush();
      Serial.println(); Serial.flush();

      break;
    }
    case EventType::EVT_SELECTED_TRACK_DN:
    {
      _tracks--;
      
      ui_data.redraw_track.flag();
      ui_data.redraw_selected_track_indicator.flag();
      
      Serial.print("GO DOWN A TRACK TO "); Serial.flush();
      Serial.print(_tracks.index()); Serial.flush();
      Serial.println(); Serial.flush();
      
      break;
    }
    case EventType::EVT_PLAYBACK_STATE_TOGGLE:
    {
      set_playback_state(! timer1.playback_state());
      
      eeprom.flag_save_requested();
      
      goto success;
    }
    case EventType::EVT_BPM_SET:
    {
      timer1.set_bpm(e.parameter);

      ui_data.popup_bpm_requested.flag();
      
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
