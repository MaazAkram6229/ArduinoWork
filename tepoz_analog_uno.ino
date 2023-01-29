int phase[7]={0,6,4,5,2,1,3} ;
int t=9000;
int phaseCount=0;
const int sen1=5;
const int sen2=6;
const int sen3=7;
const int H1=9;
const int H2=10;
const int H3=11;
const int L1=A3;
const int L2=A4;
const int L3=A5;
const int pot=A0;
int pwm=123;
int temp=0;

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
phaseCount = (PIND >> 5) & 7;  // Read hall effect sensors status (PIND: read from PORTD which is arduino pins 0..7)
BLDC_move ();    

Serial.begin(9600);

PCICR |= B00000100;
PCMSK2 |= B11100000;

}
// 3phase, 100 Hz, rising or falling edge every 1664uS ( multiple of 4uS).

ISR (PCINT2_vect){
  phaseCount = (PIND>>5) & 7;    // Read hall effect sensors status (PIND: read from PORTD which is arduino pins 0..7)
  BLDC_move ();                               // Move the BLDC motor
}

void loop(){
      
}

void BLDC_move ()
{
  
  
  switch(phase[phaseCount]){
  

     
case 6:
  analogWrite(H1, pwm);
  analogWrite(L3, pwm);
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  
break;
case 1:
  analogWrite(H1, pwm);
  analogWrite(L2, pwm);
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L3, HIGH);
break;
case 2:
  analogWrite(H3, pwm);
  analogWrite(L2, pwm);
  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L3, HIGH);
break;
case 3:
  analogWrite(H3, pwm);
  analogWrite(L1, pwm);
  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
break;
case 4:
  analogWrite(H2, pwm);
  analogWrite(L1, pwm);
  digitalWrite(H1, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
break;
case 5:
  analogWrite(H2, pwm);
  analogWrite(L3, pwm);
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);
break;

default:
PORTB = 0;
break;
}

}
