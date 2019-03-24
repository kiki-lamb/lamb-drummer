#include "application.h"
#include "ui.h"
#include "track_state_control_binding.h"

Controls<Application::buttonpad_t> Application::controls(&Application::bpm);
static Application::collection_t   Application::_track_states;
static Eeprom                      Application::eeprom;
static Timer1_                     Application::timer1;
static Timer2_                     Application::timer2;

Application::Application() {};

Application::~Application() {}

static void Application::setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("Begin setup"));

  controls .setup();
  Ui      ::setup();
  Ui      ::enter_screen(Ui::SCREEN_INTRO);

  cli();
  timer1   .setup();
  timer2   .setup();
  sei();
  restore_state();

  Ui      ::enter_screen(Ui::SCREEN_MAIN);

  Serial.println(F("Setup complete."));
  Serial.println();
}

static void Application::loop() {
  const uint16_t frame_rate  = 80;
  const uint16_t frame_delay = 1000 / frame_rate;

  Ui::update_screen();
  delay(frame_delay);
}

static Application::collection_t const & Application::track_states() {
  return _track_states;
}

static void Application::flag_main_screen() {
  Ui::flag_screen(Ui::SCREEN_MAIN);
}

static double Application::hz() {
  return timer1.hz();
}

static uint8_t Application::bpm() {
  return timer1.bpm();
}

static uint8_t Application::ticker() {
  return timer1.ticker();
}

static uint8_t Application::page() {
  uint8_t tmp_tick        = timer1.ticker() >> 1;
  uint8_t tmp_inside_tick = tmp_tick % _track_states.max_mod_maj();
  uint8_t tmp_page        = tmp_inside_tick /  16;

  return tmp_page;
}

static bool Application::playback_state() {
  return timer1.playback_state();
}

static void Application::set_playback_state(bool playback_state_) {
  timer1.set_playback_state(playback_state_);
  Ui::flag_redraw_playback_state();
  flag_main_screen();
  eeprom.flag_save_requested();
}

static void Application::save_state() {
  eeprom.save_all( Eeprom::PersistantData<collection_t>(&_track_states, bpm(), playback_state()) );
}

static void Application::restore_state() {
  Eeprom::PersistantData<collection_t> tmp(&_track_states, bpm(), playback_state());
  eeprom.restore_all(tmp);
  controls.set_encoder(tmp.bpm);
  timer1.set_bpm(tmp.bpm); 
  Application::set_playback_state(tmp.playback_state);
}

static void Application::process_controls() {
#define SET_FLAGS flag_main_screen(); eeprom.flag_save_requested();

  controls.poll();

  if (controls.bpm_changed.consume()) {
    timer1.set_bpm(controls.bpm());
    Ui     ::flag_popup_bpm();
    SET_FLAGS;
  }

  if (controls.encoder_button_pressed .consume())
    set_playback_state(! timer1.playback_state());

  if (controls.buttonpad_button_pressed.consume() && IButtonpad::BTN_NONE != controls.buttonpad_button()) {
    Serial.print(F("Caught button "));
    Serial.print(controls.buttonpad_button());
    Serial.print(F(" for track "));
    Serial.print(_track_states.index());
    Serial.println();

    if ( 
      TrackStateButtonProcessor::handle_button(
        _track_states.current(),
        controls.buttonpad_button()
      )
    ) {
      Ui::flag_redraw_track(_track_states.index());
      Ui::flag_redraw_selected_track_indicator();
      SET_FLAGS;
    }
  }
  
#undef SET_FLAGS
}



