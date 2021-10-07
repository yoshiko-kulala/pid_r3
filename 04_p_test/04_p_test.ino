#define p_gain 1.0

void setup() {
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (digitalRead(2)) { //buttonが押下されていない
    //モータ全停止
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    //    Serial.println("waiting");
  }
  else { //button押下状態
    //    Serial.println("moving");
    //    Serial.print("Angle=");
    int ang = map(analogRead(0), 125, 890, -100, 100);
    //    Serial.println(ang);
    Serial.print(ang);
    Serial.print(",");
    Serial.print(0);
    Serial.print(",");
    Serial.print(100);
    Serial.print(",");
    Serial.println(-100);

    if (ang == 0) {
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
    else if (ang < 0) {
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      analogWrite(5, -ang * p_gain);
    }
    else if (ang > 0) {
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      analogWrite(5, ang * p_gain);
    }
  }
  //  Serial.println();
  delay(10);
}
