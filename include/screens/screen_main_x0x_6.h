#ifndef LAMB_DRUMMER_SCREEN_STATE_MAIN_XOX_6_H
#define LAMB_DRUMMER_SCREEN_STATE_MAIN_XOX_6_H

////////////////////////////////////////////////////////////////////////////////
// screen_main<ui_data<track_collection<6, tracks::x0x > > >
////////////////////////////////////////////////////////////////////////////////

template <>
class screen_main<ui_data<track_collection<6, tracks::x0x > > > :
  public screen<ui_data<track_collection<6, tracks::x0x > > > {

  typedef ui_data<track_collection<6, tracks::x0x > > data_t;
  typedef screen<data_t> base_t;

  static const uint8_t track_count = 6;
public:

////////////////////////////////////////////////////////////////////////////////

  screen_main(data_t * data) :
    base_t(data),
    popup_bpm_time(0),
    popup_bpm_state(false) {}
  
private:
  unsigned long popup_bpm_time;
  bool          popup_bpm_state;
  static const unsigned long popup_bpm_duration = 600;

////////////////////////////////////////////////////////////////////////////////

  void draw_bar_number() {
    lcd::set_cursor(18,0);
    lcd::print(data->bar+1);
  }

////////////////////////////////////////////////////////////////////////////////

  virtual void impl_enter() override {
    data->popup_bpm_requested.set();
    
    draw_line_0();
    
    lcd::put_playstate(19,0); // Ugly...
    
    draw_channel_numbers();
    
    draw_bar_number();
  }
  
////////////////////////////////////////////////////////////////////////////////
  
  void draw_channel_numbers() {
    static uint8_t last_selected = 0xff;

    uint8_t selected = (*data->tracks).index() + 1;
    
    if (selected != last_selected) {
      Serial.print("SELECT ");
      Serial.println(selected);
      
      for (uint8_t line = 1; line <= 3; line++) {
        if (line + (3 * data->page) == selected) {
          Serial.print(F("Line "));
          Serial.print(line);
          Serial.print(F(" = selected "));
          Serial.print(line + (3 * data->page));
          Serial.println();
          
          continue;
        }
        
        lcd::set_cursor(0, line);

        Serial.print(F("Put number "));
        Serial.print(line + (3 * data->page));
        Serial.print(F(" on line "));
        Serial.print(line);
        Serial.println();          

        lcd::print(line + 3 * data->page);
      }
      
      lcd::put_inversion(
        0,
        selected - (3 * data->page),
        selected
      );
      
      Serial.print(F("Put inversion of "));
      Serial.print(selected);
      Serial.print(F(" on line "));
      Serial.print(selected - (3 * data->page));
      Serial.println();          

      last_selected = selected;
    }
  }

////////////////////////////////////////////////////////////////////////////////

  virtual bool impl_update() override {
    auto           tracks       = *data->tracks;
    static uint8_t last_page    = 0xff;
    static uint8_t last_bar     = 255;
    static uint8_t track_ix     = 0;
    static uint8_t block_ix     = 0;
    static bool    mid_draw     = false;
    bool           redraw_bpm   = false;
    uint8_t        bar          = data->bar;
    uint8_t        current_page = data->page;
    bool           new_page     = current_page != last_page;

    if (new_page) {
      Serial.println("NEW PAGE.");

      last_page = current_page;
      
      draw_channel_numbers();
    }
    
    if ((! mid_draw) && (new_page || (bar != last_bar))) {
      last_bar = bar;

      draw_bar_number();

      mid_draw = true;
      track_ix = 0 + 3 * data->page;     
      block_ix = 0;
    }
    
    if (mid_draw) {
        auto track = tracks[track_ix];
        
        draw_line(
          track_ix,
          track,
          block_ix++,
          track_ix == tracks.index()
        );

        if (block_ix == 4) {
          block_ix = 0;
          track_ix++;
        }
        
        if (track_ix == 3 + (3 * data->page)) {
          mid_draw = false;
          track_ix = 0 + 3 * data->page;     
          block_ix = 0;
          
          data->redraw_track.consume();
        }
        else {
          return false;
        }
    } else if (data->redraw_track.consume()) {
      auto t = tracks.current();
      
      draw_line(tracks.index(), t, 0, true);
      draw_line(tracks.index(), t, 1, true);
      draw_line(tracks.index(), t, 2, true);
      draw_line(tracks.index(), t, 3, true);
    }

    if (data->popup_bpm_requested.consume()) {
      popup_bpm_time = millis();
      popup_bpm_state = true;
      redraw_bpm = true;
    }
    
    if (popup_bpm_state) {
      unsigned long now = millis();
      
      if ((now - popup_bpm_time) >= popup_bpm_duration) {
        popup_bpm_state = false;
        data->redraw_selected_track_indicator.set();
      }
    }
    
    draw_line_0(redraw_bpm);
    
    draw_channel_numbers();        

    return true;
  }

////////////////////////////////////////////////////////////////////////////////

  void draw_line(
    uint8_t track_ix,
    tracks::x0x & track,
    uint8_t block,
    bool selected
  ) {
    Serial.print(F("draw_line("));
    Serial.print(track_ix);
    Serial.print(F(", <t>, "));
    Serial.print(block);
    Serial.print(F(", "));
    Serial.print(selected ? "TRUE" : "false");
    Serial.print(F(")"));
    Serial.println();
    
    static const uint8_t col_map[] = {
      1,   2,  3,  4,
      6,   7,  8,  9,
      11, 12, 13, 14,
      16, 17, 18, 19
    };

    static char buff[20] = {
       0 ,  0,   0,   0,   0,
      '|',  0,   0,   0,   0, 
      '|',  0,   0,   0,   0, 
      '|',  0,   0,   0,   0
    };      
  
    buff[0] = selected ?
      lcd::CHAR_INVERSION :
      ('0' + (track_ix + 1));
    
    for (
      uint8_t step = block * 5;
      step < ((block * 5) + 5);
      step++
    ) {
      char character = lcd::CHAR_REST;

      if (track.trigger(step + 16 * data->bar)) {
        character |= 0b100;
      }
      
      buff[col_map[step % 16]] = character; 
    }

    Serial.print(F("Place cursor at "));
    Serial.print(block * 5);
    Serial.print(F(", "));
    Serial.print(track_ix + 1 - (data->page * 3));
    Serial.println();    
    
    lcd::set_cursor(block * 5, track_ix + 1 - (data->page * 3));
    lcd::print_with_nulls(buff + block * 5, 5);
  }

////////////////////////////////////////////////////////////////////////////////

  void draw_line_0(bool const & redraw_bpm = false) {
    if (redraw_bpm) {
      lcd::set_cursor(0, 0);
      lcd::print(F("                  "));

      lcd::set_cursor(0, 0);
      lcd::print(data->bpm);
      if      (data->bpm >= 100) {
        lcd::set_cursor(3, 0);
        lcd::print(F(" BPM"));
      }
      else if (data->bpm >= 10) {
        lcd::set_cursor(2, 0);
        lcd::print(F(" BPM "));
      }
      else {
        lcd::set_cursor(1, 0);
        lcd::print(F(" BPM  "));
      }
 
      lcd::set_cursor(9, 0);
      lcd::print(data->millihz);
      if      (data->millihz >= 1000) {
        lcd::set_cursor(13, 0);
        lcd::print(F(" mhz")); 
      }
      else if (data->millihz >= 100) {
        lcd::set_cursor(12, 0);
        lcd::print(F(" mhz ")); 
      }
      else if (data->millihz >= 10) {
        lcd::set_cursor(11, 0);
        lcd::print(F(" mhz  ")); 
      }
      else {
        lcd::set_cursor(10, 0);
        lcd::print(F(" mhz   ")); 
      }
    }
    
    if (data->redraw_playback_state.consume()) {
      lcd::select_playstate(! data->playback_state);
    }
  }
};

////////////////////////////////////////////////////////////////////////////////

#endif

