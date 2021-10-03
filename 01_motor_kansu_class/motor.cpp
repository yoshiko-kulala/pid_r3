#include <Arduino.h>
#include "motor.h"

Motor::Motor() {
}

void Motor::init(int a, int b,int t) {
  a_pin = a;
  b_pin = b;
  timer=t;
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  ledcSetup(timer*2, 1280, 8);
  ledcSetup(timer*2+1, 1280, 8);
  ledcAttachPin(a_pin, timer*2);
  ledcAttachPin(b_pin, timer*2+1);
}

void Motor::SetSpd(int spd) {
  spd=max(min(spd,255),-255);
  if (spd < 0) {
    ledcWrite(timer*2, 0);
    ledcWrite(timer*2+1, abs(spd));
  }
  else {
    ledcWrite(timer*2, spd);
    ledcWrite(timer*2+1, 0);
  }  
}
