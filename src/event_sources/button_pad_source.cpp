#include "event/event.h"
#include "event_sources/button_pad_source.h"
#include "button_pads/button_pad_mcp23017.h"

template <>
typename event::event_type_t
button_pad_source<button_pad_mcp23017<0x0 /* , 8, 8 */> >::button_pad_ordering[16] = {
  EVT_MAJ_UP,
  EVT_PHASE_MAJ_UP,
  EVT_MIN_UP,
  EVT_SELECTED_TRACK_DN, // EVT_PHASE_MIN_UP,

  EVT_MAJ_DN,
  EVT_PHASE_MAJ_DN,
  EVT_MIN_DN,
  EVT_SELECTED_TRACK_UP, // EVT_PHASE_MIN_DN,
};

template <>
typename event::event_type_t
button_pad_source<button_pad_mcp23017<0x3> >::button_pad_ordering[16] = {
  EVT_PAD0_ON,
  EVT_PAD1_ON,
  EVT_PAD2_ON,
  EVT_PAD3_ON,
  
  EVT_PAD4_ON,
  EVT_PAD5_ON,
  EVT_PAD6_ON,
  EVT_PAD7_ON,

  EVT_PAD8_ON,
  EVT_PAD9_ON,
  EVT_PAD10_ON,
  EVT_PAD11_ON,

  EVT_PAD12_ON,
  EVT_PAD13_ON,
  EVT_PAD14_ON,
  EVT_PAD15_ON,
};
