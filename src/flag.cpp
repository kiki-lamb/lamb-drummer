#include "flag.h"
#include "Arduino.h"

Flag::Flag(
  char * _name,
  bool _value
) :
  name(_name),
  value(_value) {
};

void Flag::flag() {
  // Serial.flush();
  // Serial.print(F("Flag "));
  // if (0 != name) {
  //   Serial.print(name);
  //   Serial.print(F(" "));
  //   Serial.println();
  // }

  value = true;
}

bool Flag::consume() {
  // Serial.print(F("Consume "));
  // if (0 != name) {
  //   Serial.print(name);
  //   Serial.print(F(" "));
  //   Serial.println();
  // }

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
  unsigned long tmp = (unsigned long)this;
  tmp += 0x800000;
  Serial.print(tmp, HEX);

  Serial.println();
  Serial.flush();
}
