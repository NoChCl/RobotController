#include "DipSwitch.h"

DipSwitch::DipSwitch(int pin, int vals[16]) {
  this->pin = pin;
  for (int i = 0; i<16; i++){
    this->vals[i] = vals[i];
  }
  this->margin = 2;
  init();
}

DipSwitch::DipSwitch(int pin, int vals[16], int margin) {
  this->pin = pin;
  for (int i = 0; i<16; i++){
    this->vals[i] = vals[i];
  }  this->margin = margin;
  init();
}

void DipSwitch::init(){
  pinMode(pin, INPUT);
  update();
}

void DipSwitch::update(){
  this->value = analogRead(pin);

  if (value >= vals[0]-margin && value <= vals[0]+margin){
      this->switch1 = false;
      this->switch2 = false;
      this->switch3 = false;
      this->switch4 = false;
  } else if (value >= vals[1]-margin && value <= vals[1]+margin){
      this->switch1 = false;
      this->switch2 = false;
      this->switch3 = false;
      this->switch4 = true;
  } else if (value >= vals[2]-margin && value <= vals[2]+margin){
      this->switch1 = false;
      this->switch2 = false;
      this->switch3 = true;
      this->switch4 = false;
  } else if (value >= vals[3]-margin && value <= vals[3]+margin){
      this->switch1 = false;
      this->switch2 = false;
      this->switch3 = true;
      this->switch4 = true;
  } else if (value >= vals[4]-margin && value <= vals[4]+margin){
      this->switch1 = false;
      this->switch2 = true;
      this->switch3 = false;
      this->switch4 = false;
  } else if (value >= vals[5]-margin && value <= vals[5]+margin){
      this->switch1 = false;
      this->switch2 = true;
      this->switch3 = false;
      this->switch4 = true;
  } else if (value >= vals[6]-margin && value <= vals[6]+margin){
      this->switch1 = false;
      this->switch2 = true;
      this->switch3 = true;
      this->switch4 = false;
  } else if (value >= vals[7]-margin && value <= vals[7]+margin){
      this->switch1 = false;
      this->switch2 = true;
      this->switch3 = true;
      this->switch4 = true;
  } else if (value >= vals[8]-margin && value <= vals[8]+margin){
      this->switch1 = true;
      this->switch2 = false;
      this->switch3 = false;
      this->switch4 = false;
  } else if (value >= vals[9]-margin && value <= vals[9]+margin){
      this->switch1 = true;
      this->switch2 = false;
      this->switch3 = false;
      this->switch4 = true;
  } else if (value >= vals[10]-margin && value <= vals[10]+margin){
      this->switch1 = true;
      this->switch2 = false;
      this->switch3 = true;
      this->switch4 = false;
  } else if (value >= vals[11]-margin && value <= vals[11]+margin){
      this->switch1 = true;
      this->switch2 = false;
      this->switch3 = true;
      this->switch4 = true;
  } else if (value >= vals[12]-margin && value <= vals[12]+margin){
      this->switch1 = true;
      this->switch2 = true;
      this->switch3 = false;
      this->switch4 = false;
  } else if (value >= vals[13]-margin && value <= vals[13]+margin){
      this->switch1 = true;
      this->switch2 = true;
      this->switch3 = false;
      this->switch4 = true;
  } else if (value >= vals[14]-margin && value <= vals[14]+margin){
      this->switch1 = true;
      this->switch2 = true;
      this->switch3 = true;
      this->switch4 = false;
  } else if (value >= vals[15]-margin && value <= vals[15]+margin){
      this->switch1 = true;
      this->switch2 = true;
      this->switch3 = true;
      this->switch4 = true;
  }
}

bool DipSwitch::get(int sw) {
  if (sw ==1) return switch1;
  if (sw ==2) return switch2;
  if (sw ==3) return switch3;
  if (sw ==4) return switch4;
  return false;
}

int DipSwitch::getRaw(){
    return value;
} 
