#include "trigger_outputs/trigger_outputs.h"
#include "application.h"
#include "util/util.h"

trigger_outputs::trigger_outputs() : _device(NULL), _values(0) {}

trigger_outputs::~trigger_outputs() {}

bool trigger_outputs::setup(jm_PCF8574 * device_) {
  _device = device_;

  if (NULL == _device) return false;  

  for (uint8_t ix = 0; ix < 8; ix++) {
    _device->pinMode(ix, OUTPUT);
  }

  _device->write(0xff);

  return true;
}

void trigger_outputs::flag() {
  _flag.set();
}

void trigger_outputs::clear() { // bool immediate) {
  write(0); // , immediate);
  
}

// void trigger_outputs::xor_write(uint16_t values_, bool immediate) {
//   Serial.print("xOR ");
// 
//   write(_values ^ values_, immediate);
// }

// void trigger_outputs::or_write(uint16_t values_, bool immediate) {
//   Serial.print("OR ");
//       
//   write(_values | values_, immediate);
// }

void trigger_outputs::write(uint16_t const & values_) { // , bool immediate) {
  _values = values_;

//   if (immediate) {
//     update(immediate);
//   }
//   else {
    flag();
//   }
}

uint16_t trigger_outputs::values() const {
  return _values;
}

bool trigger_outputs::update() { // bool immediate) {
  if (! (_flag.consume())) // || immediate))
    return false;
  
  _device->write(_values);

  return true;
}