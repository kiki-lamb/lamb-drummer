#include "x0x_leds/x0x_leds.h"
#include "application.h"
#include "util/util.h"

x0x_leds::x0x_leds() : _device(NULL), _values(0) {}

x0x_leds::~x0x_leds() {}

bool x0x_leds::setup(Adafruit_MCP23017 * device_) {
  _device = device_;

  if (NULL == _device) return false;  

  for (size_t ix = 0; ix < 16; ix++) {
    _device->pinMode(ix, OUTPUT);
    _device->digitalWrite(ix, LOW);
  }
  
  return true;
}

void x0x_leds::flag() {
  _flag.set();
}

void x0x_leds::clear(bool const & immediate) {
  write(0, immediate);
  
}

void x0x_leds::xor_write(uint16_t const & values_, bool const & immediate) {
  Serial.print("xOR ");

  write(_values ^ values_, immediate);
}

void x0x_leds::or_write(uint16_t const & values_, bool const & immediate) {
  Serial.print("OR ");
      
  write(_values | values_, immediate);
}

void x0x_leds::write(uint16_t const & values_, bool const & immediate) {
  Serial.print("Assign ");
  util::print_bits_16(values_);
  Serial.println();
  
  _values = values_;

  if (immediate) {
    update(immediate);
  }
  else {
    flag();
  }
}

uint16_t x0x_leds::values() const {
  return _values;
}

bool x0x_leds::update(bool const & immediate) {
  if (! (_flag.consume() || immediate))
    return false;

  Serial.print("Write  ");
  util::print_bits_16(_values);
  Serial.println();
  
  _device->writeGPIOAB(_values);

  return true;
}
