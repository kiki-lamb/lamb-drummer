#include "i2c_lock.h"

volatile char i2c_lock::cSREG = 0;

volatile bool i2c_lock::lock = false;

volatile bool i2c_lock::claim() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if (! lock) { 
#ifdef LOG_I2C_LOCK
      Serial.println(F("+i2c"));
#endif
//      cSREG = SREG;    

//      sei();
  
      return lock = true;
    }
#ifdef LOG_I2C_LOCK
    Serial.println(F("!i2c"));
#endif
  }

  return false;
}

volatile void i2c_lock::release() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
#ifdef LOG_I2C_LOCK
    Serial.println(F("-i2c"));
#endif

//    SREG = cSREG;
    
    lock = false;
  }
}
