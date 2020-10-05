#ifndef LAMB_DRUMMER_TRACK_STATE_COLLECTION_H
#define LAMB_DRUMMER_TRACK_STATE_COLLECTION_H

#include "Arduino.h"
#include <lamb.h>
#include "track/track.h"

template <size_t size_, class track_t = track>
class track_collection : public lamb::positional_fixed_array<size_, track_t> {
public:
  track_collection() {}

  virtual ~track_collection() {}

  uint8_t max_mod_maj() const {
    uint8_t max = 0;

    for (uint8_t ix = 0; ix < size_; ix++)
      if ((*this)[ix].mod_maj() > max)
        max = (*this)[ix].mod_maj();

    return max;
  }
};

#endif
