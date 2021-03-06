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
    SCREEN_NONE,
    SCREEN_INTRO,
    SCREEN_MAIN
  };

  uint32_t last_update;
  
  bool update_screen() {
    uint32_t now = millis();
    uint32_t delta = now - last_update;

    if (delta < 200) return false;
        
    bool tmp = screens[current_screen]->update();

    if (tmp) {
      last_update = now;
    }
    else {
      screens[current_screen]->flag();
    }
    
    return tmp;
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
    last_update(0),
    data(data_),
    current_screen(SCREEN_NONE),
    screens()
    {
      screens[0] = new screen_none<data_t>(data);
      screens[1] = new screen_intro<data_t>(data);
      screens[2] = new screen_main<data_t>(data);
    }

private:
  data_t         * data;
  screen_t         current_screen;
  screen<data_t> * screens[3];
};

#endif
