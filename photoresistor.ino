int lightVal = 0;
int lightPin = 0; //Light sensor pin
int ledPins = 9;

void setup(){
  for(int i =0;i<3;i++){
    pinMode(ledPins,OUTPUT);
  }
  Serial.begin(9600);
}

void loop(){
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  lightVal = map(lightVal, 6, 679, 0, 30);
  Serial.println(lightVal);
  lightVal /= 10;
  Serial.println(lightVal);
  for(int i =0;i<lightVal;i++){
    digitalWrite(ledPins,HIGH);
    delay(100);
     digitalWrite(ledPins,LOW);
    delay(1);
  }
}
