#ifndef SHELF_CLOCK_LCD_H
#define SHELF_CLOCK_LCD_H

#include <LiquidCrystal.h>

class Lcd {
private:
  Lcd();
  ~Lcd();
  static const uint8_t       LCD_COLS;
  static const uint8_t       LCD_LINES;
  static const uint8_t       LCD_RS;
  static const uint8_t       LCD_EN;
  static const uint8_t       LCD_D4;
  static const uint8_t       LCD_D5;
  static const uint8_t       LCD_D6;
  static const uint8_t       LCD_D7;
  static const unsigned char custom_chars[8][8];
  static void                select_inversion(uint8_t number);
public:
  static       LiquidCrystal lcd;  // RE-PRIVATE
  enum chars { CHAR_INVERSION, CHAR_PLAYSTATE, CHAR_HIT, CHAR_HIT_ACTIVE, CHAR_REST, CHAR_REST_ACTIVE, CHAR_HIT_BARRIER, CHAR_REST_BARRIER };
  static void put_inversion(
    uint8_t col,
    uint8_t line,
    uint8_t number
  );
  static void setup();
  static void put_playstate(uint8_t col, uint8_t line);
  static void select_playstate(bool paused);
};


#endif
