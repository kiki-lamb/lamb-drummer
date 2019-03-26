#include "ui.h"
#include "screen_states.h"
#include "screen_state_main.h"

Flag           Ui::redraw_selected_track_indicator("rst", true);
Flag           Ui::redraw_playback_state          ("rps", true);
Flag           Ui::redraw_bpm                     ("rb" , false);
Flag           Ui::popup_bpm_requested            ("pbr", false);
Flag           Ui::redraw_track                   ("ti" , false);
uint8_t        Ui::track_flagged_for_redraw      = 0;
Ui::screen_t   Ui::current_screen                = SCREEN_NONE;

IScreenState * Ui::screen_states[4]              = {
  new SSIntro(), new SSNone(), new SSMain(), new SSInstr()
};

void Ui::flag_redraw_selected_track_indicator() {
  redraw_selected_track_indicator.flag();
}

void Ui::flag_redraw_playback_state() {
  redraw_playback_state.flag();
}

void Ui::flag_redraw_track(uint8_t track) {
  redraw_track.flag();
  track_flagged_for_redraw = track;
}

void Ui::flag_popup_bpm() {
  popup_bpm_requested.flag();
  flag_screen(SCREEN_MAIN);
}

void Ui::setup() {
  Lcd::setup();
}

void Ui::flag_screen(screen_t screen) {
  screen_states[screen]->flag();
}

void Ui::update_screen() {
  screen_states[current_screen]->update();
}

void Ui::enter_screen(screen_t screen) {
  if (screen == current_screen)
    return;
  current_screen = screen;
  screen_states[screen]->enter();
}

Ui::Ui() {};

Ui::~Ui() {}
