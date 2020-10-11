#ifndef LAMB_DRUMMER_SCREEN_STATE_MAIN_H
#define LAMB_DRUMMER_SCREEN_STATE_MAIN_H

#include <lamb.h>
#include "Arduino.h"
#include "screen.h"
#include "ui_data/ui_data.h"
#include "track_collection/track_collection.h"
#include "tracks/euclidean.h"
#include "tracks/x0x.h"

////////////////////////////////////////////////////////////////////////////////

template <typename data_t>
class screen_main :
  public screen<data_t> {
  
private:
  virtual void      impl_enter() override;

  virtual bool      impl_update() override;
};

////////////////////////////////////////////////////////////////////////////////
// screen_main<ui_data<track_collection<3, tracks::euclidean> > >
////////////////////////////////////////////////////////////////////////////////

template <>
class screen_main<ui_data<track_collection<3, tracks::euclidean> > > :
  public screen<ui_data<track_collection<3, tracks::euclidean> > > {

  typedef ui_data<track_collection<3, tracks::euclidean> > data_t;
  typedef screen<data_t> base_t;
  
public:
  screen_main(data_t * data) :
    base_t(data),
    popup_bpm_time(0),
    popup_bpm_state(false) {}
  
private:

////////////////////////////////////////////////////////////////////////////////

  virtual void impl_enter() override {
    data->popup_bpm_requested.set();
    
    draw_line_0();
    
    lcd::put_playstate(19,0); // Ugly...
    
    draw_channel_numbers();
    
    draw_bars();
    
    for (
      uint8_t step = 0, mmm = max_mod_maj(*data->tracks);
      step < 16;
      step++) {
      draw_column(step, mmm);
    }
    
    draw_bar_number();
  }

////////////////////////////////////////////////////////////////////////////////

  virtual bool impl_update() override {
    bool redraw_bpm = false;
    
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
    
    bool redraw_bar = false;
    
    static uint8_t last_bar = 255;
    uint8_t        tmp_bar = data->bar;
    
    if (tmp_bar != last_bar) {
      last_bar = tmp_bar;
      redraw_bar = true;
    }
    
    uint8_t mmm = max_mod_maj(*data->tracks);
    
    if (redraw_bar) {
      draw_bar_number();
      
      for (uint8_t col = 0;  col < 16; col++) {
        draw_column((data->bar * 16) + col, mmm);
      }
      
      data->redraw_track.consume();
    } else if (data->redraw_track.consume()) {
      for (uint8_t col = 0;  col < 16; col++) {
        draw_column((*data->tracks).index(), (data->bar * 16) + col, mmm);
      }
    }

    return true;
  }

////////////////////////////////////////////////////////////////////////////////
  
  void draw_bars() {
    static const uint8_t gap_map[] = { 5, 10, 15 };
    
    for (uint8_t line = 1; line <= 3; line++)
      for (uint8_t gap = 0; gap <= 2; gap++) {
        lcd::set_cursor(gap_map[gap], line);
        lcd::print(F("|"));
      }
  }

////////////////////////////////////////////////////////////////////////////////

  void draw_channel_numbers() {
    static uint8_t last_selected = 0xff;
    uint8_t selected = (*data->tracks).index() + 1;
    
    if (selected !=last_selected) {
      for (uint8_t line = 1; line <= 3; line++) {
        if (line == selected) continue;
        
        lcd::set_cursor(0, line);
        lcd::print(line);
      }
      
      lcd::put_inversion(
        0,
        selected,
        selected
      );
      
      last_selected = selected;
    }
  }

////////////////////////////////////////////////////////////////////////////////

  void 		    draw_column(
    uint8_t const & col,
    uint8_t const & mod_maj
  ) {
    for (uint8_t line = 1; line <= 3; line++) {
      draw_column(line-1, col, mod_maj);
    }
  }

////////////////////////////////////////////////////////////////////////////////
  
  void 		    draw_column(
    uint8_t const & channel,
    uint8_t const & col,
    uint8_t const & mod_maj
  ) {
    tracks::euclidean const & t = (*data->tracks)[channel];
    
    static const uint8_t col_map[] = {
      1,   2,  3,  4,
      6,   7,  8,  9,
      11, 12, 13, 14,
      16, 17, 18, 19
    };
    
    int8_t col_ = col_map[col % mod_maj % 16];  
    
    uint8_t character  = lcd::CHAR_REST;
    bool    on_barrier = ((col - t.phase_maj() + 1) % t.mod_maj()) == 0;
    bool    is_hit     = t.trigger(col);
    
    if (on_barrier)
      character |= 0b011;
    
    if (is_hit)
      character |= 0b100;
    
    lcd::set_cursor(col_, channel + 1);
    lcd::write(character);
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
    else if (data->redraw_selected_track_indicator.consume()) {
      tracks::euclidean const & track  =
        (*data->tracks)[(*data->tracks).index()];
 
      lcd::set_cursor(0, 0);
      lcd::print(F("                  "));
 
      lcd::set_cursor(0, 0);
      lcd::print(F("Maj"));
      if (track.mod_maj() < 10) {
        lcd::print(' ');
        lcd::print(track.mod_maj());
      }
      else {
        lcd::print(track.mod_maj());
      }

      lcd::set_cursor(5, 0);
      lcd::write(byte(223));

      lcd::set_cursor(6, 0);
      if (track.phase_maj() < 10) {
        lcd::print(track.phase_maj());
      }
      else {
        lcd::print(track.phase_maj());
        lcd::print(' ');
      }

      lcd::set_cursor(9, 0);
      lcd::print(F("Min"));
      if (track.mod_min() < 10) { 
        lcd::print(' ');
        lcd::print(track.mod_min());
      }
      else {
        lcd::print(track.mod_min());
      }

      lcd::set_cursor(14, 0);
      lcd::write(byte(223));

      lcd::set_cursor(15, 0);
      if (track.phase_min() < 10) {
        lcd::print(track.phase_min());
      }
      else {
        lcd::print(track.phase_min());
        lcd::print(' ');
      }
    }

    if (data->redraw_playback_state.consume()) {
      lcd::select_playstate(! data->playback_state);
    }
  }

////////////////////////////////////////////////////////////////////////////////

  void draw_bar_number() {
    lcd::set_cursor(18,0);
    lcd::print(data->bar+1);
  }

////////////////////////////////////////////////////////////////////////////////
  
  template <size_t size>
  uint8_t max_mod_maj(
    track_collection<size, tracks::euclidean> const & that
  ) {
    uint8_t max = 0;
    
    for (uint8_t ix = 0; ix < that.size(); ix++)
      if (that[ix].mod_maj() > max)
        max = that[ix].mod_maj();
    
    return max;
  }
                      
  unsigned long popup_bpm_time;
  bool          popup_bpm_state;
  static const unsigned long popup_bpm_duration = 600;
};

