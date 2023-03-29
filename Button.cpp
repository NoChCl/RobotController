#include "Button.h"

Button::Button(int pin) {
  this->pin = pin;
  init();
}

void Button::init(){
  pinMode(pin, INPUT_PULLUP);
  update();
}

void Button::update(){
  this->wasPressed = isPressed;
  this->isPressed = !digitalRead(pin);
  
  if (!wasPressed && isPressed){
      this->changedHigh = true;
      this->changedLow = false;
  } else if (wasPressed && !isPressed){
      this->changedHigh = false;
      this->changedLow = true;
  } else {
      this->changedHigh = false;
      this->changedLow = false;
  }
}

bool Button::get() {
  return isPressed;
}

bool Button::pressed() {
  return changedHigh;
}

bool Button::released() {
  return changedLow;
}
