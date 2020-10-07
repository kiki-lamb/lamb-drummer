#ifndef LAMB_DRUMMER_ENCODER_PAD_MCP23017_H
#define LAMB_DRUMMER_ENCODER_PAD_MCP23017_H

#include <Adafruit_MCP23017.h>
#include <inttypes.h>

#include "lamb.h"

template <uint8_t encoder_count>
class encoder_pad_mcp23017 {
private:
  class encoder_state {
  public:
    int8_t  motion;
    uint8_t stage_ix;
    bool    flagged;
    
    encoder_state() : motion(0), stage_ix(0), flagged(false) {}
    inline ~encoder_state() {}
    
    inline void update(char bit_pair) {
      static const unsigned char stages[] = { 0b00, 0b01, 0b11, 0b10 };
      
      if (stages[((uint8_t)(stage_ix + 1U)) & 0b11] == bit_pair) {
        this->motion--;
        this->flagged = true;
        this->stage_ix = (stage_gix + 1U) & 0b11;
      }
      else if (stages[((uint8_t)(stage_ix - 1)) & 0b11] == bit_pair) {
        this->motion++;
        this->flagged = true;
        this->stage_ix = (this->stage_ix - 1) & 0b11;
      }
    }
  };
  
private:
  uint8_t             i2c_addr;
  uint8_t             encoder_range_start;
  Adafruit_MCP23017 * device;
  lamb::array_list<encoder_state, lamb::delete_traits::owner>
                      encoder_states;
  uint16_t            encoder_mask;
  uint8_t             encoder_shift;
  
public:
  struct motion_event {
    uint8_t encoder_number;
    int8_t motion;
  };

  lamb::ring_buffer<motion_event, encoder_count> motion_events;

public:
  encoder_pad_mcp23017(
    uint8_t i2c_addr_, 
    uint8_t encoder_range_start_ = 0
  ) : 
    i2c_addr(i2c_addr), 
    encoder_range_start(encoder_range_start_),
    device(0),
    encoders_states(encoder_count_),
    encoder_mask(0),
    encoder_shift(0) {}
  
  virtual ~encoder_pad_mcp23017() {}

  virtual void setup() {
    Serial.print(F("Setup encoder_pad_MCP23017 @ 0x"));
    Serial.print(i2c_addr, HEX);
    Serial.println(F("...")); Serial.flush();
    
    if (NULL == device) {
      device = new Adafruit_MCP23017();
      device->begin(i2c_addr);
    }
    
    for (uint8_t ix = 0; ix < 16; ix++) {
      device->pinMode(ix, INPUT);
      device->pullUp(ix, HIGH);
    }
    
    uint16_t partial_mask = 0x8000;
    
    for (uint8_t ix = 0; ix < (encoder_count << 1); ix++, partial_mask >>= 1 ) {
      encoder_mask |= partial_mask;
    }
    
    encoder_mask >>= encoder_range_start;    
    
    encoder_shift = 16 - ((encoder_count << 1) + encoder_range_start);  
  }
  
  virtual void setup(Adafruit_MCP23017 * _device) {
    device = _device;
    setup();
  }
  
  virtual bool read() {
#ifdef LOG_I2C_LOCK
    Serial.print(F("E:ir ")); Serial.flush();
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

    if (tmpval == encoders_)
      return false;

#ifdef LOG_I2C_LOCK
    Serial.print(F("E:ir ")); Serial.flush();
#endif

    encoders_ = tmpval;

    uint16_t partial_mask = 0b11;
    partial_mask <<= (encoder_count-1) << 1;

    for (uint8_t ix = 0; ix < encoder_count; ix++, partial_mask >>= 2) {
      uint16_t cut = partial_mask & encoders_;
      uint8_t shifted = cut >> (((encoder_count-1) << 1) - (ix << 1));

      encoder_states[ix].update(shifted);

      if (encoder_states[ix].flagged && motion_events.writable()) {
        motion_events.enqueue(motion_event { ix, encoder_states[ix].motion });
        encoder_states[ix].motion = 0;
        encoder_states[ix].flagged = false;
      }
    }
    
    return motion_events.readable();
  }
};

#endif
 
