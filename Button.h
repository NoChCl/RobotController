#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  private:
    int pin;
    
    bool isPressed;
    bool wasPressed;
    
    bool changedHigh;
    bool changedLow;
    
    
  public:
    Button(int pin);
    
    void init();
    void update();
    
    bool get();
    bool pressed();
    bool released();
};

#endif 
