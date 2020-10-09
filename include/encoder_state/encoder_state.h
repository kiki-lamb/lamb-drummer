#ifndef LAMB_DRUMMER_ENCODER_STATE
#define LAMB_DRUMMER_ENCODER_STATE

#include <inttypes.h>

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

      if (motion < -1) {
        this->flagged = true;
      }

      this->stage_ix = (stage_ix + 1U) & 0b11;
    }
    else if (stages[((uint8_t)(stage_ix - 1)) & 0b11] == bit_pair) {
      this->motion++;

      if (motion > 1) {
        this->flagged = true;
      }

      this->stage_ix = (this->stage_ix - 1) & 0b11;
    }
  }
};

#endif
