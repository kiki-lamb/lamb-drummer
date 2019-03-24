#include "i_screen_state.h"
#include "lcd.h"

IScreenState::IScreenState(): requires_update("requires_update", true) {
  flag();
}

IScreenState::~IScreenState() {
}

void IScreenState::flag() {
  requires_update.flag();
}

static LiquidCrystal & IScreenState::lcd() {
  return Lcd::lcd;
}

void IScreenState::update() { 
  if (requires_update.consume())
    impl_update(); 
}

void IScreenState::enter() { 
  requires_update.consume();
  
  lcd().clear(); 
  
  impl_enter(); 
}

