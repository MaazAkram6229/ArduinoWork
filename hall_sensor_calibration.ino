int t=6000;
int temp=0;
int initial_delay=0;
int phaseCount=0;
int phaseCoun=0;
void setup(){

pinMode (8, OUTPUT); // phase 1 high
pinMode (9, OUTPUT);  //phase 2 high
pinMode (10, OUTPUT);  //phase 3 high
pinMode (11, OUTPUT);   //phase 1 LOW
pinMode (12, OUTPUT);     //phase 1 LOW
pinMode (13, OUTPUT);    //phase 2 LOW
pinMode (A0, INPUT);    //phase 3 LOW
Serial.begin(9600);

PCICR |= B00000100;
PCMSK2 |= B11100000;
}

ISR (PCINT2_vect){
  phaseCoun = (PIND>>5) & 7;    // Read hall effect sensors status (PIND: read from PORTD which is arduino pins 0..7)
  BLDC_move ();                               // Move the BLDC motor
}
// 3phase, 100 Hz, rising or falling edge every 1664uS ( multiple of 4uS).
void loop(){
  
  
 
delayMicroseconds(t);
phaseCount = phaseCount +1;
if (phaseCount == 7)
{
  phaseCount = 1; 
}

switch(phaseCount){

case 1:
PORTB = 0b00001001;
break;
case 2:
PORTB = 0b00011011;
break;
case 3:
PORTB = 0b00010010;
break;
case 4:
PORTB = 0b00110110;
break;
case 5:
PORTB = 0b00100100;
break;
case 6:
PORTB = 0b00101101;
break;
default:
PORTB = 0;
break;
}
  
  



}
void BLDC_move ()
{
  
  Serial.println(phaseCoun);
  

}
