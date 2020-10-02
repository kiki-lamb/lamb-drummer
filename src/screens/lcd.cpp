#include "Arduino.h"
#include "screens/lcd.h"

#include "LiquidCrystal_I2C.h"

Lcd::Lcd() {}
Lcd::~Lcd() {}

void Lcd::setup() {
  lcd.init();
  lcd.backlight();

  for (uint8_t ix = 0; ix < 8; ix++)
    lcd.createChar(ix, (uint8_t *)(custom_chars[ix]));
}

const uint8_t Lcd::LCD_COLS  = 20;
const uint8_t Lcd::LCD_LINES = 4;
const uint8_t Lcd::LCD_RS    = 12;
const uint8_t Lcd::LCD_EN    = 11;
const uint8_t Lcd::LCD_D4    = 10;
const uint8_t Lcd::LCD_D5    = 8;
const uint8_t Lcd::LCD_D6    = 7;
const uint8_t Lcd::LCD_D7    = 4;

LiquidCrystal_I2C Lcd::lcd(0x27, 20, 4);

// new ////////////////////////////////////////////////////////////////////////
void Lcd::clear() {
  lcd.clear();
}

void Lcd::set_cursor(uint8_t x, uint8_t y) {
  lcd.setCursor(x, y);
}

void Lcd::write(uint8_t byte) {
  lcd.write(byte);
}

///////////////////////////////////////////////////////////////////////////////                                                                               
void Lcd::put_inversion(
  uint8_t col,
  uint8_t line,
  uint8_t number
) {
  select_inversion(number);
  lcd.setCursor(col, line);
  lcd.write(byte(CHAR_INVERSION));
}

void Lcd::select_inversion(uint8_t number) {
  static const uint8_t inversions[][8] = {
    {
      0b10001,
      0b01110,
      0b01100,
      0b01010,
      0b00110,
      0b01110,
      0b10001,
      0b11111
    },
    {
      0b11111,
      0b11011,
      0b10011,
      0b11011,
      0b11011,
      0b11011,
      0b10001,
      0b11111
    },
    {
      0b11111,
      0b10001,
      0b01110,
      0b11101,
      0b11011,
      0b10111,
      0b00000,
      0b11111
    },
    {
      0b11111,
      0b00000,
      0b11101,
      0b11011,
      0b11101,
      0b01110,
      0b10001,
      0b11111
    }
  };

  lcd.createChar(CHAR_INVERSION, const_cast<uint8_t *>(inversions[number]));
}

void Lcd::put_playstate(uint8_t col, uint8_t line) {
  lcd.setCursor(col, line);
  lcd.write(byte(CHAR_PLAYSTATE));
}

void Lcd::select_playstate(bool paused) {
  static const uint8_t playstates[][8] = {
    {
      0b11011, // CHAR_PAUSE
      0b11011,
      0b11011,
      0b11011,
      0b11011,
      0b11011,
      0b11011,
      0b00000
    },
    {
      0b10000, // CHAR_PLAY
      0b11000,
      0b11100,
      0b11110,
      0b11100,
      0b11000,
      0b10000,
      0b00000
    }
  };

  lcd.createChar(CHAR_PLAYSTATE, const_cast<uint8_t *>(playstates[paused ? 0 : 1]));
}

const uint8_t Lcd::custom_chars[8][8] = {
  {
    0b00000, // CHAR_REST
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00100,
    0b00000
  },
 {
    0b11111, // CHAR_REST_ACTIVE
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11011,
    0b11111
  },
  {
    0b11111, // CHAR_INVERSION
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b00000
  },
  {
    0b00100, // CHAR_REST_BARRIER
    0b00000,
    0b00100,
    0b00000,
    0b00100,
    0b00000,
    0b00100,
    0b00000
  },
  {
    0b01110, // CHAR_HIT
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00000
  },
  {
    0b11111, // CHAR_HIT_ACTIVE
    0b10001,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b10001,
    0b11111
  },
  {
    0b00000, // CHAR_PLAYSTATE
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
  },
  {
    0b01110, // CHAR_HIT_BARRIER
    0b11011,
    0b11111,
    0b11011,
    0b11111,
    0b11011,
    0b01110,
    0b00000
  }
};
