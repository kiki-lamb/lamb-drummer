#include "event_sources/control_source.h"
#include "buttonpads/buttonpad_pcf8574.h"

template <> ControlType ControlSource<Buttonpad_PCF8754<0x3F> >::buttonpad_ordering[8] = {
  EVT_MAJ_UP,
  EVT_PHASE_MAJ_UP,
  EVT_MIN_UP,
  EVT_PHASE_MIN_UP,
  EVT_MAJ_DN,
  EVT_PHASE_MAJ_DN,
  EVT_MIN_DN,
  EVT_PHASE_MIN_DN
};
