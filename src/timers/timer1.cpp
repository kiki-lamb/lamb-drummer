#include "timers/timer1.h"
#include "application/application.h"

void timer1::set_ticker(uint8_t const & ticker_) { 
  _ticker = ticker_;
}

void timer1::adjust_ticker(int8_t const & ticker_addend_) { 
  _ticker += ticker_addend_;
}

timer1::timer1(uint8_t const & track_count_) :
  _track_count(track_count_),
  _bpm(0),
  _playback_state(true),
  _ticker(0),
  _millihz(0) {};

// timer1::~timer1() {}

timer1 * timer1::_instance = 0;

timer1 & timer1::instance() {
  return *_instance;
}

void timer1::setup() {
  _instance = this;
  TCCR1A    = 0;
  TCCR1B    = 0;
  TCNT1     = 0; // initialize counter value to 0
  OCR1A     = 31249; // = 16000000 / (256 * 2) - 1
  TCCR1B   |= (1 << WGM12); // TURN ON OUTPUT
  TCCR1B   |= (1 << CS12) | (0 << CS11) | (1 << CS10);
  // Set CS12, CS11 and CS10 bits for 512 prescaler
  TIMSK1   |= (1 << OCIE1A);
  TCCR1A   |= (1 << COM1A0);
  DDRB     |= _BV(1);
}

bool timer1::playback_state() const {
  return _playback_state;
}

void timer1::set_playback_state(bool const & playback_state_) {
  _playback_state = playback_state_;
}

void timer1::set_bpm(uint8_t const & tmp_bpm) {
  Serial.print(F("BPM = "));
  Serial.print(tmp_bpm);
  
  timer1::_bpm         = tmp_bpm;
  timer1::_millihz     = (((uint32_t)timer1::_bpm) * 1000) / 60;
  timer1::set_hz_by_bpm( timer1::_bpm ); 

  Serial.print(F(", "));
  Serial.print(timer1::_millihz);
  Serial.println();
}

uint8_t timer1::ticker() const {
  return _ticker;
}

uint8_t timer1::bpm() const {
  return _bpm;
}

uint16_t timer1::millihz() const {
  return _millihz;
}

void timer1::set_hz_by_bpm(uint8_t const & bpm_) {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    uint32_t tmp   = bpm_;
    tmp          <<= 23;
    tmp           /= 60;
    tmp          >>= 10;
    
    OCR1A = F_CPU / tmp - 1;

    if (TCNT1 > OCR1A)
      TCNT1 = OCR1A - 1;
  }
}

void timer1::increment_ticker() {
  timer1::_ticker++;
}

void timer1::draw_track_on_x0x_leds() {
  uint16_t write = 0;
  uint8_t  add   = application::bar() << 4;
  auto     track = application::tracks().current();
  
  for (uint8_t col = 0, total = add; col < 16; col++, total++) {
    if (track.trigger(total)) {
      write |= 1 << col;
    }
  }
  
  application::x0x_leds().write(lamb::flip_bytes(write));
}

void timer1::draw_chase_light_on_x0x_leds(uint8_t const & ticker_) {
  application::x0x_leds().xor_write(
    lamb::flip_bytes(1 << (((ticker_ >> 1) % 16)))
  );    
}
  
void timer1::isr() {
#ifdef LOG_TIMERS
  Serial.println(F("1:isr +"));
#endif
    
  char    cTIMSK1 = TIMSK1;
  TIMSK1          = 0;
  char    cTIMSK2 = TIMSK2;
  TIMSK2          = 0;
  uint8_t ticker_ = ticker();

  if (playback_state()) {
    if ((ticker_ & 0b1)) {
      application::triggers().write(0xff);
    }
    else {
      if ((ticker_ % 8) == 0) { // can probably happen less often?
        application::flag_main_screen(); // In ISR, not that ugly...
      }

      draw_track_on_x0x_leds();

      draw_chase_light_on_x0x_leds(ticker_);
            
      uint8_t out = 0xff;
      
      for (uint8_t ix = 0; ix < _track_count; ix++) {      
        if (application::tracks()[ix].trigger(ticker_ >> 1)) {
          out &= ~_BV(ix);
        }
      }
      
      Serial.print(F("out = "));
      lamb::print_bits_8(out);

      Serial.print(" ");
      Serial.print(ticker_ >> 1);
      Serial.println();
      
      application::triggers().write(out);
    }
    
    increment_ticker();
  }
  else {
    draw_track_on_x0x_leds(); // doesn't need to happen this often!
  }
  
  TIMSK1 = cTIMSK1;
  TIMSK2 = cTIMSK2;

#ifdef LOG_TIMERS
  Serial.println(F("1:isr -"));
#endif
}

ISR(TIMER1_COMPA_vect) {
  timer1::instance().isr();
}
