#include <Arduino.h>
#include <avr/power.h>
#include "application/application.h"

void setup() {
  clock_prescale_set(clock_div_1);
  
  application::setup();
}

void loop() {
  application::loop();
}
