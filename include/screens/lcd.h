#ifndef LAMB_DRUMMER_LCD_H
#define LAMB_DRUMMER_LCD_H

#include "LiquidCrystal_I2C.h"
#include "lamb.h"

class lcd {
private:
  lcd();
  static const uint8_t     LCD_COLS;
  static const uint8_t     LCD_LINES;
  static const uint8_t     LCD_RS;
  static const uint8_t     LCD_EN;
  static const uint8_t     LCD_D4;
  static const uint8_t     LCD_D5;
  static const uint8_t     LCD_D6;
  static const uint8_t     LCD_D7;
  static const uint8_t     custom_chars[8][8];
  static void              select_inversion(uint8_t const & number);
  static LiquidCrystal_I2C device;
public:
  enum chars {
    CHAR_REST, CHAR_REST_ACTIVE, CHAR_INVERSION, CHAR_REST_BARRIER,   
    CHAR_HIT,  CHAR_HIT_ACTIVE,  CHAR_PLAYSTATE, CHAR_HIT_BARRIER
    };
  static void put_inversion(
    uint8_t const & col,
    uint8_t const & line,
    uint8_t const & number
  );
  static void setup();
  static void put_playstate(uint8_t const & col, uint8_t const & line);
  static void select_playstate(bool const & paused);
  
  // New
  static void clear();
  static void set_cursor(uint8_t const & x, uint8_t const & y);
  static void write(uint8_t const & byte);

  static size_t print_with_nulls(const char * buffer, size_t size);
  
  template <typename T> static void print(T const & t) {
    if (! lamb::i2c_lock::claim()) return;
    
    device.print(t);

    lamb::i2c_lock::release();
  }
};

#endif
