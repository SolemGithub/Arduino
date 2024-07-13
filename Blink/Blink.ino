

const int sensorPin = A0;
void setup() {

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);

  for (int i = 3; i < 6; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float volt = (sensorVal / 1024.0) * 5;
  float temp = (volt - 0.5) * 100;

  Serial.print("Sensor ");
  Serial.println(sensorVal);
  Serial.print("Volt ");
  Serial.println(volt);
  Serial.print("Tmp ");
  Serial.println(temp);




  for (int i = 3; i < 6; i++) {
    
    if (temp > 20 + i) {
      digitalWrite(i, HIGH);

    } else {
      digitalWrite(i, LOW);
    }
  }
  delay(5);
}
