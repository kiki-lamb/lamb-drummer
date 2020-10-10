#ifndef LAMB_DRUMMER_XOX_TRACK_STATE_H
#define LAMB_DRUMMER_XOX_TRACK_STATE_H

#include "Arduino.h"
#include <lamb.h>

namespace tracks {
  class x0x {
  public:
    lamb::flag modified;
    void       set_mod_maj  (uint8_t const & val);
    void       set_mod_min  (uint8_t const & val);
    void       set_phase_min(uint8_t const & val);
    void       set_phase_maj(uint8_t const & val);
    uint8_t    mod_maj()   const;
    uint8_t    mod_min()   const;
    uint8_t    phase_min() const;
    uint8_t    phase_maj() const;
    x0x &    operator=(x0x const & other);
    bool       trigger_state(uint8_t const & counter) const;
    x0x(
      uint8_t const & mod_maj_ = 0,
      uint8_t const & mod_min_ = 1,
      uint8_t const & phase_min_ = 0,
      uint8_t const & phase_maj_ = 0
    );

  private:
    uint8_t _mod_maj;
    uint8_t _mod_min;
    uint8_t _phase_min;
    uint8_t _phase_maj;
  };
}

#endif