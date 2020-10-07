#include "screens/screen_main.h"
#include "application.h"
#include "util/util.h"
#include "Adafruit_MCP23017.h"

screen_main::screen_main(data_t * data) :
  screen<ui_data<track_collection<3, track> > >(data),
  popup_bpm_time(0),
  popup_bpm_state(false)
  {}

void screen_main::draw_channel_numbers() {
  for (uint8_t line = 1; line <= 3; line++) {
    lcd::set_cursor(0, line);
    lcd::print(line);
  }

  lcd::put_inversion(
    0,
    (*data->tracks).index() + 1,
    (*data->tracks).index() + 1
  );
}

void screen_main::draw_bars() {
  static const uint8_t gap_map[] = { 5, 10, 15 };

  for (uint8_t line = 1; line <= 3; line++)
    for (uint8_t gap = 0; gap <= 2; gap++) {
      lcd::set_cursor(gap_map[gap], line);
      lcd::print(F("|"));
    }
}

void screen_main::impl_enter() {
  data->popup_bpm_requested.set();

  draw_line0();

  lcd::put_playstate(19,0); // Ugly...

  draw_channel_numbers();

  draw_bars();

  for (uint8_t step = 0, mmm = (*data->tracks).max_mod_maj(); step < 16; step++)
    draw_column(step, mmm);

  draw_page_number();
}

void screen_main::draw_page_number() {
  lcd::set_cursor(18,0);
  lcd::print(data->page+1);
}

void screen_main::draw_line0(bool const & redraw_bpm) {
  if (redraw_bpm) {
    lcd::set_cursor(0, 0);
    lcd::print(F("                  "));

    lcd::set_cursor(0, 0);
    lcd::print(data->bpm);
    if      (data->bpm >= 100) {
      lcd::set_cursor(3, 0);
      lcd::print(" BPM");
    }
    else if (data->bpm >= 10) {
      lcd::set_cursor(2, 0);
      lcd::print(" BPM ");
    }
    else {
      lcd::set_cursor(1, 0);
      lcd::print(" BPM  ");
    }
    
    lcd::set_cursor(9, 0);
    lcd::print(data->millihz);
    if      (data->millihz >= 1000) {
      lcd::set_cursor(13, 0);
      lcd::print(" mhz"); 
    }
    else if (data->millihz >= 100) {
      lcd::set_cursor(12, 0);
      lcd::print(" mhz "); 
    }
    else if (data->millihz >= 10) {
      lcd::set_cursor(11, 0);
      lcd::print(" mhz  "); 
    }
    else {
      lcd::set_cursor(10, 0);
      lcd::print(" mhz   "); 
    }
  }
  else if (data->redraw_selected_track_indicator.consume()) {
    track const & track  = (*data->tracks)[(*data->tracks).index()];
    
    lcd::set_cursor(0, 0);
    lcd::print("                  ");
    
    lcd::set_cursor(0, 0);
    lcd::print("Maj");
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
    lcd::print("Min");
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

void screen_main::impl_update() {
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

  draw_line0(redraw_bpm);

  draw_channel_numbers();

  uint8_t prior   = ((uint8_t)((data->ticker>>1)-1)) % (*data->tracks).max_mod_maj(); // Don't remove this cast or the subtraction result becomes a signed type
  uint8_t current = (data->ticker>>1) % (*data->tracks).max_mod_maj();

  ////Serial.println("Before rt!");
  bool redraw_page = data->redraw_track.consume();

  if (! redraw_page) {
    static uint8_t last_page = 255;
    uint8_t        tmp_page = data->page;

    if (tmp_page != last_page) {
        last_page = tmp_page;
        redraw_page = true;
    }
  }

  uint8_t mmm = (*data->tracks).max_mod_maj();

  if (redraw_page) {
    draw_page_number();
    for (uint8_t col = 0;  col <= 15; col++)
      draw_column((data->page * 16) + col, mmm);
  }
}

void screen_main::draw_column(
  uint8_t const & col,
  uint8_t const & mod_maj
)  {
  static const uint8_t col_map[] = {
    1,   2,  3,  4,
    6,   7,  8,  9,
    11, 12, 13, 14,
    16, 17, 18, 19
  };

  int8_t col_ = col_map[col % mod_maj % 16];
  
  for (uint8_t line = 1; line <= 3; line++) {
    track const & t = (*data->tracks)[line-1];
    
    uint8_t character  = lcd::CHAR_REST;
    bool    on_barrier = ((col - t.phase_maj() + 1) % t.mod_maj()) == 0;
    bool    is_hit     = t.trigger_state(col);
    
    if (on_barrier)
      character |= 0b011;
    
    if ( is_hit )
      character |= 0b100;
    
    lcd::set_cursor(col_, line);
    lcd::write(character);
  }
}
