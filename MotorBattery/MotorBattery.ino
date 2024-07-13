int switchPin = 2;
int motorPin = 9;
int switchState = 0;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
  Serial.println("LOOPS");
  switchState = digitalRead(switchPin);

  if (switchState == HIGH) {
    digitalWrite(motorPin, HIGH);
    Serial.println("HIGH");

  } else {
    digitalWrite(motorPin, LOW);
    Serial.println("LOW");
  }
}
