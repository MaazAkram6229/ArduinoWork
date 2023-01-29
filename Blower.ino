void setup() {
  // put your setup code here, to run once:
  pinMode(A0,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(A0,140);
  

}
