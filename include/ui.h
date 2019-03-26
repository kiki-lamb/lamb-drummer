#ifndef SHELF_CLOCK_UI_H
#define SHELF_CLOCK_UI_H

#include "lcd.h"
#include "i_screen_state.h"
#include "flag.h"

class Ui {
  friend class SSMain;

  public:
    template <class tracks_t>
    class UiData {
    public:
      tracks_t const * track_states;
      uint8_t page;
      uint8_t bpm;
      double  hz;
      bool    playback_state;
      uint8_t ticker;

      UiData(
        tracks_t const * track_states_,
        uint8_t          page_,
        uint8_t          bpm_,
        double           hz_,
        bool             playback_state_,
        uint8_t          ticker_
      ) :
  		  track_states(track_states_),
  			page(page_),
  			bpm(bpm_),
  			hz(hz_),
  			playback_state(playback_state_),
  			ticker(ticker_)
      {};

      virtual ~UiData() {};
    };

    enum screen_t {
			SCREEN_INTRO,
			SCREEN_NONE,
			SCREEN_MAIN,
			SCREEN_INSTR
		};

    static void           setup           ();
    static void           flag_popup_bpm  ();
    static void           flag_screen     (screen_t screen);
    static void           flag_redraw_track(uint8_t track);
    static void           flag_redraw_selected_track_indicator();
    static void           flag_redraw_playback_state();

    template <class tracks_t>
    static void update_screen(UiData<tracks_t> data) {
      screen_states[current_screen]->update();
    }

    template <class tracks_t>
    static void enter_screen(screen_t screen, UiData<tracks_t> data) {
      if (screen == current_screen)
        return;
      current_screen = screen;
      screen_states[screen]->enter();
    }

  private:
    Ui();
    ~Ui();
    static screen_t       current_screen;
    static IScreenState * screen_states[4];
    static Flag           popup_bpm_requested;
    static Flag           redraw_bpm;
    static Flag           redraw_track;
    static Flag           redraw_selected_track_indicator;
    static Flag           redraw_playback_state;
    static uint8_t        track_flagged_for_redraw;
};

#endif
