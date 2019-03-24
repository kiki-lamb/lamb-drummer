#ifndef SHELF_CLOCK_APPLICATION_H
#define SHELF_CLOCK_APPLICATION_H

#include "Arduino.h"
#include "buttonpad_resistor_ladder.h"
#include "buttonpad_pcf8574.h"
#include "track_state_control_binding.h"
#include "track_state_collection.h"
#include "controls.h"
#include "eeprom.h"
#include "timer1.h"
#include "timer2.h"

class Application {
  private:
  Application();
  ~Application();

  public:
  static const    size_t                  NUM_TRACKS = 3;
  typedef TrackStateCollection<NUM_TRACKS, TrackState> collection_t;

  private:
  typedef         Buttonpad_PCF8754<0x3F> buttonpad_t;
  typedef         Controls<buttonpad_t>   controls_t;
  static          controls_t              controls;
  static          Eeprom                  eeprom;
  static          Timer1_                 timer1;
  static          Timer2_                 timer2;
  static          collection_t            _track_states;
  
  public:
  static          void                    setup();
  static          void                    loop();
  static          void                    process_controls();
  static          uint8_t                 page();  

  // fwds to timer1:
  static          double                  hz();
  static          uint8_t                 bpm();
  static          uint8_t                 ticker();
  static          bool                    playback_state();
  static          void                    set_bpm(uint8_t bpm);
  static          void                    set_playback_state(bool playback_state_);

  // fwd to Ui:
  static          void                    flag_main_screen();

  // fwd to _track_states:
  static          collection_t const &    track_states();
  
  // fwd to eeprom:
  static          void                    save_state();
};
#endif
