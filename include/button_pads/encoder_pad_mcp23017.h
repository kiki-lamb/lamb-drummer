#ifndef LAMB_DRUMMER_ENCODER_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_ENCODER_PAD_PIN_MCP23017_H

template <
  uint8_t i2c_addr_,
  uint8_t encoder_count = 8,
  uint8_t encoder_range_start = 0
  > class encoder_pad_mcp23017 :
  public button_pad_mcp23017<i2c_addr_, encoder_count * 2, encoder_range_start> {
};

#endif
