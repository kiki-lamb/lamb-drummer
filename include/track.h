#ifndef SHELF_CLOCK_TRACK_STATE_H
#define SHELF_CLOCK_TRACK_STATE_H

#include "Arduino.h"
#include "flag.h"

class Track {
public:
  Flag    modified;

  void    set_mod_maj  (uint8_t val);
  void    set_mod_min  (uint8_t val);
  void    set_phase_min(uint8_t val);
  void    set_phase_maj(uint8_t val);
  uint8_t mod_maj()   const;
  uint8_t mod_min()   const;
  uint8_t phase_min() const;
  uint8_t phase_maj() const;
  virtual Track & operator=(Track const & other);
  bool    trigger_state(uint8_t counter) const;
  Track(
    uint8_t mod_maj_ = 0,
    uint8_t mod_min_ = 1,
    uint8_t phase_min_ = 0,
    uint8_t phase_maj_ = 0
  );
  virtual ~Track();
private:
  uint8_t _mod_min;
  uint8_t _mod_maj;
  uint8_t _phase_min;
  uint8_t _phase_maj;
};

#endif
