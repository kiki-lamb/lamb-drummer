#ifndef SHELF_CLOCK_CONTROLS_H
#define SHELF_CLOCK_CONTROLS_H

#include "i_buttonpad.h"
#include "flag.h"
#include "encoder_button.h" 
#include "encoder.h" 
#include "timer1.h"
#include "application.h"

template <class i_buttonpad_t>
class Controls {
  public:

  Flag buttonpad_button_pressed;
  Flag encoder_button_pressed;
  Flag bpm_changed;
  uint8_t(*bpm_f)();
  
  uint8_t bpm() const {
    return _bpm;
  }

  IButtonpad::Button buttonpad_button() const {
    return button_pad->buttonpad_button();
  }

  Controls(uint8_t(*bpm_f_)()) : button_pad(new i_buttonpad_t()),  buttonpad_button_pressed("buttonpad_button_pressed"), encoder_button(A7), bpm_f(bpm_f_) {
  }

  void setup() {  
    Encoder::setup();
    encoder_button.setup();
    button_pad->setup();
  }
  
  void poll() {
    uint8_t tmp_bpm = Encoder::value();
  
    if (tmp_bpm != (*bpm_f)()) {
      bpm_changed.flag();
      _bpm = tmp_bpm;
    }

    if ( encoder_button.read() )
      encoder_button_pressed.flag();
    
    if ( button_pad->read() ) 
      buttonpad_button_pressed.flag();
  }
  
  virtual ~Controls() {}

  private:   
  uint8_t _bpm;
  IButtonpad * button_pad;
  EncoderButton encoder_button;
};

#endif
