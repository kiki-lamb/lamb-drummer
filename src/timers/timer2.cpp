#include "Arduino.h"
#include "timers/timer2.h"
#include "application.h"

Timer2_::Timer2_() {};

Timer2_::~Timer2_() {};

void Timer2_::setup() {
  DDRB |= 0b00010000;

  TCCR2A  = 0; // set entire TCCR2A register to 0
  TCCR2B  = 0; // same for TCCR2B
  TCNT2   = 0; // initialize counter value to 0
  OCR2A   = 255;//99; // 255; // = 16000000 / (64 * 1000) - 1 (must be <256) // set compare match register for 977 Hz increments
  TCCR2B |= (1 << WGM21); // turn on CTC mode
  TCCR2B |= (1 << CS22) | (0 << CS21) | (0 << CS20); // Set CS22, CS21 and CS20 bits for 64 prescaler
  TIMSK2 |= (1 << OCIE2A); // enable timer compare interrupt
}

ISR(TIMER2_COMPA_vect) {
  static uint16_t ix = 0;

  if (! (ix++ & 0b11111111)) {
    PORTB ^= _BV(5);   // flip LED_BUILTIN
    Application::save_state(); // In ISR, not that ugly...
  }

  Application  ::process_control_events(); // In ISR, not that ugly...
}
