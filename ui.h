#ifndef SHELF_CLOCK_UI_H
#define SHELF_CLOCK_UI_H

#include "lcd.h"
#include "i_screen_state.h"
#include "screen_states.h"
#include "flag.h"

class Ui {
  friend class SSMain;

  public:
    enum screen_t { SCREEN_INTRO, SCREEN_NONE, SCREEN_MAIN, SCREEN_INSTR };
    
    static void           setup           ();
    static void           update_screen   ();
    static void           popup_bpm       ();
    static void           flag_screen     (screen_t screen);
    static void           enter_screen    (screen_t screen);
    static void           invalidate_track(uint8_t track);

    static Flag           redraw_selected_track;
    static Flag           redraw_playback_state;
        
  private:
    Ui();
    ~Ui();
    static screen_t       current_screen;
    static IScreenState * screen_states[4];
    static Flag           popup_bpm_requested;
    static Flag           redraw_bpm;
    static Flag           track_invalidated;
    static uint8_t        invalidated_track;
};

#endif
