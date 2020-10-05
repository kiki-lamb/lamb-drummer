#ifndef LAMB_DRUMMER_I2C_LOCK_H
#define LAMB_DRUMMER_I2C_LOCK_H

#include "Arduino.h"
#include <util/atomic.h>

class i2c_lock {
public:
  static volatile bool lock;
  static volatile bool claim();
  static volatile void release();
};

#endif
