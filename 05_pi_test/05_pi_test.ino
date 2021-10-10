#include <MsTimer2.h>
#define p_gain 0.7
#define i_gain 0.01
int ang = 0;
int ang_int = 0;
int ang_pre = 0;

void output() {
  if (digitalRead(2)) { //buttonが押下されていない
    //モータ全停止
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    ang_int = 0;
    //    Serial.println("waiting");
  }
  else { //button押下状態
    //    Serial.println("moving");
    //    Serial.print("Angle=");
    ang_pre = ang;
    ang = map(analogRead(0), 125, 890, -100, 100);
    //    Serial.println(ang);
    if (ang * ang_pre < 0){
      ang_int = 0;
    }
    else if(abs(ang_int) < 2147483647) {
      ang_int = ang_int + ang;
    }

    if (ang == 0) {
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
    else if (ang < 0) {
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(5, ang * p_gain + ang_int * i_gain);
    }
    else if (ang > 0) {
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      analogWrite(5, ang * p_gain + ang_int * i_gain);
    }
  }
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(115200);
  MsTimer2::set(5, output);
  MsTimer2::start();
}

void loop() {
  int ang1 = map(analogRead(0), 125, 890, -100, 100);
  Serial.print(ang1);
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(100);
  Serial.print(",");
  Serial.println(-100);
  delay(10);
}
