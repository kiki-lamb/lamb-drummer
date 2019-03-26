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
      screen_states[current_screen]->update();
    }

    void enter_screen(screen_t screen) {
      if (screen == current_screen)
        return;
      current_screen = screen;
      screen_states[screen]->enter();
    }

    void setup() {
      Lcd::setup();
    }

    void flag_screen(screen_t screen) {
      screen_states[screen]->flag();
    }

    Ui(data_t * data_) :
			current_screen(SCREEN_NONE),
      screen_states(),
      data(data_)
    {
      screen_states[0] = new SSIntro(data);
      screen_states[1] = new SSNone (data);
      screen_states[2] = new SSMain (data);
      screen_states[3] = new SSInstr(data);
    }

    virtual ~Ui() {}

  private:
    data_t * data;
    screen_t               current_screen;
    IScreenState<data_t> * screen_states[4];
};

#endif
