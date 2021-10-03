void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(13, HIGH);
  for (int i = 0; i < 255; i++) {
    analogWrite(5, i);
    delay(10);
  }
  for (int i = 255; i >0; i--) {
    analogWrite(5, i);
    delay(10);
  }
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(13, LOW);
  for (int i = 0; i < 255; i++) {
    analogWrite(5, i);
    delay(10);
  }
  for (int i = 255; i >0; i--) {
    analogWrite(5, i);
    delay(10);
  }
}
