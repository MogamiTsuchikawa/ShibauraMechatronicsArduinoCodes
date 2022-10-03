void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int ans[4] = {9+7,9-7,9*7,9/7};
  char kigos[4] = {'+','-','*','/'};
  for(int i=0; i<4; i++){
    Serial.print(kigos[i]);
    Serial.println(ans[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
