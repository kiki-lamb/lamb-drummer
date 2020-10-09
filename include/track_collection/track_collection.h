#ifndef LAMB_DRUMMER_TRACK_STATE_COLLECTION_H
#define LAMB_DRUMMER_TRACK_STATE_COLLECTION_H

#include "Arduino.h"
#include <lamb.h>

template <size_t size_, class track_t>
class track_collection : public lamb::positional_fixed_array<size_, track_t> {
public:
  track_collection() {}
};

#endif
