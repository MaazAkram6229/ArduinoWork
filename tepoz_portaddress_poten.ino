int t=10000;
int temp=0;
int initial_delay=0;
int phaseCount=0;
void setup(){
pinMode (22, OUTPUT); // phase 1 high
pinMode (23, OUTPUT);  //phase 2 high
pinMode (24, OUTPUT);  //phase 3 high
pinMode (25, OUTPUT);   //phase 1 LOW
pinMode (26, OUTPUT);     //phase 1 LOW
pinMode (27, OUTPUT);    //phase 2 LOW


/*
pinMode (8, OUTPUT); // phase 1 high
pinMode (9, OUTPUT);  //phase 2 high
pinMode (10, OUTPUT);  //phase 3 high
pinMode (11, OUTPUT);   //phase 1 LOW
pinMode (12, OUTPUT);     //phase 1 LOW
pinMode (13, OUTPUT);    //phase 2 LOW
*/
pinMode (A7, INPUT);    //phase 3 LOW
Serial.begin(9600);
}
// 3phase, 100 Hz, rising or falling edge every 1664uS ( multiple of 4uS).
void loop(){
delayMicroseconds(t);
Serial.println(t);
phaseCount = phaseCount +1;
if (phaseCount == 7)
{
  phaseCount = 1; 
}
switch(phaseCount){
case 6:
PORTA = 0b00011001;
break;
case 1:
PORTA = 0b00101001;
break;
case 2:
PORTA = 0b00101100;
break;
case 3:
PORTA = 0b00110100;
break;
case 4:
PORTA = 0b00110010;
break;
case 5:
PORTA = 0b00011010;
break;

default:
PORTA = 0;
break;
}
  /*
  temp = analogRead(A7);
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
  if(t>1500)
  {
    t=t-10;
  }
  Serial.println(t);
  



}
