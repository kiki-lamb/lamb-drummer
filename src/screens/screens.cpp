#include "screens/screens.h"

SSNone::SSNone(
  SSNone::data_t * data
) : Screen<SSNone::data_t>(data) {}

SSIntro::SSIntro(
  SSIntro::data_t * data
) : Screen<SSIntro::data_t>(data) {}

SSInstr::SSInstr(
  SSInstr::data_t * data
) : Screen<SSIntro::data_t>(data) {}

void SSNone::impl_enter() {
}

void SSNone::impl_update() {
}

void SSInstr::impl_enter() {
}

void SSInstr::impl_update() {
}

void SSIntro::impl_enter() {
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

void SSIntro::impl_update() {
}
