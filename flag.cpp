#include "flag.h"
#include "Arduino.h"

Flag::Flag(char * _name = 0, bool _value = false) : name(_name), value(_value) {};

void Flag::flag() { 
//  Serial.print(F("Flag "));
//  Serial.print(name);
//  Serial.println();
  value = true; 
}

bool Flag::consume() { 
  bool tmp = value;
  if (value) {
    value = false;
    return true;
  }
  
  return false;
}

void Flag::unflag() {
  value = false;
  
  Serial.flush();
  Serial.print(F("Explicitly unflag "));
  
  if (0 != name) {
    Serial.print(name);
    Serial.print(F(" "));
  }

  Serial.print(F("@ "));
  unsigned long tmp = this;
  tmp += 0x800000;
  Serial.print(tmp, HEX);

  Serial.println();  
  Serial.flush();
}

