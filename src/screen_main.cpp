#include "screen_main.h"
#include "ui.h"

SSMain::SSMain(data_t * data) :
  IScreen<UiData<TrackCollection<3, Track> > >(data),
  popup_bpm_time(0),
  popup_bpm_state(false)
  {}

void SSMain::draw_channel_numbers() {
  for (uint8_t line = 1; line <= 3; line++) {
    lcd().setCursor(0, line);
    lcd().print(line);
  }

  Lcd::put_inversion(0, (*data->tracks).index() + 1, (*data->tracks).index() + 1);
}

void SSMain::draw_bars() {
  static const uint8_t gap_map[] = { 5, 10, 15 };

  for (uint8_t line = 1; line <= 3; line++)
    for (uint8_t gap = 0; gap <= 2; gap++) {
      lcd().setCursor(gap_map[gap], line);
      lcd().print(F("|"));
    }
}

void SSMain::impl_enter() {
  data->popup_bpm_requested->flag();
  data->redraw_selected_track_indicator->unflag();

  draw_line0();
  Lcd::put_playstate(19,0); // Ugly...

  draw_channel_numbers();
  draw_bars();

  for (uint8_t step = 0; step < 16; step++)
    draw_column(step);

  draw_page_number();

  data->redraw_playback_state->unflag();
//  redraw_bpm->unflag();
}

void SSMain::draw_page_number() {
  lcd().setCursor(18,0);
  lcd().print(data->page+1);
}

void SSMain::draw_line0(bool redraw_bpm) {
  char buf [21];
  char buf2[21];

  if (redraw_bpm) {
    lcd().setCursor(0, 0);
    lcd().print("                  ");

    lcd().setCursor(0, 0);
    snprintf(buf, 21, "%d BPM", data->bpm);
    lcd().print(buf);

    lcd().setCursor(9, 0);
    dtostrf(data->hz, 2, 3, buf2);
    snprintf(buf, 21, "%s hz", buf2);
    lcd().print(buf);
  }
  else {
    //Serial.println("Before rdsi!");
    if (data->redraw_selected_track_indicator->consume()) {
    draw_channel_numbers();

    lcd().setCursor(0, 0);
    lcd().print("                  ");

    lcd().setCursor(0, 0);
    snprintf(buf, 21, "Maj%2d", (*data->tracks)[(*data->tracks).index()].mod_maj());
    lcd().print(buf);

    lcd().setCursor(5, 0);
    lcd().write(byte(223));

    lcd().setCursor(6, 0);
    snprintf(buf, 21, "%-2d", (*data->tracks)[(*data->tracks).index()].phase_maj());
    lcd().print(buf);

    lcd().setCursor(9, 0);
    snprintf(buf, 21, "Min%2d", (*data->tracks)[(*data->tracks).index()].mod_min());
    lcd().print(buf);

    lcd().setCursor(14, 0);
    lcd().write(byte(223));

    lcd().setCursor(15, 0);
    snprintf(buf, 21, "%-2d", (*data->tracks)[(*data->tracks).index()].phase_min());
    lcd().print(buf);
  } }

  //Serial.println("Before rps!");
  if (data->redraw_playback_state->consume()) {
    Lcd::select_playstate(! data->playback_state);
  }
}

void SSMain::impl_update() {
  bool redraw_bpm = false;
  //Serial.println("Before pbr!");
  if (data->popup_bpm_requested->consume()) {
    popup_bpm_time = millis();
    popup_bpm_state = true;
    redraw_bpm = true;
  }

  if (popup_bpm_state) {
    unsigned long now = millis();

    if ((now - popup_bpm_time) >= popup_bpm_duration) {
      popup_bpm_state = false;
      data->redraw_selected_track_indicator->flag();
    }
  }

  draw_line0(redraw_bpm);

  uint8_t prior   = ((uint8_t)((data->ticker>>1)-1)) % (*data->tracks).max_mod_maj(); // Don't remove this cast or the subtraction result becomes a signed type
  uint8_t current = (data->ticker>>1) % (*data->tracks).max_mod_maj();

  //Serial.println("Before rt!");
  bool redraw_page = data->redraw_track->consume();

  if (! redraw_page) {
    static uint8_t last_page = 255;
    uint8_t        tmp_page = data->page;

    if (tmp_page != last_page) {
        last_page = tmp_page;
        redraw_page = true;
    }
  }

  if (redraw_page) {
    draw_page_number();

    for (uint8_t col = 0;  col <= 15; col++)
      draw_column((data->page * 16) + col, false, true);
  }
  else
    draw_column(prior, false);

  draw_column(current, true);
}

void SSMain::draw_column(uint8_t col, bool highlit, bool log_this)  {
  static const uint8_t col_map[] = {
    1,   2,  3,  4,
    6,   7,  8,  9,
    11, 12, 13, 14,
    16, 17, 18, 19
  };

  // uint8_t tmp = (*data->tracks).max_mod_maj();

  for (uint8_t line = 1; line <= 3; line++) {
    uint8_t col_ = col_map[col % (*data->tracks).max_mod_maj() % 16];
    uint8_t tmp = 0;

    if ( (*data->tracks)[line-1].trigger_state(col) ) {
      if (highlit)
        tmp = Lcd::CHAR_HIT_ACTIVE;
      else if (((col - (*data->tracks)[line-1].phase_maj() + 1) % (*data->tracks)[line-1].mod_maj()) == 0)
        tmp = Lcd::CHAR_HIT_BARRIER;
      else
        tmp = Lcd::CHAR_HIT;
    }
    else {
      if (highlit)
        tmp = Lcd::CHAR_REST_ACTIVE;
      else if (((col - (*data->tracks)[line-1].phase_maj() + 1) % (*data->tracks)[line-1].mod_maj()) == 0)
        tmp = Lcd::CHAR_REST_BARRIER;
      else
        tmp = Lcd::CHAR_REST;
    }

    lcd().setCursor(col_, line);
    lcd().write(tmp);
  }
}
