#include "timers/timer1.h"
#include "application.h"

Timer1_::Timer1_() :
  _bpm(0),
  _playback_state(true),
  _ticker(0),
  _hz(0) {
};

Timer1_::~Timer1_() {}

Timer1_ * Timer1_::_instance = 0;

Timer1_ & Timer1_::instance() {
  return *_instance;
}

void Timer1_::setup() {
  _instance = this;
  DDRC   |= 0b00001111;
  PORTC  ^= 0b00001111;
  TCCR1A  = 0;
  TCCR1B  = 0;
  TCNT1   = 0; // initialize counter value to 0
  OCR1A   = 31249; // = 16000000 / (256 * 2) - 1 (must be <655) // set compare match register for 2 Hz increments
  TCCR1B |= (1 << WGM12); // TURN ON OUTPUT
  TCCR1B |= (1 << CS12) | (0 << CS11) | (0 << CS10); // Set CS12, CS11 and CS10 bits for 256 prescaler
  TIMSK1 |= (1 << OCIE1A);
  TCCR1A |= (1 << COM1A0);
  DDRB   |= _BV(1);
}

bool Timer1_::playback_state() const {
  return _playback_state;
}

void Timer1_::set_playback_state(bool playback_state_) {
  _playback_state = playback_state_;

  if (_playback_state) {
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
      TCCR1A |= (1 << COM1A0);
      TCNT1 = 0;
    }
  }
  else { // stop playback
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
      TCCR1A ^= (1 << COM1A0);
      PORTC &= ~0b1111; // PORTC = 0;
      PORTB ^= 0b10;
    }
  }
}

void Timer1_::set_bpm(uint8_t tmp_bpm) {
  Serial.print(F("Set BPM: "));
  Serial.println(tmp_bpm);

  Timer1_::_bpm          = tmp_bpm;
  Timer1_::_hz           = Timer1_::_bpm / 60.0;
  Timer1_::set_hz_by_bpm ( Timer1_::_bpm ); // This should probably be in the ISR...
}

uint8_t Timer1_::ticker() const {
  return _ticker;
}

uint8_t Timer1_::bpm() const {
  return _bpm;
}

double Timer1_::hz() const {
  return _hz;
}

void Timer1_::set_hz_by_bpm(uint8_t bpm_) {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    OCR1A = 16000000 / (256 * (bpm_ / 60.0 * 8)) - 1; //   // do not un-float the '60.0'!
    if (TCNT1 > OCR1A)
      TCNT1 = OCR1A - 1;
  }
}

void Timer1_::increment_ticker() {
  Timer1_::_ticker++;
}

ISR(TIMER1_COMPA_vect) {
  uint8_t ticker = Timer1_::instance().ticker();

  if (! (ticker & 0b1)) {
    Application::flag_main_screen(); // In ISR, not that ugly...

    if (! Timer1_::instance().playback_state()) {
      PORTC &= ~0b1111; // PORTC = 0;
      return;
    }

    byte blast = 0;

    for (byte ix = 0; ix <= 2; ix++)
      if (Application::tracks()[ix].trigger_state(ticker >> 1)) // In ISR, not that ugly...
        blast |= _BV(ix);

    PORTC = blast;
  }
  else
    PORTC &= ~0b1111;

  Timer1_::instance().increment_ticker();
}
