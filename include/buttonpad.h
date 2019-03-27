#ifndef SHELF_CLOCK_I_BUTTONPAD_PIN_H
#define SHELF_CLOCK_I_BUTTONPAD_PIN_H

#include "Arduino.h"

class Buttonpad {
public:
  Buttonpad();
  virtual ~Buttonpad();
  bool    poll();
  uint8_t button() const;
  void    setup();
private:
  virtual bool    impl_poll() = 0;
  virtual uint8_t impl_button() const = 0;
  virtual void    impl_setup() = 0;
// protected:
//   enum Button {
//     BTN_MAJ_UP, // 9
//     BTN_INSTR_SELECT_UP, // 8
//     BTN_MIN_UP, // 7
//     BTN_PHASE_MIN_UP, // 6
//     BTN_MAJ_DOWN, // 2
//     BTN_INSTR_SELECT_DOWN, // 3
//     BTN_MIN_DOWN, // 4
//     BTN_PHASE_MIN_DOWN, // 5
//     BTN_NONE, // 1
// };
};

#endif
