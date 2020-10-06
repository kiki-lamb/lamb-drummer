#include "screens/screens.h"

screen_none::screen_none(
  screen_none::data_t * data
) : screen<screen_none::data_t>(data) {}

screen_intro::screen_intro(
  screen_intro::data_t * data
) : screen<screen_intro::data_t>(data) {}

screen_instr::screen_instr(
  screen_instr::data_t * data
) : screen<screen_intro::data_t>(data) {}

void screen_none::impl_enter() {
}

void screen_none::impl_update() {
}

void screen_instr::impl_enter() {
}

void screen_instr::impl_update() {
}

void screen_intro::impl_enter() {
  lcd::set_cursor(0, 0);
  lcd::print(F("    Lamb Drummer    "));

  static const int MS = 2;

  for (uint8_t iix = 0; iix < 4; iix++) {
    for (uint8_t ix = 0; ix < 20; ix++) {
      for (uint8_t iiix = 1; iiix < 4; iiix++) {
        lcd::set_cursor(ix, iiix);
        lcd::print(F(" ")); // write(lcd::CHAR_REST);
      }
      delay(MS);
    }

    for (uint8_t ix = 0; ix < 20; ix++) {
      for (uint8_t iiix = 1; iiix < 4; iiix++) {
        lcd::set_cursor(ix, iiix);
        lcd::write(lcd::CHAR_HIT);
      }
      delay(MS);
    }
  }

  for (uint8_t ix = 0; ix < 20; ix++) {
    for (uint8_t iiix = 1; iiix < 4; iiix++) {
      lcd::set_cursor(ix, iiix);
      lcd::print(F(" "));
    }
    delay(MS);
  }

  lcd::clear();
}

void screen_intro::impl_update() {
}
