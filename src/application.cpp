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
jm_PCF8574                Application::output_device;
uint8_t                   Application::queued_output = 0xff;

Application::Application() {};

Application::~Application() {};

void Application::update_ui_data() {
  ui_data.page           = page();
  ui_data.bpm            = timer1.bpm();
  ui_data.hz             = timer1.hz();
  ui_data.playback_state = timer1.playback_state();
  ui_data.ticker         = timer1.ticker();
}

void Application::setup() {
  Serial .begin(230400);
  Wire   .begin();
  Wire   .setClock(100000);
  
  output_device.begin(0x3A);
  for (uint8_t ix = 0; ix < 8; ix++) {
    output_device.pinMode(ix, OUTPUT);
  }

  output_device.write(0xff);
  uint16_t step = 150;

  ui     .setup();
  ui     .enter_screen(ui_t::SCREEN_INTRO);

  while (false) {
    output_device.write(0b11111110);
    delay(step);
    output_device.write(0b11111111);
    delay(step);

    output_device.write(0b11111011);
    delay(step);
    output_device.write(0b11111111);
    delay(step);

    output_device.write(0b11111100);
    delay(step);
    output_device.write(0b11111111);
    delay(step);

    output_device.write(0b11111011);
    delay(step);
    output_device.write(0b11111111);
    delay(step);
  }
  
  Eeprom::PersistantData<tracks_t> tmp(
    &_tracks,
    timer1.bpm(),
    timer1.playback_state()
  );

  eeprom .restore_all(tmp);

  setup_controls(tmp.bpm);
  
  cli();
  Serial.println(F("Stop all interrupts..."));
  
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

  Serial.println(F("Enable all interrupts."));
  sei();
  
  Serial.println(F("Enter SCREEN_MAIN..."));
  ui     .enter_screen(ui_t::SCREEN_MAIN);
  Serial.println(F("Entered SCREEN_MAIN."));
}

void Application::setup_controls(uint8_t bpm) {
  static ButtonpadSource<Buttonpad_MCP23017<0x0, 8, 8> >
                       buttonpad_source;
//  static EncoderSource encoder_source(EventType::EVT_BPM_SET, bpm);
//  static ButtonSource  button_source(
//    EventType::EVT_PLAYBACK_STATE_TOGGLE,
//    A7
//  );
//  static CombineEventSources<Event,3>
//                       combine_event_sources;
  buttonpad_source     .setup();
//  encoder_source       .setup();
//  button_source.setup();
//  combine_event_sources.sources[0] = &buttonpad_source;
//  combine_event_sources.sources[1] = &encoder_source;
//  combine_event_sources.sources[2] = &button_source;
  control_event_source .source     = &buttonpad_source; //combine_event_sources;
}

void Application::print_bits(uint8_t t0) {
  {
    for(uint16_t mask = 0x80; mask; mask >>= 1) {
      if (mask & t0)
        Serial.print('1');
      else
        Serial.print('0');
    }
  }
}

void Application::loop() {
  const uint16_t frame_delay = 10;
  // v roughly 6.25 hz. this is mainly so that popups (like BPM) are still
  // removed in a faily timely manner when playback is paused or when
  // bpm is set absurdly low.
  static uint8_t clk = 0;

  if (clk++ & 0b111) {
    flag_main_screen();
  }

  if (output_flag.consume()) {
#ifdef LOG_OUTPUT
    Serial.print("Output: ");
    print_bits(queued_output);
    Serial.println();
#endif
    
    output_device.write(queued_output);
  }
  
  if (controls_flag.consume()) {
    process_control_events();
  }
    
  update_ui_data();

  ui.update_screen();

  // delay(frame_delay);
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
  Serial.print("Flagging: ");
  print_bits(output);
  Serial.println();
#endif
  
  queued_output = output;

  output_flag.flag();
}

void Application::process_control_events() {
  control_event_source.poll();
  while(process_control_event(control_event_source.dequeue_event()));
}

bool Application::process_control_event(
  Application::control_event_source_t::event_t e
) {
  if (! e)
    return false;
  if (e.type < 8) {
    ProcessTrackControl<Event::event_type_t, 8>::apply(
      _tracks.current(),
      e.type
    );
    ui_data.redraw_track.flag();
    ui_data.redraw_selected_track_indicator.flag();
    goto success;
  }
  else {
    switch (e.type) {
    case EventType::EVT_SELECTED_TRACK_UP:
      _tracks++;
      ui_data.redraw_track.flag();
      ui_data.redraw_selected_track_indicator.flag();
      Serial.print("GO UP A TRACK TO ");
      Serial.print(_tracks.index()); // 
      Serial.println();
      break;
    case EventType::EVT_SELECTED_TRACK_DN:
      _tracks--;
      ui_data.redraw_track.flag();
      ui_data.redraw_selected_track_indicator.flag();
      Serial.print("GO DOWN A TRACK TO ");
      Serial.print(_tracks.index());
      Serial.println();
      break;      
    case EventType::EVT_PLAYBACK_STATE_TOGGLE:
      set_playback_state(! timer1.playback_state());
      goto success;
    case EventType::EVT_BPM_SET:
      timer1.set_bpm(e.parameter);
      ui_data.popup_bpm_requested.flag();
      goto success;
    }
    return false;
    success:
      flag_main_screen();
      eeprom.flag_save_requested();
      return true;
  }
}
