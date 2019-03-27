#ifndef SHELF_CLOCK_BUTTONPAD_PIN_H
#define SHELF_CLOCK_BUTTONPAD_PIN_H

#include "Arduino.h"
#include "i_buttonpad.h"

class Buttonpad_ResistorLadder : public IButtonpad {
  private:
    static const uint8_t  BUTTONPAD_PIN;
    static const uint16_t VALUES[8];
    uint8_t               button;
  public:
    Buttonpad_ResistorLadder();
    virtual ~Buttonpad_ResistorLadder();
    virtual bool impl_read();
    virtual uint8_t impl_buttonpad_button() const;
    virtual void impl_setup();
};

#endif
