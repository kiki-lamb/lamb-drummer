#ifndef SHELF_CLOCK_UI_H
#define SHELF_CLOCK_UI_H

#include "lcd.h"
#include "i_screen_state.h"
#include "flag.h"
#include "screen_state_main.h"
#include "screen_states.h"

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

    void update_screen() {
      screen_states[current_screen]->update(data);
    }

    void enter_screen(screen_t screen) {
      if (screen == current_screen)
        return;
      current_screen = screen;
      screen_states[screen]->enter(data);
    }

    // void flag_redraw_selected_track_indicator() {
    //   redraw_selected_track_indicator.flag();
    // }
    //
    // void flag_redraw_playback_state() {
    //   redraw_playback_state.flag();
    // }
    //
    // void flag_redraw_track(uint8_t track) {
    //   redraw_track.flag();
    //   track_flagged_for_redraw = track;
    // }
    //
    // void flag_popup_bpm() {
    //   popup_bpm_requested.flag();
    //   flag_screen(SCREEN_MAIN);
    // }

    void setup(data_t * data_) {
      data = data;
      Lcd::setup();
    }

    void flag_screen(screen_t screen) {
      screen_states[screen]->flag();
    }

    Ui() :
			current_screen(SCREEN_NONE),
      screen_states()
    {
      screen_states[0] = new SSIntro();
      screen_states[1] = new SSNone ();
      screen_states[2] = new SSMain (
        // &popup_bpm_requested,
        // &redraw_playback_state,
        // &redraw_selected_track_indicator,
        // &redraw_track
      );
      screen_states[3] = new SSInstr();
    }

    virtual ~Ui() {}

  private:
    data_t * data;
    screen_t               current_screen;
    IScreenState<data_t> * screen_states[4];
};

#endif
