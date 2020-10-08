#ifndef LAMB_DRUMMER_ENCODER_PAD_MCP23017_H
#define LAMB_DRUMMER_ENCODER_PAD_MCP23017_H

#include <inttypes.h>
#include "lamb.h"
#include "button_pads/pad_mcp23017.h"

template <uint8_t encoder_count>
class encoder_pad_mcp23017 : public pad_mcp23017 {
private:
  class encoder_state {
  public:
    int8_t  motion;
    uint8_t stage_ix;
    bool    flagged;
     
    encoder_state() : motion(0), stage_ix(0), flagged(false) {}
    
    ~encoder_state() {}
     
    void update(char bit_pair) {
      static const unsigned char stages[] = { 0b00, 0b01, 0b11, 0b10 };
       
      if (stages[((uint8_t)(stage_ix + 1U)) & 0b11] == bit_pair) {
        this->motion--;

        if (motion < -2) {
          this->flagged = true;
        }

        this->stage_ix = (stage_ix + 1U) & 0b11;
      }
      else if (stages[((uint8_t)(stage_ix - 1)) & 0b11] == bit_pair) {
        this->motion++;

        if (motion > 2) {
          this->flagged = true;
        }

        this->stage_ix = (this->stage_ix - 1) & 0b11;
      }
    }
  };
  
private:
  encoder_state encoder_states[encoder_count];
  
public:
  struct motion_event {
    uint8_t encoder_number;
    int8_t motion;
  };

  lamb::ring_buffer<motion_event, encoder_count> motion_events;

public:
  explicit encoder_pad_mcp23017(
    uint8_t i2c_addr_, 
    uint8_t button_range_start_ = 0
  ) :
    pad_mcp23017(i2c_addr_, (encoder_count << 1), button_range_start_),
    encoder_states() {}
  
  virtual ~encoder_pad_mcp23017() {}
  
  virtual bool read() {
    bool read = false;
    uint16_t tmpval = begin_read(read);

    if (! read) return false;
    
    buttons_ = tmpval;

    uint16_t partial_mask = 0b11;
    partial_mask <<= (encoder_count-1) << 1;

    for (uint8_t ix = 0; ix < encoder_count; ix++, partial_mask >>= 2) {
      uint16_t cut = partial_mask & buttons_;
      uint8_t shifted = cut >> (((encoder_count-1) << 1) - (ix << 1));

      encoder_states[ix].update(shifted);

      if (encoder_states[ix].flagged && motion_events.writable()) {
        motion_events.enqueue(
          motion_event { ix, encoder_states[ix].motion ^ 1 }
        );
        encoder_states[ix].motion = 0;
        encoder_states[ix].flagged = false;
      }
    }
    
    return motion_events.readable();
  }
};

#endif












