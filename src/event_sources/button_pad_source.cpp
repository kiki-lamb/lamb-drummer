#include "event/event.h"
#include "event_sources/button_pad_source.h"
#include "button_pads/button_pad_mcp23017.h"
#include "button_pads/encoder_pad_mcp23017.h"

template <>
typename event::event_type_t
button_pad_source<button_pad_mcp23017<0x0, 8> >::button_pad_ordering[16] = {
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
  EVT_PAD_1,
  EVT_PAD_2,
  EVT_PAD_3,  
  EVT_PAD_4,

  EVT_PAD_5,
  EVT_PAD_6,
  EVT_PAD_7,
  EVT_PAD_8,

  EVT_PAD_9,
  EVT_PAD_10,
  EVT_PAD_11,
  EVT_PAD_12,

  EVT_PAD_13,
  EVT_PAD_14,
  EVT_PAD_15,
  EVT_PAD_16,
};

template <>
typename event::event_type_t
button_pad_source<encoder_pad_mcp23017<0x0, 4, 8> >::button_pad_ordering[16] = {
  EVT_PAD_1,
  EVT_PAD_2,
  EVT_PAD_3,  
  EVT_PAD_4,

  EVT_PAD_5,
  EVT_PAD_6,
  EVT_PAD_7,
  EVT_PAD_8,
};
