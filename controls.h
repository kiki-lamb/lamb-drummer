#ifndef SHELF_CLOCK_CONTROLS_H
#define SHELF_CLOCK_CONTROLS_H

#include "i_buttonpad.h"
#include "flag.h"
#include "encoder_button.h" 
#include "encoder.h" 
#include "buffer.h"

template <class i_buttonpad_t>
class Controls {
  public:
  
  enum ControlEventType { 
    EVT_MIN_UP,
    EVT_MIN_DN,
    EVT_MAJ_UP,
    EVT_MAJ_DN,
    EVT_PHASE_MIN_UP,
    EVT_PHASE_MIN_DN,
    EVT_PHASE_MAJ_UP,
    EVT_PHASE_MAJ_DN,
    EVT_SELECTED_TRACK_UP,
    EVT_SELECTED_TRACK_DN,
    EVT_BPM_SET,
    EVT_PLAYBACK_STATE_TOGGLE,
    EVT_NOT_AVAILABLE
  };

  struct ControlEvent {
    ControlEventType type;
    uint8_t parameter;
  };

  Buffer<ControlEvent, 8> event_buffer;
//  Flag buttonpad_button_pressed;
//  Flag encoder_button_pressed;
//  Flag bpm_changed;
  uint8_t(*bpm_f)();
  
  uint8_t bpm() const {
    return _bpm;
  }

  IButtonpad::Button buttonpad_button() const {
    return button_pad->buttonpad_button();
  }

  Controls(uint8_t(*bpm_f_)()) : 
    button_pad(new i_buttonpad_t()),  
    encoder_button(A7), 
    bpm_f(bpm_f_) {
  }

  void set_encoder(uint8_t val) {
    Encoder::set_value(val);
  }
  
  void setup() {  
    Encoder::setup();
    encoder_button.setup();
    button_pad->setup();
  }

  void poll() {
    uint8_t tmp_bpm = Encoder::value();
  
    if (tmp_bpm != (*bpm_f)()) {
      queue_event(EVT_BPM_SET, tmp_bpm);
      _bpm = tmp_bpm;
    }

    if ( encoder_button.read() )
      queue_event( EVT_PLAYBACK_STATE_TOGGLE);
    
    if ( button_pad->read() ) {
      static ControlEventType unscramble_buttons[] = {
        EVT_MAJ_UP,
        EVT_PHASE_MAJ_UP,
        EVT_MIN_UP,
        EVT_PHASE_MIN_UP,
        EVT_MAJ_DN,
        EVT_PHASE_MAJ_DN,
        EVT_MIN_DN,
        EVT_PHASE_MIN_DN
      };
      
      queue_event( unscramble_buttons[buttonpad_button()] );
    }
  }
  
  virtual ~Controls() {}

  ControlEvent dequeue_event() {
    if (! event_buffer.readable() ) {
      ControlEvent e = { EVT_NOT_AVAILABLE};
      return e;
    }

    return event_buffer.read();
  }

  private:   
  void queue_event(ControlEventType t, uint8_t param = 0) {
    if (! event_buffer.writeable()) {
      Serial.println(F("Can't queue."));
      return;
    }

    ControlEvent e = { t, param };

    Serial.print(F("Queue "));
    Serial.print(e.type);
    Serial.println();

    event_buffer.write(e);
  };
  
  uint8_t _bpm;
  IButtonpad * button_pad;
  EncoderButton encoder_button;
};

#endif