////////////////////////////////////////////////////////////////////////////////
// screen_main<ui_data<track_collection<3, tracks::x0x > > >
////////////////////////////////////////////////////////////////////////////////

template <>
class screen_main<ui_data<track_collection<3, tracks::x0x > > > :
  public screen<ui_data<track_collection<3, tracks::x0x > > > {

  typedef ui_data<track_collection<3, tracks::x0x > > data_t;
  typedef screen<data_t> base_t;

  static const uint8_t track_count = 3;
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
    
    draw_bars();
    
//    for (
//      uint8_t step = 0;
//      step < 16;
//      step++) {
//      draw_line(step);
//    }
    
    draw_bar_number();
  }
  
////////////////////////////////////////////////////////////////////////////////

  void draw_bars() {
    static const uint8_t gap_map[] = { 5, 10, 15 };
    
    for (uint8_t line = 1; line <= 3; line++)
      for (uint8_t gap = 0; gap <= 2; gap++) {
        lcd::set_cursor(gap_map[gap], line);
        lcd::print(F("|"));
      }
  }
  
////////////////////////////////////////////////////////////////////////////////
  
  void draw_channel_numbers() {
    static uint8_t last_selected = 0xff;
    uint8_t selected = (*data->tracks).index() + 1;
    
    if (selected !=last_selected) {
      for (uint8_t line = 1; line <= 3; line++) {
        if (line == selected) continue;
        
        lcd::set_cursor(0, line);
        lcd::print(line);
      }
      
      lcd::put_inversion(
        0,
        selected,
        selected
      );
      
      last_selected = selected;
    }
  }

////////////////////////////////////////////////////////////////////////////////

  virtual bool impl_update() override {
    bool redraw_bpm = false;
    
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
    
    static uint8_t last_bar = 255;
    uint8_t        tmp_bar  = data->bar;
    auto           tracks   = (*data->tracks);
    static bool    mid_draw = false;
    static uint8_t track_ix = 0;
    
    if (tmp_bar != last_bar) {
      last_bar   = tmp_bar;

      draw_bar_number();

      mid_draw = true;
    }
    
    if (mid_draw) {
        auto track = tracks[track_ix];

        draw_line(track_ix++, track);
             
        if (track_ix == 3) {
          mid_draw = false;
          track_ix = 0;
          data->redraw_track.consume();
        }
        else {
          requires_update.set();
          
          return false;
        }
    } else if (data->redraw_track.consume()) {
      auto t = tracks.current();
      
      draw_line(tracks.index(), t);
    }

    return true;
  }

////////////////////////////////////////////////////////////////////////////////

  void draw_line(uint8_t track_ix, tracks::x0x & track) {
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
  
    buff[0]  = '0' + track_ix;
    
    for (uint8_t step = 0; step < 16; step++) {
      char character = lcd::CHAR_REST;

      if (track.trigger(step + 16 * data->bar)) {
        character |= 0b100;
      }
      
      buff[col_map[step % 16]] = character; 
    }
        
    lcd::set_cursor(0, track_ix + 1);
    lcd::print_with_nulls(buff, 20);
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

#endif
