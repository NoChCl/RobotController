#include "Slider.h"
#include "Button.h"
#include "ArcadeButton.h"
#include "DipSwitch.h"

#include "Joystick.h"

#define SLIDER_MIN 0
#define SLIDER_MAX 255

Joystick_ Joystick;

Slider slider1(A3, SLIDER_MIN, SLIDER_MAX);
Slider slider2(A2, SLIDER_MIN, SLIDER_MAX);
Slider slider3(A1, SLIDER_MIN, SLIDER_MAX);
Slider slider4(A0, SLIDER_MIN, SLIDER_MAX);

int vals[] = {0,
              91,
              178,
              242,
              317,
              363,
              408,
              443,
              512,
              536,
              561,
              582,
              607,
              623,
              640,
              654};
DipSwitch dipSwitch(A6, vals, 5);

Button latchingButton1(2);
Button latchingButton2(3);

ArcadeButton button3(15, 14, false);
ArcadeButton button4(16, 10, false);
ArcadeButton button2(6, 7, false);
ArcadeButton button1(8, 9, false);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Joystick.setXAxisRange(SLIDER_MIN, SLIDER_MAX);
  Joystick.setRxAxisRange(SLIDER_MIN, SLIDER_MAX);
  Joystick.setYAxisRange(SLIDER_MIN, SLIDER_MAX);
  Joystick.setRyAxisRange(SLIDER_MIN, SLIDER_MAX);
  Joystick.begin();
}

void loop() {
  updateState();
  setJoystick();

  delay(2);
}

void updateState(){
  slider1.update();
  slider2.update();
  slider3.update();
  slider4.update();

  dipSwitch.update();
  button1.setMode(dipSwitch.get(1));
  button1.update();
  button2.setMode(dipSwitch.get(2));
  button2.update();
  button3.setMode(dipSwitch.get(3));
  button3.update();
  button4.setMode(dipSwitch.get(4));
  button4.update();

  latchingButton1.update();
  latchingButton2.update();
}

void setJoystick(){
  Joystick.setXAxis(slider1.getValue());  
  Joystick.setRxAxis(slider2.getValue());
  Joystick.setYAxis(slider3.getValue());
  Joystick.setRyAxis(slider4.getValue());

  Joystick.setButton(0, button1.get());
  Joystick.setButton(1, button2.get());
  Joystick.setButton(2, button3.get());
  Joystick.setButton(3, button4.get());

  Joystick.setButton(4, latchingButton1.get());
  Joystick.setButton(5, latchingButton2.get());
}
