#include "Arduino.h"
#include "timers/timer2.h"
#include "application/application.h"

timer2::timer2() {};

// timer2::~timer2() {};

timer2 * timer2::_instance = 0;

timer2 & timer2::instance() {
  return *_instance;
}

void timer2::setup() {
  _instance = this;
  DDRB |= 0b00010000;

  TCCR2A  = 0; // set entire TCCR2A register to 0
  TCCR2B  = 0; // same for TCCR2B
  TCNT2   = 0; // initialize counter value to 0
  OCR2A   = 254;
  TCCR2B |= (1 << WGM21);
  TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20); // Prescale = 1024
  TIMSK2 |= (1 << OCIE2A); // enable timer compare interrupt
}

void timer2::isr() {
#ifdef LOG_TIMERS
  Serial.println(F("2:isr +"));
#endif

  char cTIMSK1 = TIMSK1;
  TIMSK1 = 0;
  
  char cTIMSK2 = TIMSK2;
  TIMSK2 = 0;

  static uint16_t ix = 0;
  
  if (! (ix++ & 0b11111111)) {
    PORTB ^= _BV(5);   // flip LED_BUILTIN
    application::save_state(); // In ISR, not that ugly...
  }

  application::flag_controls();

  TIMSK1 = cTIMSK1;
  TIMSK2 = cTIMSK2;
  
#ifdef LOG_TIMERS
  Serial.println(F("2:isr -"));
#endif
}

ISR(TIMER2_COMPA_vect) {
  timer2::instance().isr();
}
