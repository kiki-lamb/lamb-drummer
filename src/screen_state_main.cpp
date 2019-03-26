#include "screen_state_main.h"
#include "ui.h"

SSMain::SSMain(
//   Flag * popup_bpm_requested_,
// //  Flag * redraw_bpm_,
//   Flag * redraw_playback_state_,
//   Flag * redraw_selected_track_indicator_,
//   Flag * redraw_track_
) :
  // popup_bpm_requested(popup_bpm_requested_),
  // //redraw_bpm(redraw_bpm_),
  // redraw_playback_state(redraw_playback_state_),
  // redraw_selected_track_indicator(redraw_selected_track_indicator_),
  // redraw_track(redraw_track_),
  popup_bpm_time(0),
  popup_bpm_state(false)
  {}

void SSMain::draw_channel_numbers(data_t * d) {
  for (uint8_t line = 1; line <= 3; line++) {
    lcd().setCursor(0, line);
    lcd().print(line);
  }

  Lcd::put_inversion(0, (*d->tracks).index() + 1, (*d->tracks).index() + 1);
}

void SSMain::draw_bars(data_t * d) {
  static const uint8_t gap_map[] = { 5, 10, 15 };

  for (uint8_t line = 1; line <= 3; line++)
    for (uint8_t gap = 0; gap <= 2; gap++) {
      lcd().setCursor(gap_map[gap], line);
      lcd().print(F("|"));
    }
}

void SSMain::impl_enter(SSIntro::data_t * d) {
  SSIntro::data_t * d_ = d;

  d->popup_bpm_requested->flag();
  d->redraw_selected_track_indicator->unflag();

  draw_line0(d);
  Lcd::put_playstate(19,0); // Ugly...

  draw_channel_numbers(d);
  draw_bars(d);

  for (uint8_t step = 0; step < 16; step++)
    draw_column(d, step);

  draw_page_number(d);

  d->redraw_playback_state->unflag();
//  redraw_bpm->unflag();
}

void SSMain::draw_page_number(data_t * d) {
  lcd().setCursor(18,0);
  lcd().print(d->page+1);
}

void SSMain::draw_line0(SSMain::data_t * d, bool redraw_bpm) {
  char buf [21];
  char buf2[21];

  if (redraw_bpm) {
    lcd().setCursor(0, 0);
    lcd().print("                  ");

    lcd().setCursor(0, 0);
    snprintf(buf, 21, "%d BPM", d->bpm);
    lcd().print(buf);

    lcd().setCursor(9, 0);
    dtostrf(d->hz, 2, 3, buf2);
    snprintf(buf, 21, "%s hz", buf2);
    lcd().print(buf);
  }
  else {
    //Serial.println("Before rdsi!");
    if (d->redraw_selected_track_indicator->consume()) {
    draw_channel_numbers(d);

    lcd().setCursor(0, 0);
    lcd().print("                  ");

    lcd().setCursor(0, 0);
    snprintf(buf, 21, "Maj%2d", (*d->tracks)[(*d->tracks).index()].mod_maj());
    lcd().print(buf);

    lcd().setCursor(5, 0);
    lcd().write(byte(223));

    lcd().setCursor(6, 0);
    snprintf(buf, 21, "%-2d", (*d->tracks)[(*d->tracks).index()].phase_maj());
    lcd().print(buf);

    lcd().setCursor(9, 0);
    snprintf(buf, 21, "Min%2d", (*d->tracks)[(*d->tracks).index()].mod_min());
    lcd().print(buf);

    lcd().setCursor(14, 0);
    lcd().write(byte(223));

    lcd().setCursor(15, 0);
    snprintf(buf, 21, "%-2d", (*d->tracks)[(*d->tracks).index()].phase_min());
    lcd().print(buf);
  } }

  //Serial.println("Before rps!");
  if (d->redraw_playback_state->consume()) {
    Lcd::select_playstate(! d->playback_state);
  }
}

void SSMain::impl_update(SSIntro::data_t * d) {
  bool redraw_bpm = false;
  //Serial.println("Before pbr!");
  if (d->popup_bpm_requested->consume()) {
    popup_bpm_time = millis();
    popup_bpm_state = true;
    redraw_bpm = true;
  }

  if (popup_bpm_state) {
    unsigned long now = millis();

    if ((now - popup_bpm_time) >= popup_bpm_duration) {
      popup_bpm_state = false;
      d->redraw_selected_track_indicator->flag();
    }
  }

  draw_line0(d, redraw_bpm);

  uint8_t prior   = ((uint8_t)((d->ticker>>1)-1)) % (*d->tracks).max_mod_maj(); // Don't remove this cast or the subtraction result becomes a signed type
  uint8_t current = (d->ticker>>1) % (*d->tracks).max_mod_maj();

  //Serial.println("Before rt!");
  bool redraw_page = d->redraw_track->consume();

  if (! redraw_page) {
    static uint8_t last_page = 255;
    uint8_t        tmp_page = d->page;

    if (tmp_page != last_page) {
        last_page = tmp_page;
        redraw_page = true;
    }
  }

  if (redraw_page) {
    draw_page_number(d);

    for (uint8_t col = 0;  col <= 15; col++)
      draw_column(d, (d->page * 16) + col, false, true);
  }
  else
    draw_column(d, prior, false);

  draw_column(d, current, true);
}

void SSMain::draw_column(SSMain::data_t * d, uint8_t col, bool highlit, bool log_this)  {
  static const uint8_t col_map[] = {
    1,   2,  3,  4,
    6,   7,  8,  9,
    11, 12, 13, 14,
    16, 17, 18, 19
  };

  uint8_t tmp = (*d->tracks).max_mod_maj();

  for (uint8_t line = 1; line <= 3; line++) {
    uint8_t col_ = col_map[col % (*d->tracks).max_mod_maj() % 16];
    uint8_t tmp = 0;

    if ( (*d->tracks)[line-1].trigger_state(col) ) {
      if (highlit)
        tmp = Lcd::CHAR_HIT_ACTIVE;
      else if (((col - (*d->tracks)[line-1].phase_maj() + 1) % (*d->tracks)[line-1].mod_maj()) == 0)
        tmp = Lcd::CHAR_HIT_BARRIER;
      else
        tmp = Lcd::CHAR_HIT;
    }
    else {
      if (highlit)
        tmp = Lcd::CHAR_REST_ACTIVE;
      else if (((col - (*d->tracks)[line-1].phase_maj() + 1) % (*d->tracks)[line-1].mod_maj()) == 0)
        tmp = Lcd::CHAR_REST_BARRIER;
      else
        tmp = Lcd::CHAR_REST;
    }

    lcd().setCursor(col_, line);
    lcd().write(tmp);
  }
}
