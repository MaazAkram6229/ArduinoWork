int phase[7]={0,6,4,5,2,1,3} ;
int t=9000;
int temp=0;
int initial_delay=0;
int phaseCount=0;
int phaseCoun=0;
int ali=0;


void setup(){
pinMode (5, INPUT); 
pinMode (6, INPUT);  
pinMode (7, INPUT);  
pinMode (8, OUTPUT); // phase 1 high
pinMode (9, OUTPUT);  //phase 2 high
pinMode (10, OUTPUT);  //phase 3 high
pinMode (11, OUTPUT);   //phase 1 LOW
pinMode (12, OUTPUT);     //phase 1 LOW
pinMode (13, OUTPUT);    //phase 2 LOW
pinMode (A0, INPUT);    //phase 3 LOW
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

//phaseCount = phaseCount +1;
/*if (phaseCount == 6)
{
  phaseCount = 0; 
}*/

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
 if(ali=0)
   {
   BLDC_move ();
   ali++;
   }
  
 
   
    */
    
     delayMicroseconds(t);
     
}

void BLDC_move ()
{
  phaseCoun=digitalRead(5)+digitalRead(6)*2+digitalRead(7)*4;
  
  Serial.println(phaseCoun);
  switch(phase[phaseCount]){
     
case 6:
PORTB = 0b00011001;
break;
case 1:
PORTB = 0b00101001;
break;
case 2:
PORTB = 0b00101100;
break;
case 3:
PORTB = 0b00110100;
break;
case 4:
PORTB = 0b00110010;
break;
case 5:
PORTB = 0b00011010;
break;

default:
PORTB = 0;
break;
}

}
