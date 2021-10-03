/*
 * center 508
 * upper 890
 * lower 125
 */
void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(analogRead(0));
  delay(100);
}
