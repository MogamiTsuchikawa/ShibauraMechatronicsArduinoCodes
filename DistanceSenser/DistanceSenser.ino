#define trigPin 12
#define echoPin 11
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}
void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2);        // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // Added this line
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 10000.0 * (331.5 + 0.607 * 20.0);
  if (distance >= 200 || distance <= 0) {
    Serial.println("Out of range");
  } else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  if (distance < 20) {
    digitalWrite(1, 1);
    digitalWrite(2, 0);
    digitalWrite(3, 0);
  } else if (distance < 40) {
    digitalWrite(1, 1);
    digitalWrite(2, 1);
    digitalWrite(3, 0);
  } else {
    digitalWrite(1, 1);
    digitalWrite(2, 1);
    digitalWrite(3, 1);
  }
  delay(100);
}