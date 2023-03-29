#ifndef ARCADE_BUTTON_H
#define ARCADE_BUTTON_H

#include <Arduino.h>

class ArcadeButton {
  private:
    int buttonPin;
    int ledPin;
    
    bool isPressed;
    bool wasPressed;
    bool state;
    
    bool changedHigh;
    bool changedLow;
    
    bool isMomentary;
    
  public:
    ArcadeButton(int buttonPin, int ledPin);
    ArcadeButton(int buttonPin, int ledPin, bool isMomentary);
    
    void init();
    void update();
    
    void setMode(bool isMomentary);
    
    bool get();
    bool pressed();
    bool released();

    bool getMode();
    
};

#endif 
