#ifndef SHELF_CLOCK_UI_H
#define SHELF_CLOCK_UI_H

#include <lamb.h>
#include "screens/screen.h"
#include "screens/screen_main.h"
#include "screens/screens.h"

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
      screens[current_screen]->update();
    }

    void enter_screen(screen_t screen) {
      if (screen == current_screen)
        return;
      current_screen = screen;
      screens[screen]->enter();
    }

    void setup() {
      Lcd::setup();
    }

    void flag_screen(screen_t screen) {
      screens[screen]->flag();
    }

    Ui(data_t * data_) :
      data(data_),
			current_screen(SCREEN_NONE),
      screens()
    {
      screens[0] = new SSIntro(data);
      screens[1] = new SSNone (data);
      screens[2] = new SSMain (data);
      screens[3] = new SSInstr(data);
    }

    virtual ~Ui() {}

  private:
    data_t * data;
    screen_t               current_screen;
    Screen<data_t> * screens[4];
};

#endif
