  
  int analogLight = A0; 
  int led1 = 9; 
  int led2 = 10; 
  int led3 = 11; 

void setup() {
  // put your setup code here, to run once:'


  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly

  float lightValue = analogRead(analogLight);
  lightValue = lightValue/4.0;
  analogWrite(led1, lightValue);
  analogWrite(led2, lightValue);
  analogWrite(led3, int((lightValue * 2)) % 130);
  Serial.println(lightValue);


}
