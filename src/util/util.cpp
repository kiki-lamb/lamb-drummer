#include "util/util.h"
#include <Arduino.h>

void util::print_bits_8(uint8_t const & t0) {
  {
    for(uint16_t mask = 0x80; mask; mask >>= 1) {
      if (mask & t0) {
        Serial.print('1'); Serial.flush();
      }
      else {
        Serial.print('0'); Serial.flush();
      }
    }
  }
}

void util::print_bits_16(uint16_t const & t0) {
  {
    for(uint16_t mask = 0x8000; mask; mask >>= 1) {
      if (mask & t0) {
        Serial.print('1'); Serial.flush();
      }
      else {
        Serial.print('0'); Serial.flush();
      }
    }
  }
}

uint16_t util::flip_bytes(uint16_t const & value) {
  uint8_t a = value >> 8;
  uint8_t b = value &  0xff;
  
  return (((uint16_t)b) << 8) | a; 
}
