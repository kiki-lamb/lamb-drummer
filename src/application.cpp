#include "application.h"
#include "ui_data.h"
#include "track_state_control_binding.h"

IControls *           Application::controls(new Application::controls_t(&Application::bpm));
Application::tracks_t Application::tracks;
Eeprom                Application::eeprom;
Timer1_               Application::timer1;
Timer2_               Application::timer2;
Application::ui_t     Application::ui;
Flag                  Application::popup_bpm_requested("rst", true);
Flag                  Application::redraw_track("rps", true);
Flag                  Application::redraw_selected_track_indicator("pbr", false);
Flag                  Application::redraw_playback_state("ti" , false);

Application::Application() {};

Application::~Application() {};

Application::ui_data_t Application::ui_data() {
  return ui_data_t(
    &tracks,  //  tracks_t const * track_states_,
    page(),  //  uint8_t          page_,
    timer1.bpm(),  //  uint8_t          bpm_,
    timer1.hz(),  //  double           hz_,
    timer1.playback_state(),  //  bool             playback_state_,
    timer1.ticker(),  //  uint8_t          ticker_,
    &popup_bpm_requested,  //  Flag *           popup_bpm_requested_,
    &redraw_track,  //  Flag *           redraw_track_,
    &redraw_selected_track_indicator,  //  Flag *           redraw_selected_track_indicator_,
    &redraw_playback_state  //  Flag *           redraw_playback_state_
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
      0, //
      0, //
      0, //
      0, //
      false, //
      0, //
      &popup_bpm_requested, //
      &redraw_track, //
      &redraw_selected_track_indicator, //
      &redraw_playback_state //
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

uint8_t Application::bpm() {
  return timer1.bpm();
}

uint8_t Application::page() {
  uint8_t tmp_tick        = timer1.ticker() >> 1;
  uint8_t tmp_inside_tick = tmp_tick % tracks.max_mod_maj();
  uint8_t tmp_page        = tmp_inside_tick /  16;
  return tmp_page;
}

void Application::set_playback_state(bool playback_state_) {
  timer1.set_playback_state(playback_state_);
  redraw_playback_state.flag();
  flag_main_screen();
  eeprom.flag_save_requested();
}

void Application::save_state() {
   eeprom.save_all(
     Eeprom::PersistantData<tracks_t>(
       &tracks,
       bpm(),
       timer1.playback_state()
     )
   );
}

void Application::restore_state() {
  Eeprom::PersistantData<tracks_t> tmp(
    &tracks,
    timer1.bpm(),
    timer1.playback_state()
  );
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
    redraw_track.flag();
    redraw_selected_track_indicator.flag();
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
        popup_bpm_requested.flag();
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
