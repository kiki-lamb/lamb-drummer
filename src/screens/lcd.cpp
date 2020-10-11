#include "Arduino.h"
#include "screens/lcd.h"

#include "LiquidCrystal_I2C.h"

lcd::lcd() {}
// lcd::~lcd() {}

void lcd::setup() {
  device.init();
  device.backlight();

  for (uint8_t ix = 0; ix < 8; ix++)
    device.createChar(ix, (uint8_t *)(custom_chars[ix]));
}

const uint8_t lcd::LCD_COLS  = 20;
const uint8_t lcd::LCD_LINES = 4;
const uint8_t lcd::LCD_RS    = 12;
const uint8_t lcd::LCD_EN    = 11;
const uint8_t lcd::LCD_D4    = 10;
const uint8_t lcd::LCD_D5    = 8;
const uint8_t lcd::LCD_D6    = 7;
const uint8_t lcd::LCD_D7    = 4;

LiquidCrystal_I2C lcd::device(0x27, 20, 4);

// new ////////////////////////////////////////////////////////////////////////

void lcd::clear() {
#ifdef LOG_I2C_LOCK
  Serial.print(F("L:c  "));
#endif
  if (! lamb::i2c_lock::claim()) return;

  device.clear();

#ifdef LOG_I2C_LOCK
  Serial.print(F("L:c  "));
#endif
  lamb::i2c_lock::release();
}

void lcd::set_cursor(uint8_t const & x, uint8_t const &  y) {
#ifdef LOG_I2C_LOCK
  Serial.print(F("L:sc "));
#endif
  if (! lamb::i2c_lock::claim()) return;
  
  device.setCursor(x, y);

#ifdef LOG_I2C_LOCK
  Serial.print(F("L:sc "));
#endif
  lamb::i2c_lock::release();
}


size_t lcd::print_with_nulls(const char * buffer, size_t size) {
#ifdef LOG_I2C_LOCK
  Serial.print(F("L:pn  "));
#endif
  if (! lamb::i2c_lock::claim()) return 0;
  
  size_t n = 0;

  while (size--) {
    if (device.write(*buffer++)) n++;
    else break;
  }

#ifdef LOG_I2C_LOCK
  Serial.print(F("L:pn  "));
#endif
  lamb::i2c_lock::release();

  return n;
}

void lcd::write(uint8_t const & byte) {
#ifdef LOG_I2C_LOCK
  Serial.print(F("L:w  "));
#endif
  if (! lamb::i2c_lock::claim()) return;
      
  device.write(byte);

#ifdef LOG_I2C_LOCK
  Serial.print(F("L:w  "));
#endif
  lamb::i2c_lock::release();
}

//////////////////////////////////////////////////////////////////////////////

void lcd::put_inversion(
  uint8_t const & col,
  uint8_t const & line,
  uint8_t const & number
) {
  select_inversion(number);
  device.setCursor(col, line);
  device.write(byte(CHAR_INVERSION));
}

void lcd::select_inversion(uint8_t const & number) {
#ifdef LOG_I2C_LOCK
  Serial.print(F("L:si "));
#endif
  if (! lamb::i2c_lock::claim()) return;
  
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

  device.createChar(CHAR_INVERSION, const_cast<uint8_t *>(inversions[number]));

#ifdef LOG_I2C_LOCK
  Serial.print(F("L:si "));
#endif
  lamb::i2c_lock::release();
}

void lcd::put_playstate(uint8_t const & col, uint8_t const & line) {
#ifdef LOG_I2C_LOCK
  Serial.print(F("L:pp "));
#endif
  if (! lamb::i2c_lock::claim()) return;
  
  device.setCursor(col, line);
  device.write(byte(CHAR_PLAYSTATE));

#ifdef LOG_I2C_LOCK
  Serial.print(F("L:pp "));
#endif
  lamb::i2c_lock::release();
}

void lcd::select_playstate(bool const & paused) {
  if (! lamb::i2c_lock::claim()) return;
  
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

  device.createChar(
    CHAR_PLAYSTATE,
    const_cast<uint8_t *>(playstates[paused ? 0 : 1])
  );

  lamb::i2c_lock::release();
}

const uint8_t lcd::custom_chars[8][8] = {
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
