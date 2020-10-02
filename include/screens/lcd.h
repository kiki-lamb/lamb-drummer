#ifndef LAMB_DRUMMER_LCD_H
#define LAMB_DRUMMER_LCD_H

#include "LiquidCrystal_I2C.h"
#include "i2c_lock.h"

class Lcd {
private:
  Lcd();
  ~Lcd();
  static const uint8_t     LCD_COLS;
  static const uint8_t     LCD_LINES;
  static const uint8_t     LCD_RS;
  static const uint8_t     LCD_EN;
  static const uint8_t     LCD_D4;
  static const uint8_t     LCD_D5;
  static const uint8_t     LCD_D6;
  static const uint8_t     LCD_D7;
  static const uint8_t     custom_chars[8][8];
  static void              select_inversion(uint8_t number);
  static LiquidCrystal_I2C lcd;
public:
  enum chars {
    CHAR_REST, CHAR_REST_ACTIVE, CHAR_INVERSION, CHAR_REST_BARRIER,   
    CHAR_HIT,  CHAR_HIT_ACTIVE,  CHAR_PLAYSTATE, CHAR_HIT_BARRIER
    };
  static void put_inversion(
    uint8_t col,
    uint8_t line,
    uint8_t number
  );
  static void setup();
  static void put_playstate(uint8_t col, uint8_t line);
  static void select_playstate(bool paused);
  
  // New
  static void clear();
  static void set_cursor(uint8_t x, uint8_t y);
  static void write(uint8_t byte);
  template <typename T> static void print(T t) {
    /* Serial.print("Lcd::print "); */ if (! I2CLock::claim()) return;
    
    lcd.print(t);

    /* Serial.print("Lcd::print "); */ I2CLock::release();
  }

};

#endif
