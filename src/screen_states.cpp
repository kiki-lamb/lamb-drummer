#include "screen_states.h"

void SSNone::impl_enter(SSIntro::data_t d) {
}

void SSNone::impl_update(SSIntro::data_t d) {
}

void SSInstr::impl_enter(SSInstr::data_t d) {
}

void SSInstr::impl_update(SSInstr::data_t d) {
}

void SSIntro::impl_enter(SSIntro::data_t d) {
  lcd().setCursor(0, 0);
  lcd().print(F("    Lamb Drummer    "));

  static const int MS = 10;

  for (uint8_t iix = 0; iix < 4; iix++) {
    for (uint8_t ix = 0; ix < 20; ix++) {
      for (uint8_t iiix = 1; iiix < 4; iiix++) {
        lcd().setCursor(ix, iiix);
        lcd().print(F(" ")); // write(Lcd::CHAR_REST);
      }
      delay(MS);
    }

    for (uint8_t ix = 0; ix < 20; ix++) {
      for (uint8_t iiix = 1; iiix < 4; iiix++) {
        lcd().setCursor(ix, iiix);
        lcd().write(Lcd::CHAR_HIT);
      }
      delay(MS);
    }
  }

  for (uint8_t ix = 0; ix < 20; ix++) {
    for (uint8_t iiix = 1; iiix < 4; iiix++) {
      lcd().setCursor(ix, iiix);
      lcd().print(F(" "));
    }
    delay(MS);
  }

  delay(300);

  lcd().clear();

  delay(300);
}

void SSIntro::impl_update(SSIntro::data_t d) {
}
