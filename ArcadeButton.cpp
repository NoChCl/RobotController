#include "ArcadeButton.h"

ArcadeButton::ArcadeButton(int buttonPin, int ledPin) {
  this->buttonPin = buttonPin;
  this->ledPin = ledPin;
  this->isMomentary = true;
  this->state = false;
  init();
}

ArcadeButton::ArcadeButton(int buttonPin, int ledPin, bool isMomentary) {
  this->buttonPin = buttonPin;
  this->ledPin = ledPin;
  this->isMomentary = isMomentary;
  this->state = false;
  init();
}


void ArcadeButton::init(){
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  update();
}

void ArcadeButton::update(){
  this->wasPressed = isPressed;
  this->isPressed = !digitalRead(buttonPin);
  
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
  
  if (isMomentary){
    this->state = isPressed;
  } else {
    if (changedHigh){
      state = !state;
    }
  }
  
  digitalWrite(ledPin, state);
}

void ArcadeButton::setMode(bool isMomentary){
  this->isMomentary = isMomentary;
}

bool ArcadeButton::get() {
  return state;
}

bool ArcadeButton::pressed() {
  return changedHigh;
}

bool ArcadeButton::released() {
  return changedLow;
}

bool ArcadeButton::getMode() {
  return isMomentary;
}
