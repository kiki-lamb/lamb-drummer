#ifndef SHELF_CLOCK_TRACK_STATE_COLLECTION_H
#define SHELF_CLOCK_TRACK_STATE_COLLECTION_H

#include "Arduino.h"

template <size_t size, class track_state_t> 
class TrackStateCollection {
  private:
   track_state_t items[size];
   size_t _index;
   
  public:
  typedef track_state_t item_t;
  
  TrackStateCollection() : _index(2) {
    for (size_t ix = 0; ix < size; ix++)
      items[ix] = track_state_t();
  }
  
  virtual ~TrackStateCollection() {}

  size_t index() const {
    return _index;
  }
  
  track_state_t const & operator[](size_t index) const {
    return items[index];
  }
  
  track_state_t & operator[](size_t index) {
    return items[index];
  }

  uint8_t max_mod_maj() const {
    uint8_t max = 0;
  
    for (uint8_t ix = 0; ix < size; ix++)
      if (items[ix].mod_maj() > max)
        max = items[ix].mod_maj();
  
    return max;
  }
};

#endif
