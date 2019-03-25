#include "application.h"
#include "ui.h"
#include "track_state_control_binding.h"

IControls * Application::controls(new Application::controls_t(&Application::bpm));
Application::track_collection_t   Application::_track_states;
Eeprom                      Application::eeprom;
Timer1_                     Application::timer1;
Timer2_                     Application::timer2;

Application::Application() {};

Application::~Application() {}

void Application::setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println(F("Begin setup"));

  controls->setup();
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

void Application::loop() {
  const uint16_t frame_rate  = 80;
  const uint16_t frame_delay = 1000 / frame_rate;

  Ui::update_screen();
  delay(frame_delay);
}

Application::track_collection_t const & Application::track_states() {
  return _track_states;
}

void Application::flag_main_screen() {
  Ui::flag_screen(Ui::SCREEN_MAIN);
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
  uint8_t tmp_inside_tick = tmp_tick % _track_states.max_mod_maj();
  uint8_t tmp_page        = tmp_inside_tick /  16;

  return tmp_page;
}

bool Application::playback_state() {
  return timer1.playback_state();
}

void Application::set_playback_state(bool playback_state_) {
  timer1.set_playback_state(playback_state_);
  Ui::flag_redraw_playback_state();
  flag_main_screen();
  eeprom.flag_save_requested();
}

void Application::save_state() {
  eeprom.save_all( Eeprom::PersistantData<track_collection_t>(&_track_states, bpm(), playback_state()) );
}

void Application::restore_state() {
  Eeprom::PersistantData<track_collection_t> tmp(&_track_states, bpm(), playback_state());
  eeprom.restore_all(tmp);
  controls->set_encoder(tmp.bpm);
  timer1.set_bpm(tmp.bpm); 
  Application::set_playback_state(tmp.playback_state);
}

void Application::process_controls() {
#define SET_FLAGS flag_main_screen(); eeprom.flag_save_requested();

  controls->poll();

// uint8_t tmp = controls->queue_count();

// if (0 != tmp) {
//    Serial.print(F("QUEUE HAS "));
//    Serial.print(controls->queue_count());
//    Serial.println(F(" EVENTS."));
//   }
  
  for (
        controls_t::ControlEvent e = controls->dequeue_event(); 
        e.type != controls_t::EVT_NOT_AVAILABLE; 
        e = controls->dequeue_event()) {

    Serial.print(F("Dequeue "));
    Serial.print(e.type);
    Serial.println();

    if (e.type < 8) {
      TrackStateEventProcessor<controls_t>::handle_event(_track_states.current(), e);
      Serial.print(F("Caught event "));
      Serial.print(e.type);
      Serial.print(F(" for track "));
      Serial.print(_track_states.index());
      Serial.println();
      Ui::flag_redraw_track(_track_states.index());
      Ui::flag_redraw_selected_track_indicator();
      SET_FLAGS;
    }
    else {
      switch (e.type) {
        case controls_t::EVT_PLAYBACK_STATE_TOGGLE:
          set_playback_state(! timer1.playback_state());
          break;
        case controls_t::EVT_BPM_SET:
          timer1.set_bpm(e.parameter);
          Ui     ::flag_popup_bpm();
          SET_FLAGS;
          break;
      }
    }
  }
  
#undef SET_FLAGS
}

