#ifndef DIP_SWITCH_H
#define DIP_SWITCH_H

#include <Arduino.h>

class DipSwitch {
  private:
    int pin;
    int vals[16];
    int margin;
    
    int value;
    bool switch1;
    bool switch2;
    bool switch3;
    bool switch4;
    
    
  public:
    DipSwitch(int pin, int vals[16]);
    DipSwitch(int pin, int vals[16], int margin);
    
    void init();
    void update();
    
    bool get(int sw);
    int getRaw();
};

#endif 
