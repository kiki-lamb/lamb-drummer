#include "screen_state_main.h"
#include "ui.h"

static const unsigned long SSMain::POP_DURATION = 600;

SSMain::SSMain() : popup_bpm_time(0), popup_bpm_state(false) {}

Application::collection_t const & SSMain::track_states() {
  return Application::track_states();
}

void SSMain::draw_channel_numbers() const {
  for (uint8_t line = 1; line <= 3; line++) {
    lcd().setCursor(0, line);
    lcd().print(line);
  }  

  Lcd::put_inversion(0, track_states().index() + 1, track_states().index() + 1);
}

void SSMain::draw_bars() const {
  static const uint8_t gap_map[] = { 5, 10, 15 };  

  for (uint8_t line = 1; line <= 3; line++)
    for (uint8_t gap = 0; gap <= 2; gap++) {
      lcd().setCursor(gap_map[gap], line);
      lcd().print(F("|"));
    }
}

void SSMain::impl_enter() {
  Ui::flag_popup_bpm();
  Ui::redraw_selected_track_indicator.unflag();
  
  draw_line0();
  Lcd::put_playstate(19,0);

  draw_channel_numbers();
  draw_bars();

  for (uint8_t step = 0; step < 16; step++)
    draw_column(step);

  draw_page_number();
  
  Ui::redraw_playback_state.unflag();
  Ui::redraw_bpm.unflag();
}

void SSMain::draw_page_number() const {
  lcd().setCursor(18,0);
  lcd().print(Application::page()+1);
}

void SSMain::draw_line0() const {
// Must consume:
//  Ui::redraw_playback_state
//  Ui::redraw_bpm
//  Ui::redraw_selected_track_indicator)

  char buf [21];
  char buf2[21];
  
  if (Ui::redraw_bpm.consume()) {  
    lcd().setCursor(0, 0);
    lcd().print("                  ");
    
    lcd().setCursor(0, 0);
    snprintf(buf, 21, "%d BPM", Application::bpm());
    lcd().print(buf);
    
    lcd().setCursor(9, 0);
    dtostrf(Application::hz(), 2, 3, buf2);
    snprintf(buf, 21, "%s hz", buf2);
    lcd().print(buf);
  }
  else if (Ui::redraw_selected_track_indicator.consume()) {
    draw_channel_numbers();

    lcd().setCursor(0, 0);
    lcd().print("                  ");
    
    lcd().setCursor(0, 0);
    snprintf(buf, 21, "Maj%2d", track_states()[track_states().index()].mod_maj());
    lcd().print(buf);

    lcd().setCursor(5, 0);
    lcd().write(byte(223));
 
    lcd().setCursor(6, 0);
    snprintf(buf, 21, "%-2d", track_states()[track_states().index()].phase_maj());
    lcd().print(buf);

    lcd().setCursor(9, 0);
    snprintf(buf, 21, "Min%2d", track_states()[track_states().index()].mod_min());
    lcd().print(buf);

    lcd().setCursor(14, 0);
    lcd().write(byte(223));

    lcd().setCursor(15, 0);
    snprintf(buf, 21, "%-2d", track_states()[track_states().index()].phase_min());
    lcd().print(buf);
  }

  if (Ui::redraw_playback_state.consume()) { 
    Lcd::select_playstate(! Application::playback_state()); 
  }
}

void SSMain::impl_update() {
  if (Ui::popup_bpm_requested.consume()) {
    popup_bpm_time = millis();
    popup_bpm_state = true;
    Ui::redraw_bpm.flag();
  }

  if (popup_bpm_state) {
    unsigned long now = millis();
    
    if ((now - popup_bpm_time) >= POP_DURATION) {
      popup_bpm_state = false;
      Ui::redraw_selected_track_indicator.flag();
    }
  }
 
  draw_line0();

  uint8_t prior   = ((uint8_t)((Application::ticker()>>1)-1)) % track_states().max_mod_maj(); // Don't remove this cast or the subtraction result becomes a signed type
  uint8_t current = (Application::ticker()>>1) % track_states().max_mod_maj();
  bool redraw_page = Ui::redraw_track.consume(); 
  
  if (! redraw_page) {
    static uint8_t last_page = 255;
    uint8_t        tmp_page = Application::page();

    if (tmp_page != last_page) {
        last_page = tmp_page;
        redraw_page = true;
    }
  }

  if (redraw_page) {
    draw_page_number();
      
    for (uint8_t col = 0;  col <= 15; col++)
      draw_column((Application::page() * 16) + col, false, true);
  }
  else
    draw_column(prior, false);

  draw_column(current, true); 
}
  
void SSMain::draw_column(uint8_t col, bool highlit = false, bool log_this = false) const {  
  static const uint8_t col_map[] = { 
    1,   2,  3,  4, 
    6,   7,  8,  9, 
    11, 12, 13, 14,
    16, 17, 18, 19 
  };

  uint8_t tmp = track_states().max_mod_maj();
  
  for (uint8_t line = 1; line <= 3; line++) {
    uint8_t col_ = col_map[col % track_states().max_mod_maj() % 16];
    uint8_t tmp = 0;

    if ( track_states()[line-1].trigger_state(col) ) {
      if (highlit) 
        tmp = Lcd::CHAR_HIT_ACTIVE;
      else if (((col - track_states()[line-1].phase_maj() + 1) % track_states()[line-1].mod_maj()) == 0)
        tmp = Lcd::CHAR_HIT_BARRIER;
      else 
        tmp = Lcd::CHAR_HIT;
    }
    else {
      if (highlit)
        tmp = Lcd::CHAR_REST_ACTIVE;
      else if (((col - track_states()[line-1].phase_maj() + 1) % track_states()[line-1].mod_maj()) == 0)
        tmp = Lcd::CHAR_REST_BARRIER;
      else
        tmp = Lcd::CHAR_REST; 
    }
      
    lcd().setCursor(col_, line);
    lcd().write(tmp);
  }
}


