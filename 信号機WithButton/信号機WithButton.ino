int ledPins[3] = {13,11,9};
int ledBlinkTimes[3] = {1000,800,4000};

void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<3; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(2,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  Serial.write("normal mode\n");
  for(int l=0; l<3; l++){
    digitalWrite(ledPins[l], 0==l);
  }
  while(digitalRead(2)){
    delay(100);
  }
  Serial.write("Button pushed!\n");
  // put your main code here, to run repeatedly:
  for(int i=0; i<3; i++){
    for(int l=0; l<3; l++){
      digitalWrite(ledPins[l], i==l);
    }
    delay(ledBlinkTimes[i]);
  }
}
