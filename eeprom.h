#ifndef SHELF_CLOCK_EEPROM_H
#define SHELF_CLOCK_EEPROM_H

#include <EEPROM.h>
#include "flag.h"
#include "track_state.h"

class Eeprom {
  private:
    void save_playback_state() const;
    void save_bpm() const;
    bool playback_state() const;
    uint8_t bpm() const;
    void save_track_state(size_t eeprom_location, TrackState const & track_state) const;
    void restore_track_state(size_t eeprom_location, TrackState & track_state) const;
    Flag save_requested;
    unsigned long last_edit;

  public:
    void flag_save_requested();
    void save_all() const;
    void restore_all() const;
    Eeprom();
    virtual ~Eeprom();    
};

#endif
