#include "timers/timer1.h"
#include "application.h"

timer1_::timer1_() :
  _bpm(0),
  _playback_state(true),
  _ticker(0),
  _hz(0) {
};

timer1_::~timer1_() {}

timer1_ * timer1_::_instance = 0;

timer1_ & timer1_::instance() {
  return *_instance;
}

void timer1_::setup() {
  _instance = this;
  // DDRC   |= 0b00001111;
  // PORTC  ^= 0b00001111;
  TCCR1A  = 0;
  TCCR1B  = 0;
  TCNT1   = 0; // initialize counter value to 0
  OCR1A   = 31249; // = 16000000 / (256 * 2) - 1 (must be <655) // set compare match register for 2 Hz increments
  TCCR1B |= (1 << WGM12); // TURN ON OUTPUT
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10); // Set CS12, CS11 and CS10 bits for 512 prescaler
  TIMSK1 |= (1 << OCIE1A);
  TCCR1A |= (1 << COM1A0);
  DDRB   |= _BV(1);
}

bool timer1_::playback_state() const {
  return _playback_state;
}

void timer1_::set_playback_state(bool const & playback_state_) {
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
      application::trigger_outputs().write(~0b1111);
      PORTB ^= 0b10;
    }
  }
}

void timer1_::set_bpm(uint8_t const & tmp_bpm) {
  Serial.print("BPM = ");
  Serial.println(tmp_bpm);
  
  timer1_::_bpm          = tmp_bpm;
  timer1_::_hz           = timer1_::_bpm / 60.0;
  timer1_::set_hz_by_bpm ( timer1_::_bpm ); // This should probably be in the ISR...
}

uint8_t timer1_::ticker() const {
  return _ticker;
}

uint8_t timer1_::bpm() const {
  return _bpm;
}

double timer1_::hz() const {
  return _hz;
}

void timer1_::set_hz_by_bpm(uint8_t const & bpm_) {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    OCR1A = 16000000 / (256 * (bpm_ / 30.0 * 8)) - 1;
    // ^ do not un-float the '60.0'!

    if (TCNT1 > OCR1A)
      TCNT1 = OCR1A - 1;
  }
}

void timer1_::increment_ticker() {
  timer1_::_ticker++;
}

void timer1_::isr() {
  cli();
  
#ifdef LOG_TIMERS
  Serial.println(F("1:isr +"));
#endif
    
  char cTIMSK1 = TIMSK1;
  TIMSK1 = 0;
  
  char cTIMSK2 = TIMSK2;
  TIMSK2 = 0;

  uint8_t ticker_ = ticker();

  if (! (ticker_ & 0b1)) {
    application::flag_main_screen(); // In ISR, not that ugly...

    if (! playback_state()) {
      application::trigger_outputs().write(~0b1111);

#ifdef LOG_TIMERS
      Serial.println(F("1:isr !"));
#endif

      return;
    }

    byte blast = 0xff;

    for (byte ix = 0; ix <= 2; ix++) {
      if (application::tracks()[ix].trigger_state(ticker_ >> 1)) {
        blast &= ~_BV(ix);
      }
    }

#ifdef LOG_OUTPUT
    Serial.println();
    Serial.print(F("blast   "));
    Serial.print(ticker_);
    Serial.print(F(" = "));
    application::print_bits(blast);
    Serial.println();
#endif
    
    application::trigger_outputs().write(blast);
  }
  else {
#ifdef LOG_OUTPUT
    Serial.println();
    Serial.println(F("unblast "));
#endif
    
    application::trigger_outputs().write(0xff);
  }

  increment_ticker();

  TIMSK1 = cTIMSK1;
  TIMSK2 = cTIMSK2;

#ifdef LOG_TIMERS
  Serial.println(F("1:isr -"));
#endif
}

ISR(TIMER1_COMPA_vect) {
  timer1_::instance().isr();
}
