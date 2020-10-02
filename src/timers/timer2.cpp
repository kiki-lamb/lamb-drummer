#include "Arduino.h"
#include "timers/timer2.h"
#include "application.h"

Timer2_::Timer2_() {};

Timer2_::~Timer2_() {};

Timer2_ * Timer2_::_instance = 0;

Timer2_ & Timer2_::instance() {
  return *_instance;
}

void Timer2_::setup() {
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

void Timer2_::isr() {
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
    Application::save_state(); // In ISR, not that ugly...
  }

  Application  ::process_control_events(); // In ISR, not that ugly...

  TIMSK1 = cTIMSK1;
  TIMSK2 = cTIMSK2;
  
#ifdef LOG_TIMERS
  Serial.println(F("2:isr -"));
#endif
}

ISR(TIMER2_COMPA_vect) {
  Timer2_::instance().isr();
}
