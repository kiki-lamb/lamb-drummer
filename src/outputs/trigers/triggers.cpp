#include "outputs/triggers/triggers.h"
#include "application/application.h"

outputs::triggers::triggers() : _device(NULL), _values(0) {}

// outputs::triggers::~triggers() {}

bool outputs::triggers::setup(jm_PCF8574 * device_) {
  _device = device_;

  if (NULL == _device) return false;  

  for (uint8_t ix = 0; ix < 8; ix++) {
    _device->pinMode(ix, OUTPUT);
  }

  _device->write(0xff);

  return true;
}

void outputs::triggers::flag() {
  _flag.set();
}

void outputs::triggers::clear() {
  write(0);
}

void outputs::triggers::write(uint16_t const & values_) {
  _values = values_;

  flag();
}

uint16_t outputs::triggers::values() const {
  return _values;
}

bool outputs::triggers::update() {
  if (! (_flag.consume()))
    return false;
  
  _device->write(values());

  return true;
}
