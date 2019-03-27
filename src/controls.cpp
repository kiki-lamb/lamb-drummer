#include "controls.h"
#include "buttonpad_pcf8574.h"

//template <class buttonpad_t> typename ControlEventSource<buttonpad_t>::ControlEventType ControlEventSource<buttonpad_t>::buttonpad_ordering[8] = {
//  EVT_MAJ_UP,
//  EVT_PHASE_MAJ_UP,
//  EVT_MIN_UP,
//  EVT_PHASE_MIN_UP,
//  EVT_MAJ_DN,
//  EVT_PHASE_MAJ_DN,
//  EVT_MIN_DN,
//  EVT_PHASE_MIN_DN
//};

template <> ControlEventType ControlEventSource<Buttonpad_PCF8754<0x3F> >::buttonpad_ordering[8] = {
  EVT_MAJ_UP,
  EVT_PHASE_MAJ_UP,
  EVT_MIN_UP,
  EVT_PHASE_MIN_UP,
  EVT_MAJ_DN,
  EVT_PHASE_MAJ_DN,
  EVT_MIN_DN,
  EVT_PHASE_MIN_DN
};
