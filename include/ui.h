#ifndef SHELF_CLOCK_UI_H
#define SHELF_CLOCK_UI_H

#include "lcd.h"
#include "i_screen_state.h"
#include "flag.h"
#include "screen_states.h"
#include "screen_state_main.h"

template <class data_t>
class Ui {
  friend class SSMain;

  public:
    enum screen_t {
			SCREEN_INTRO,
			SCREEN_NONE,
			SCREEN_MAIN,
			SCREEN_INSTR
		};

    void update_screen(data_t data) {
      screen_states[current_screen]->update();
    }

    void enter_screen(screen_t screen, data_t data) {
      if (screen == current_screen)
        return;
      current_screen = screen;
      screen_states[screen]->enter();
    }

    void flag_redraw_selected_track_indicator() {
      redraw_selected_track_indicator.flag();
    }

    void flag_redraw_playback_state() {
      redraw_playback_state.flag();
    }

    void flag_redraw_track(uint8_t track) {
      redraw_track.flag();
      track_flagged_for_redraw = track;
    }

    void flag_popup_bpm() {
      popup_bpm_requested.flag();
      flag_screen(SCREEN_MAIN);
    }

    void setup() {
      Lcd::setup();
    }

    void flag_screen(screen_t screen) {
      screen_states[screen]->flag();
    }

    Ui() :
		  redraw_selected_track_indicator("rst", true),
			redraw_playback_state          ("rps", true),
			redraw_bpm                     ("rb" , false),
			popup_bpm_requested            ("pbr", false),
			redraw_track                   ("ti" , false),
			track_flagged_for_redraw(0),
			current_screen(SCREEN_NONE),
      screen_states()
    {
      screen_states[0] = new SSIntro();
      screen_states[1] = new SSNone ();
      screen_states[2] = new SSNone ();
//      screen_states[2] = new SSMain ();
      screen_states[3] = new SSInstr();
    }

    ~Ui() {}

  private:
    screen_t       current_screen;
    IScreenState<data_t> * screen_states[4];
    Flag           popup_bpm_requested;
    Flag           redraw_bpm;
    Flag           redraw_track;
    Flag           redraw_selected_track_indicator;
    Flag           redraw_playback_state;
    uint8_t        track_flagged_for_redraw;
};

#endif
