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
  TCCR1B |= (1 << CS12) | (0 << CS11) | (1 << CS10); // Set CS12, CS11 and CS10 bits for 512 prescaler
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
    OCR1A = 16000000 / (256 * (bpm_ / 30.0 * 8)) - 1;
    // ^ do not un-float the '60.0'!

    if (TCNT1 > OCR1A)
      TCNT1 = OCR1A - 1;
  }
}

void Timer1_::increment_ticker() {
  Timer1_::_ticker++;
}

void Timer1_::isr() {
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
    Application::flag_main_screen(); // In ISR, not that ugly...

    if (! playback_state()) {
      PORTC &= ~0b1111; // PORTC = 0;

#ifdef LOG_TIMERS
      Serial.println(F("1:isr !"));
#endif

      return;
    }

    byte blast = 0xff;

//    Serial.print(F("Triggers: "));

    for (byte ix = 0; ix <= 2; ix++) {
      if (Application::tracks()[ix].trigger_state(ticker_ >> 1)) {
        blast &= ~_BV(ix);

//        Serial.print(ix);
//        Serial.print(" ");                
//        Serial.print(" = ");     
//        Application::print_bits(_BV(ix));
//        Serial.print(", ");
      }
    }

//    Serial.println();


#ifdef LOG_OUTPUT
    Serial.println();
    Serial.print(F("blast   "));
    Serial.print(ticker_);
    Serial.print(F(" = "));
    Application::print_bits(blast);
    Serial.println();
#endif
    
    Application::flag_output(blast);
  }
  else {
#ifdef LOG_OUTPUT
    Serial.println();
    Serial.println(F("unblast "));
#endif
    
    Application::flag_output(0xff);
  }

  increment_ticker();

  TIMSK1 = cTIMSK1;
  TIMSK2 = cTIMSK2;

#ifdef LOG_TIMERS
  Serial.println(F("1:isr -"));
#endif

  sei();
}

ISR(TIMER1_COMPA_vect) {
  Timer1_::instance().isr();
}
