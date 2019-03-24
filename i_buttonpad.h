#ifndef SHELF_CLOCK_I_BUTTONPAD_PIN_H
#define SHELF_CLOCK_I_BUTTONPAD_PIN_H

#include "Arduino.h"
#include "flag.h"

class IButtonpad {
  public:
    IButtonpad();
    virtual ~IButtonpad();

    bool read();
    uint8_t buttonpad_button() const;
    void setup();

    enum Button {
      BTN_MAJ_UP, // 9
      BTN_INSTR_SELECT_UP, // 8
      BTN_MIN_UP, // 7
      BTN_PHASE_MIN_UP, // 6
      BTN_MAJ_DOWN, // 2
      BTN_INSTR_SELECT_DOWN, // 3
      BTN_MIN_DOWN, // 4
      BTN_PHASE_MIN_DOWN, // 5
      BTN_NONE, // 1
  };
    
  private:
      virtual bool impl_read() = 0;
      virtual uint8_t impl_buttonpad_button() const = 0;
      virtual void impl_setup() = 0;

};

#endif
