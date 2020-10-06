#ifndef LAMB_DRUMMER_ENCODER_PAD_PIN_MCP23017_H
#define LAMB_DRUMMER_ENCODER_PAD_PIN_MCP23017_H

template <
  uint8_t i2c_addr_,
  uint8_t encoder_count = 8,
  uint8_t encoder_range_start = 0
  > class encoder_pad_mcp23017 : public button_pad_mcp23017<i2c_addr_, encoder_count * 2, encoder_range_start> {
private:
  typedef button_pad_mcp23017<i2c_addr_, encoder_count * 2, encoder_range_start> base_type;

  lamb::encoders::states::directional states[encoder_count];

public:
  encoder_pad_mcp23017() {}

  ~encoder_pad_mcp23017() {}

  virtual bool impl_read() {
    bool tmp =  base_type::impl_read();

    uint16_t buttons = base_type::buttons();
    
    if (! tmp)
      return tmp;

    uint16_t partial_mask = 0xc000;
    partial_mask >>= encoder_range_start;
    
    for (uint8_t ix = 0; ix < (encoder_count * 2); ix += 2, partial_mask >>= 2) {
      Serial.print("PM: ");
      base_type::print_bits_16(partial_mask);
      Serial.print(" vs ");
      base_type::print_bits_16(buttons);

      uint16_t cut = partial_mask & buttons;

      Serial.print(" cuts to ");
      base_type::print_bits_16(cut);

      uint16_t shifted = cut >> (((encoder_count-1) * 2) - ix);
            
      Serial.print(" giving ");
      base_type::print_bits_16(shifted);

      Serial.println();
      Serial.flush();
      
      states[ix].update(shifted);
    }

    for (uint8_t ix = 0; ix < encoder_count; ix++) {
      Serial.print("enc ");
      Serial.print(ix);
      Serial.print(" =  ");
      Serial.print(states[ix].direction());
      Serial.println();
      Serial.flush();
    }
    
    return tmp;
  }
};

#endif
