#include "event/event.h"
#include "event_sources/buttonpad_source.h"
#include "buttonpads/buttonpad_mcp23017.h"

template <>
typename Event::event_type_t
ButtonpadSource<Buttonpad_MCP23017<0x0> >::buttonpad_ordering[8] = {
  EVT_MAJ_UP,
  EVT_PHASE_MAJ_UP,
  EVT_MIN_UP,
  EVT_PHASE_MIN_UP,
  EVT_MAJ_DN,
  EVT_PHASE_MAJ_DN,
  EVT_MIN_DN,
  EVT_PHASE_MIN_DN
};
