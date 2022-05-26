#ifndef LAMB_DRUMMER_SCREEN_STATES_H
#define LAMB_DRUMMER_SCREEN_STATES_H

#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "tracks/euclidean.h"
#include "track_collection/track_collection.h"

template <typename data_t>
class screen_intro :
  public screen<data_t> {

public:
  explicit screen_intro(data_t * data)
    : screen<data_t>(data) {}
  
private:
  virtual void impl_enter() override {
    lcd::set_cursor(0, 0);
    lcd::print(F("    Lamb Drummer    "));
    
    static const int MS = 1;
    
    for (uint8_t iix = 0; iix < 3; iix++) {
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
  
  virtual bool impl_update() override { return true; }
};

template <typename data_t>
class screen_none :
  public screen<data_t> {
public:
  explicit screen_none(data_t * data) : screen<data_t>(data) {}
  
private:
  virtual void impl_enter() override {}
  virtual bool impl_update() override { return true; }
};
 
#endif
