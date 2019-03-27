#include "application.h"
#include "ui_data.h"

Application::control_event_source_t *
                          Application::control_event_source;
Application::tracks_t     Application::_tracks;
Eeprom                    Application::eeprom;
Timer1_                   Application::timer1;
Timer2_                   Application::timer2;
Application::ui_t         Application::ui(&ui_data);
Application::ui_data_t    Application::ui_data;

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
  Serial .begin(115200);
  Serial .println();
  Serial .println(F("Begin setup"));
  ui     .setup();
  ui     .enter_screen(ui_t::SCREEN_INTRO);
  Eeprom::PersistantData<tracks_t> tmp(
    &_tracks,
    timer1.bpm(),
    timer1.playback_state()
  );
  eeprom .restore_all(tmp);
  Serial .print(F("Found BPM in EEPROM: "));
  Serial .println(tmp.bpm);
  control_event_source =
    new Application::control_event_source_real_t(tmp.bpm);
  cli();
  timer1 .setup();
  timer1 .set_bpm(tmp.bpm);
  timer2 .setup();
  set_playback_state(tmp.playback_state);
  eeprom .unflag_save_requested();
  ui_data.tracks = &_tracks;
  update_ui_data();
  ui     .flag_screen (ui_t::SCREEN_MAIN);
  ui     .enter_screen(ui_t::SCREEN_MAIN);
  sei();
  Serial .println(F("Setup complete."));
  Serial .println();
}

void Application::loop() {
  const uint16_t frame_rate  = 32;
  const uint16_t frame_delay = 1000 / frame_rate;

  update_ui_data();

  // v roughly 4 hz. this is mainly so that popups (like BPM) are still
  // removed in a faily timely maner when playback is paused or when
  // bpm is set absurdly low.
  static uint8_t clk = 0;
  if (clk++ & 0b111)
    flag_main_screen();

  ui.update_screen();
  delay(frame_delay);
}

Application::tracks_t const & Application::tracks() {
  return _tracks;
}

void Application::flag_main_screen() {
  ui.flag_screen(ui_t::SCREEN_MAIN);
}

uint8_t Application::bpm() {
  return timer1.bpm();
}

uint8_t Application::page() {
  uint8_t tmp_tick        = timer1.ticker() >> 1;
  uint8_t tmp_inside_tick = tmp_tick % _tracks.max_mod_maj();
  uint8_t tmp_page        = tmp_inside_tick /  16;
  return  tmp_page;
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
       bpm(),
       timer1.playback_state()
     )
   );
}

void Application::process_control_events() {
  control_event_source->poll();
  while(process_control_event(control_event_source->dequeue_event()));
}

bool Application::process_control_event(Application::control_event_source_t::event_t e) {
  if (e.type == ControlEventType::EVT_NOT_AVAILABLE)
    return false;

  if (e.type < 8) {
    ProcessTrackControlEvent<control_event_source_t>::apply(
      _tracks.current(),
      e
    );

    Serial.print(F(" for track "));
    Serial.print(_tracks.index());
    Serial.println();
    ui_data.redraw_track.flag();
    ui_data.redraw_selected_track_indicator.flag();
  #define SET_FLAGS_AND_RETURN_TRUE flag_main_screen(); eeprom.flag_save_requested(); return true;
    SET_FLAGS_AND_RETURN_TRUE;
  }
  else {
    switch (e.type) {
      case ControlEventType::EVT_PLAYBACK_STATE_TOGGLE:
        set_playback_state(! timer1.playback_state());
        SET_FLAGS_AND_RETURN_TRUE;
        break;
      case ControlEventType::EVT_BPM_SET:
        timer1.set_bpm(e.parameter);
        ui_data.popup_bpm_requested.flag();
        SET_FLAGS_AND_RETURN_TRUE;
#undef SET_FLAGS
        break;
    }

    return false;
  }
}
