#ifndef SLIDER_H
#define SLIDER_H

#include <Arduino.h>

class Slider {
    
    private:
        int pin;
        
        int minInVal;
        int maxInVal;
        int inValue;
        
        int minOutVal;
        int maxOutVal;
        int outValue;
        
    public:
        Slider(int pin);
        Slider(int pin, int outMin, int outMax);
        Slider(int pin, int inMin, int inMax, int outMin, int outMax);
        
        void init();
        void update();
        
        int getValue();
        bool isMin();
        bool isMax();
};

#endif    
        
