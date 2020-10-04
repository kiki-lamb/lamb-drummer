#include "event/event.h"
#include "event_sources/buttonpad_source.h"
#include "buttonpads/buttonpad_mcp23017.h"

template <>
typename Event::event_type_t
ButtonpadSource<Buttonpad_MCP23017<0x0, 8, 8> >::buttonpad_ordering[16] = {
  EVT_MAJ_UP,
  EVT_PHASE_MAJ_UP,
  EVT_MIN_UP,
  EVT_SELECTED_TRACK_UP, // EVT_PHASE_MIN_UP,

  EVT_MAJ_DN,
  EVT_PHASE_MAJ_DN,
  EVT_MIN_DN,
  EVT_SELECTED_TRACK_DN, // EVT_PHASE_MIN_DN,
};

template <>
typename Event::event_type_t
ButtonpadSource<Buttonpad_MCP23017<0x5> >::buttonpad_ordering[16] = {
  EVG_PAD0_ON,
  EVG_PAD1_ON,
  EVG_PAD2_ON,
  EVG_PAD3_ON,
  
  EVG_PAD4_ON,
  EVG_PAD5_ON,
  EVG_PAD6_ON,
  EVG_PAD7_ON,

  EVG_PAD8_ON,
  EVG_PAD9_ON,
  EVG_PAD10_ON,
  EVG_PAD11_ON,

  EVG_PAD12_ON,
  EVG_PAD13_ON,
  EVG_PAD14_ON,
  EVG_PAD15_ON,
};
