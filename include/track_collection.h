#ifndef SHELF_CLOCK_TRACK_STATE_COLLECTION_H
#define SHELF_CLOCK_TRACK_STATE_COLLECTION_H

#include "Arduino.h"
#include "track.h"

template <size_t size_, class track_t = Track>
class TrackCollection {
private:
  track_t items[size_];
  size_t _index;

public:
  typedef track_t item_t;

  TrackCollection() : _index(2) {
    for (size_t ix = 0; ix < size_; ix++)
      items[ix] = track_t();

    __attribute((unused)) Track * tmp = &items[0]; // Make sure it's a Track.
  }

  virtual ~TrackCollection() {}

  size_t index() const {
    return _index;
  }

  size_t size() const {
    return size_;
  }

  track_t const & operator[](size_t index) const {
    return items[index];
  }

  track_t & operator[](size_t index) {
    return items[index];
  }

  track_t const & current() const {
    return items[index()];
  }

  track_t & current() {
    return items[index()];
  }

  uint8_t max_mod_maj() const {
    uint8_t max = 0;

    for (uint8_t ix = 0; ix < size_; ix++)
      if (items[ix].mod_maj() > max)
        max = items[ix].mod_maj();

    return max;
  }
};

#endif
