#include "application.h"
#include "ui.h"
#include "track_state_control_binding.h"

IControls *           Application::controls(new Application::controls_t(&Application::bpm));
Application::tracks_t Application::tracks;
Eeprom                Application::eeprom;
Timer1_               Application::timer1;
Timer2_               Application::timer2;
Application::ui_t     Application::ui;

Application::Application() {};

Application::~Application() {};

Application::ui_data_t Application::ui_data() {
  return ui_data_t(
    &tracks,
    page(),
    bpm(),
    hz(),
    playback_state(),
    ticker()
  );
}

void Application::setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("Begin setup"));

  controls->setup();
  ui       .setup();
  ui       .enter_screen(
    ui_t::SCREEN_INTRO,
    ui_data_t(
      0,
      0,
      0,
      0,
      false,
      0
    )
  );
  cli();
  timer1   .setup();
  timer2   .setup();
  sei();
  restore_state();
  ui       .enter_screen(ui_t::SCREEN_MAIN, ui_data());

  Serial.println(F("Setup complete."));
  Serial.println();
}

void Application::loop() {
  const uint16_t frame_rate  = 80;
  const uint16_t frame_delay = 1000 / frame_rate;

  ui.update_screen(ui_data());
  delay(frame_delay);
}

Application::tracks_t const & Application::track_states() {
  return tracks;
}

void Application::flag_main_screen() {
  ui.flag_screen(ui_t::SCREEN_MAIN);
}

double Application::hz() {
  return timer1.hz();
}

uint8_t Application::bpm() {
  return timer1.bpm();
}

uint8_t Application::ticker() {
  return timer1.ticker();
}

uint8_t Application::page() {
  uint8_t tmp_tick        = timer1.ticker() >> 1;
  uint8_t tmp_inside_tick = tmp_tick % tracks.max_mod_maj();
  uint8_t tmp_page        = tmp_inside_tick /  16;

  return tmp_page;
}

bool Application::playback_state() {
  return timer1.playback_state();
}

void Application::set_playback_state(bool playback_state_) {
  timer1.set_playback_state(playback_state_);
  ui.flag_redraw_playback_state();
  flag_main_screen();
  eeprom.flag_save_requested();
}

void Application::save_state() {
   eeprom.save_all(
     Eeprom::PersistantData<tracks_t>(
       &tracks,
       bpm(),
       playback_state()
     )
   );
}

void Application::restore_state() {
  Eeprom::PersistantData<tracks_t> tmp(&tracks, bpm(), playback_state());
  eeprom.restore_all(tmp);
  controls->set_encoder(tmp.bpm);
  timer1.set_bpm(tmp.bpm);
  Application::set_playback_state(tmp.playback_state);
  eeprom.unflag_save_requested();
}

void Application::process_control(Application::controls_t::ControlEvent & e) {
  Serial.print(F("Dequeue "));
  Serial.print(e.type);
  Serial.println();

  if (e.type < 8) {
    TrackStateEventProcessor<controls_t>::handle_event(
      tracks.current(),
      e
    );

    Serial.print(F(" for track "));
    Serial.print(tracks.index());
    Serial.println();
    ui.flag_redraw_track(tracks.index());
    ui.flag_redraw_selected_track_indicator();
  #define SET_FLAGS flag_main_screen(); eeprom.flag_save_requested();
    SET_FLAGS;
  }
  else {
    switch (e.type) {
      case controls_t::EVT_PLAYBACK_STATE_TOGGLE:
        set_playback_state(! timer1.playback_state());
        break;
      case controls_t::EVT_BPM_SET:
        timer1.set_bpm(e.parameter);
        ui    .flag_popup_bpm();
        SET_FLAGS;
#undef SET_FLAGS
        break;
    }
  }
}

void Application::process_controls() {
  controls->poll();

  for (
        controls_t::ControlEvent e = controls->dequeue_event();
        e.type != controls_t::EVT_NOT_AVAILABLE;
        e = controls->dequeue_event()
  ) process_control(e);
}
