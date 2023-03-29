#include "Slider.h"

Slider::Slider(int pin){
    this->pin = pin;
    this->minInVal = 0;
    this->maxInVal = 1023;
    
    this->minOutVal = -127;
    this->maxOutVal = 127;
    
    init();
}

Slider::Slider(int pin, int outMin, int outMax){
    this->pin = pin;
    this->minInVal = 0;
    this->maxInVal = 1023;
    
    this->minOutVal = outMin;
    this->maxOutVal = outMax;
    
    init();
}

Slider::Slider(int pin, int inMin, int inMax, int outMin, int outMax){
    this->pin = pin;
    this->minInVal = inMin;
    this->maxInVal = inMax;
    
    this->minOutVal = outMin;
    this->maxOutVal = outMax;
    
    init();
}

void Slider::init(){
    pinMode(pin, INPUT);
    update();
}

void Slider::update(){
    this->inValue = analogRead(pin);
    this->outValue = map(inValue, minInVal, maxInVal ,minOutVal, maxOutVal);
}

int Slider::getValue(){
    return outValue;
}

bool Slider::isMin(){
    return inValue == minInVal;
}

bool Slider::isMax(){
    return inValue == maxInVal;
}

