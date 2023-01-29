int t=5000;
int temp=0;
int initial_delay=0;
int phaseCount=0;
int phaseCoun=0;
void setup(){

pinMode (22, OUTPUT); // phase 1 high
pinMode (23, OUTPUT);  //phase 2 high
pinMode (24, OUTPUT);  //phase 3 high
pinMode (25, OUTPUT);   //phase 1 LOW
pinMode (26, OUTPUT);     //phase 1 LOW
pinMode (27, OUTPUT);    //phase 2 LOW
pinMode (A0, INPUT);    //phase 3 LOW
Serial.begin(9600);
}
// 3phase, 100 Hz, rising or falling edge every 1664uS ( multiple of 4uS).
void loop(){
  
  phaseCoun = (PIND>>1) & 7;   
  Serial.println(phaseCoun);
delayMicroseconds(t);
phaseCount = phaseCount +1;
if (phaseCount == 7)
{
  phaseCount = 1; 
}
switch(phaseCount){

case 1:
PORTA = 0b00001001;
break;
case 2:
PORTA = 0b00011011;
break;
case 3:
PORTA = 0b00010010;
break;
case 4:
PORTA = 0b00110110;
break;
case 5:
PORTA = 0b00100100;
break;
case 6:
PORTA = 0b00101101;
break;
default:
PORTB = 0;
break;
}
  /*
  temp = analogRead(A0);
  initial_delay = map(temp,0,1024,330,10000);
  if (initial_delay - t > 10 )
  {
    t+=10;
  }
  else if (initial_delay - t < 0 )
  {
    t-=10;
  }
  else
  {
    t= initial_delay;
  }
  */
  if (t>500)
  {
    t=t-2;
  }
  
   Serial.println(t);


}
