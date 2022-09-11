const int echoPin = 13;
const int trigPin = 12;
const int ledPin =  7;
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;           // interval at which to blink (milliseconds)
long duration;
int distance;
int distancetwo;

void setup() {
pinMode(ledPin, OUTPUT);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
Serial.begin(9600);
}

void loop() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10000);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;

if (distance < distancetwo) {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
}
distancetwo = distance;
Serial.print("Distance: ");
Serial.println(distance);

}
