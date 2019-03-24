#include "buttonpad_resistor_ladder.h"

const uint8_t  Buttonpad_ResistorLadder::BUTTONPAD_PIN   = A6;

const uint16_t Buttonpad_ResistorLadder::VALUES[]        = {  650, 540, 500, 450, 365, 300, 200, 75 };

Buttonpad_ResistorLadder::Buttonpad_ResistorLadder() : button(0) {}

Buttonpad_ResistorLadder::~Buttonpad_ResistorLadder() {}

void Buttonpad_ResistorLadder::impl_setup() {
  pinMode(BUTTONPAD_PIN, INPUT);
}

uint8_t Buttonpad_ResistorLadder::impl_buttonpad_button() const {
  return button;
}

bool Buttonpad_ResistorLadder::impl_read() {
  static uint16_t adc            = 1024;
  static bool     return_to_zero = false;
  uint8_t         pressed        = 0;
  uint16_t        previous_value = adc;

  analogRead(BUTTONPAD_PIN);
  
  adc                            += analogRead(BUTTONPAD_PIN);  
  adc >>= 1;

  uint16_t delta  = abs(previous_value - adc);
  
  if (delta > 2)
    return false;

  for (; (pressed <= 7) && (adc < VALUES[pressed]); pressed++);
      
  if ((pressed == button) || (return_to_zero && pressed != 0))
   return false;

  return_to_zero  = pressed != 0;
  button          = pressed;
    
  if (0 != button) {
    Serial.print(F("Press button "));
    Serial.print(button);
    Serial.print(F(" at "));
    Serial.print(adc);
    
    static uint16_t avg = 1024;
    avg *= 3;
    avg += adc;
    avg >>= 2;
    Serial.print(F(" previous = "));
    Serial.print(previous_value);
    Serial.print(F(" delta = "));
    Serial.print(delta);
    Serial.print(F(" average = "));
    Serial.print(avg);
    
    Serial.println();
    
    return true;
  }

  return false;
}

