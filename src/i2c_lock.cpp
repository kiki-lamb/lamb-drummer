#include "i2c_lock.h"

volatile bool I2CLock::lock = false;

volatile bool I2CLock::claim() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if (! lock) { 
#ifdef LOG_I2C_LOCK
      Serial.println(F("+i2c"));
#endif
  
      return lock = true;
    }
#ifdef LOG_I2C_LOCK
    Serial.println(F("!i2c"));
#endif
  }

  return false;
}

volatile void I2CLock::release() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
#ifdef LOG_I2C_LOCK
    Serial.println(F("-i2c"));
#endif

    lock = false;
  }
}
