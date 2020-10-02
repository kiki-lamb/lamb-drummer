#include "i2c_lock.h"

volatile bool I2CLock::lock = false;

volatile bool I2CLock::claim() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if (! lock) { 
      Serial.println("Claim I2C...");
  
      return lock = true;
    }

    Serial.println("Fail to claim I2C.");
  }

  return false;
}

volatile void I2CLock::release() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    Serial.println("Release I2C.");

    lock = false;
  }
}
