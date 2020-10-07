#ifndef LAMB_DRUMMER_UTIL_H
#define LAMB_DRUMMER_UTIL_H

#include <inttypes.h>

class util {
public:
  static  uint16_t flip_bytes(uint16_t const & value);
  static  void     print_bits_8(uint8_t const & t0);
  static  void     print_bits_16(uint16_t const & t0);
};

#endif
