#include "application.h"
#include <avr/power.h>

void setup() {
  clock_prescale_set(clock_div_1);
  
  Application::setup();
}

void loop() {
  Application::loop();
}
