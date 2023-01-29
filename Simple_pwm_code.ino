int maaz=A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(7,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

   digitalWrite(7,HIGH);
   delay(10);
   digitalWrite(7,LOW );
   delay(10);
   Serial.println(maaz);
   
}
