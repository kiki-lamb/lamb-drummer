#include "i2c_lock.h"

volatile bool I2CLock::lock = false;

volatile bool I2CLock::claim() {
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    if (! lock) {
      lock = true;
      return true;
    }
  }      
  return false;
}

volatile void I2CLock::release() {
  lock = false;
}
