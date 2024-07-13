int controlPin = 2;
int controlPin2 = 3;
int enablePin = 9;
int directionSwitchPin = 4;
int onOffSwitchStateSwitchPin = 5;
int potPin = A0;

int onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  pinMode(directionSwitchPin, INPUT);
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  pinMode(controlPin, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(onOffSwitchStateSwitchPin, OUTPUT);

  digitalWrite(enablePin, LOW);
  Serial.begin(9600);
}

void loop() {

  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin) / 4;
 

  if (onOffSwitchState != previousOnOffSwitchState) {
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
      Serial.println("motorEnabled");
      Serial.println(motorEnabled);
    }
  }

  if (directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
      Serial.println("motorDirection");
      Serial.println(motorDirection);
    }
  }

  if (motorDirection == 1) {
    digitalWrite(controlPin, HIGH);
    digitalWrite(controlPin2, LOW);
  } else {
    digitalWrite(controlPin, LOW);
    digitalWrite(controlPin2, HIGH);
  }

  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);

  } else {
    analogWrite(enablePin, 0);
  }

  previousDirectionSwitchState = directionSwitchState;
  previousOnOffSwitchState = onOffSwitchState;
}
