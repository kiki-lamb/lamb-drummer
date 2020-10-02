#include "i2c_lock.h"

volatile bool I2CLock::lock = false;

volatile bool I2CLock::claim() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if (! lock) { 
      Serial.println(F("+i2c"));
  
      return lock = true;
    }

    Serial.println(F("!i2c"));
  }

  return false;
}

volatile void I2CLock::release() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    Serial.println(F("-i2c"));

    lock = false;
  }
}
