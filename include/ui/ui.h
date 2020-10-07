#ifndef LAMB_DRUMMER_UI_H
#define LAMB_DRUMMER_UI_H

#include <lamb.h>
#include "screens/screen.h"
#include "screens/screen_main.h"
#include "screens/screens.h"

template <class data_t>
class ui {
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

  void enter_screen(screen_t const & screen) {
    if (screen == current_screen)
      return;
    current_screen = screen;
    flag_screen(current_screen);
    screens[current_screen]->enter();
  }

  void setup() {
    lcd::setup();
  }

  void flag_screen(screen_t const & screen) {
    screens[screen]->flag();
  }

  ui(data_t * data_) :
    data(data_),
    current_screen(SCREEN_NONE),
    screens()
    {
      screens[0] = new screen_intro(data);
      screens[1] = new screen_none (data);
      screens[2] = new screen_main (data);
      screens[3] = new screen_instr(data);
    }

  virtual ~ui() {}

private:
  data_t         * data;
  screen_t         current_screen;
  screen<data_t> * screens[4];
};

#endif
