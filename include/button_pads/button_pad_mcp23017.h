#ifndef LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_BUTTON_PAD_PIN_MCP23017_H

#include <Arduino.h>
#include "button_pad.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "i2c_lock.h"

template <
  uint8_t i2c_addr_,
  uint8_t button_count = 16,
  uint8_t button_range_start = 0
  > class button_pad_mcp23017 : public button_pad<uint16_t> {

private:
  Adafruit_MCP23017 * device;
  uint16_t            buttons_;
  uint16_t            new_buttons;

  uint16_t            button_mask;
  uint8_t             button_shift;
  
public:
  button_pad_mcp23017() :
    device(0),
    buttons_(0),
    new_buttons(0),
    button_mask(0) {}

  virtual ~button_pad_mcp23017() {}

  virtual void setup() {
    button_pad<uint16_t>::setup();
  }
  
  virtual void setup(Adafruit_MCP23017 * _device) {
    device = _device;
    setup();
  }

protected:
  virtual void impl_setup() {
    Serial.print(F("Setup button_pad_MCP23017 @ 0x"));
    Serial.print(i2c_addr_, HEX);
    Serial.println(F("...")); Serial.flush();

    if (NULL == device) {
      device = new Adafruit_MCP23017();
      device->begin(i2c_addr_);
    }

    for (uint8_t ix = 0; ix < 16; ix++) {
      device->pinMode(ix, INPUT);
      device->pullUp(ix, HIGH);
    }

    uint16_t partial_mask = 0x8000;
    
    for (uint8_t ix = 0; ix < button_count; ix++, partial_mask >>= 1 ) {
      button_mask |= partial_mask;
    }

    button_mask >>= button_range_start;    
    // Serial.print("BC: ");
    // Serial.print(button_count);
    // Serial.print(" BRS: ");
    // Serial.print(button_range_start);

    button_shift = 16 - (button_count + button_range_start);
    
    Serial.print(" Button mask: ");
    print_bits_16(button_mask);
    Serial.println();
    Serial.print("Button shift: ");
    Serial.print(button_shift);
    Serial.println();
    Serial.println(F("Done setup button_pad_MCP23017.\n"));
    Serial.flush();    
  }

public:
  void print_bits_16(uint16_t tmpval) const {
    for(uint16_t mask = 32768; mask; mask >>= 1) {
      if(mask  & tmpval) {
        Serial.print('1'); Serial.flush();
      }
      else {
        Serial.print('.'); Serial.flush();
      }
    }
  }
  
protected:
virtual bool impl_read() {
#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif

    if (! i2c_lock::claim())
      return false;

    uint16_t tmpval = device->readGPIOAB();
    
    i2c_lock::release();

#ifdef LOG_BUTTONPAD_MCP_RAW_READING
    Serial.print(F("raw =>   ")); Serial.flush();
    print_bits_16(tmpval);
#endif
    
    tmpval = ~tmpval;  

#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif

    new_buttons = tmpval & ~buttons_; //  ^ tmpval;

    if (button_mask != 0xffff) {
      new_buttons &= button_mask;
    }

    if (button_shift != 0) {
      new_buttons >>= button_shift;
    }
    
#ifdef LOG_BUTTONPAD_MCP_RAW_READING
    Serial.print("MCP @ 0x");
    Serial.print(i2c_addr_, HEX);

    Serial.print(F(" old =>   ")); Serial.flush();
    print_bits_16(buttons_);

    Serial.print(F("read =>   ")); Serial.flush();
    print_bits_16(tmpval);    
#endif

    buttons_ = tmpval;

    if (0 != new_buttons) {
#ifdef LOG_BUTTONPAD_MCP_OUTPUT
      Serial.print("MCP @ 0x");
      Serial.print(i2c_addr_, HEX);

      Serial.print(" Give buttons: ");
      print_bits_16(new_buttons);
      Serial.println();
      Serial.flush();
#endif
      
      return true;
    }

    return false;
  }

  virtual uint16_t impl_buttons() const {
    return new_buttons;
  }
};

#endif
