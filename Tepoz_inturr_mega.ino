int phase[7]={0,6,4,5,2,1,3} ;
int t=9000;
int phaseCount=0;
const int sen1=20;
const int sen2=19;
const int sen3=18;
const int H1=22;
const int L1=25;
const int H2=23;
const int L2=26;
const int H3=24;
const int L3=27;
const int pot=A0;
int pwm=127;
int temp=0;
int hold=0b00111000;



void setup(){
pinMode (sen1, INPUT); 
pinMode (sen2, INPUT);  
pinMode (sen3, INPUT);  
pinMode (H1, OUTPUT); // phase 1 high
pinMode (H2, OUTPUT);  //phase 2 high
pinMode (H3, OUTPUT);  //phase 3 high
pinMode (L1, OUTPUT);   //phase 1 LOW
pinMode (L2, OUTPUT);     //phase 1 LOW
pinMode (L3, OUTPUT);    //phase 2 LOW
pinMode (pot, INPUT);    //phase 3 LOW
  // Read hall effect sensors status (PIND: read from PORTD which is arduino pins 0..7)   

Serial.begin(9600);

attachInterrupt(digitalPinToInterrupt(sen1), BLDC_move, CHANGE);
attachInterrupt(digitalPinToInterrupt(sen2), BLDC_move, CHANGE);
attachInterrupt(digitalPinToInterrupt(sen3), BLDC_move, CHANGE);

}
// 3phase, 100 Hz, rising or falling edge every 1664uS ( multiple of 4uS).



void loop(){
  
  
}

void BLDC_move ()
{
  
  phaseCount=digitalRead(sen1)+digitalRead(sen2)*2+digitalRead(sen3)*4;
  Serial.println(phaseCount);
  
  switch(phase[phaseCount]){
  
  

     
case 6:
  digitalWrite(H1, HIGH);
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);
  
break;
case 1:
  digitalWrite(H1, HIGH);
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, HIGH);
break;
case 2:
  
  
  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  digitalWrite(L3, HIGH);
break;
case 3:

  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
break;
case 4:
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);
  digitalWrite(H3, LOW);
  digitalWrite(L1, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
break;
case 5:
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);
break;

}

}
