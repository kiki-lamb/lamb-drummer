#ifndef LAMB_DRUMMER_ENCODER_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_ENCODER_PAD_PIN_MCP23017_H

#include <Arduino.h>
#include "encoder_pad.h"
#include <Wire.h>
#include "Adafruit_MCP23017.h"
#include "i2c_lock.h"

template <
  uint8_t i2c_addr_,
  uint8_t encoder_count = 16,
  uint8_t encoder_range_start = 0
  > class encoder_pad_mcp23017 : public encoder_pad<uint16_t> {
private:
  Adafruit_MCP23017 * device;
  uint16_t            encoders_;
  uint16_t            new_encoders;
  uint16_t            encoder_mask;
  uint8_t             encoder_shift;
  
public:
  encoder_pad_mcp23017() :
    device(0),
    encoders_(0),
    new_encoders(0),
    encoder_mask(0) {}

  virtual ~encoder_pad_mcp23017() {}

  virtual void setup() {
    encoder_pad<uint16_t>::setup();
  }
  
  virtual void setup(Adafruit_MCP23017 * _device) {
    device = _device;
    setup();
  }

  virtual void impl_setup() {
    Serial.print(F("Setup encoder_pad_MCP23017 @ 0x"));
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
    
    for (uint8_t ix = 0; ix < encoder_count; ix++, partial_mask >>= 1 ) {
      encoder_mask |= partial_mask;
    }

    encoder_mask >>= encoder_range_start;    
    encoder_shift = 16 - encoder_count - encoder_range_start;
    
    Serial.print("Encoder mask: ");
    print_bits_16(encoder_mask);
    Serial.println();
    Serial.print("Encoder shift: ");
    Serial.print(encoder_shift);
    Serial.println();
    Serial.println(F("Done setup encoder_pad_MCP23017.\n"));
    Serial.flush();    
  }
  
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
  
  virtual bool impl_read() {
#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif

    if (! i2c_lock::claim())
      return false;

    uint16_t tmpval = device->readGPIOAB();
    
    i2c_lock::release();

#ifdef LOG_ENCODERPAD_MCP_RAW_READING
    Serial.print(F("raw =>   ")); Serial.flush();
    print_bits_16(tmpval);
#endif
    
    tmpval = ~tmpval;  

#ifdef LOG_I2C_LOCK
    Serial.print(F("B:ir ")); Serial.flush();
#endif

    new_encoders = tmpval & ~encoders_; //  ^ tmpval;

    if (encoder_mask != 0xffff) {
      new_encoders &= encoder_mask;
    }

    if (encoder_shift != 0) {
      new_encoders >>= encoder_shift;
    }
    
#ifdef LOG_ENCODERPAD_MCP_RAW_READING
    Serial.print("MCP @ 0x");
    Serial.print(i2c_addr_, HEX);

    Serial.print(F(" old =>   ")); Serial.flush();
    print_bits_16(encoders_);

    Serial.print(F("read =>   ")); Serial.flush();
    print_bits_16(tmpval);    
#endif

    encoders_ = tmpval;

    if (0 != new_encoders) {
#ifdef LOG_ENCODERPAD_MCP_OUTPUT
      Serial.print("MCP @ 0x");
      Serial.print(i2c_addr_, HEX);

      Serial.print(" Give encoders: ");
      print_bits_16(new_encoders);
      Serial.println();
      Serial.flush();
#endif
      
      return true;
    }

    return false;
  }

  virtual uint16_t impl_encoders() const {
    return new_encoders;
  }
};

#endif
