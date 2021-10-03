//motor_test

#include "motor.h"

Motor m1;
Motor m2;

void setup() {
  // put your setup code here, to run once:
  m1.init(26, 25, 0);
  m2.init(32, 33, 1);
}

void loop() {
    m1.SetSpd(0);
    m2.SetSpd(0);
    delay(10);
}
