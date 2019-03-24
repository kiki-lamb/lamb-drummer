#include "ui.h"
#include "screen_states.h"
#include "screen_state_main.h"

Flag           Ui::redraw_selected_track("rst", true);
Flag           Ui::redraw_playback_state("rps", true);
Flag           Ui::redraw_bpm           ("rb" , false);
Flag           Ui::popup_bpm_requested  ("pbr", false);
Flag           Ui::track_invalidated    ("ti" , false);
uint8_t        Ui::invalidated_track    = 0;
Ui::screen_t   Ui::current_screen       = SCREEN_NONE;
IScreenState * Ui::screen_states[4]     = { new SSIntro(), new SSNone(), new SSMain(), new SSInstr() };

static void Ui::invalidate_track(uint8_t track) {
  track_invalidated.flag();
  invalidated_track = track;
}

static void Ui::popup_bpm() {
  popup_bpm_requested.flag();
  flag_screen(SCREEN_MAIN);
}

static void Ui::setup() {
  Lcd::setup();
}

static void Ui::update_screen() {
  screen_states[current_screen]->update();
}

static void Ui::flag_screen(screen_t screen) {
  screen_states[screen]->flag();
}

static void Ui::enter_screen(screen_t screen) {
  if (screen == current_screen)
    return;
  current_screen = screen;
  screen_states[screen]->enter();
}

Ui::Ui() {};

Ui::~Ui() {}
