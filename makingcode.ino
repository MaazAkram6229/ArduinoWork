
int tempphase[7]={0,4,6,2,3,1,5}; 
int ph=1;
int period=0;
bool A_STATE = true;
int phase[7]={0,6,4,5,2,1,3} ;   // sens val relation with phase  1,2,3,4,5,6   
int hold=0b00111000;
int phaseCount=1;
const int sen1=5;
const int sen2=6;
const int sen3=7;
const int H1=8;
const int L1=11;
const int H2=9;
const int L2=12;
const int H3=10;
const int L3=13;
const int pot=A0;
int temp=0;
int in=0;
int of=0;
float gg=0;

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
  pinMode(8,OUTPUT);
  Serial.begin(9600);


  cli();  

   





  
  sei();



  
}
// 3phase, 100 Hz, rising or falling edge every 1664uS ( multiple of 4uS).
void loop(){
delayMicroseconds(10000);
ph = ph +1;
if (ph == 7)
{
  ph = 1; 
}
  phaseCount=tempphase[ph];
  hold=phaseCount;
  BLDC_move();


}







void BLDC_move ()
{
  //phaseCount=digitalRead(sen1)+digitalRead(sen2)*2+digitalRead(sen3)*4;
  //phaseCount = (PIND>>1) & 7;                                     //18 , 19 , 20

    PORTB = 0b00111000;
    hold = 0b00111000;
    delayMicroseconds(10);
  switch(phase[phaseCount]){   
             
case 6:
  PORTB = 0b00011001;
  hold = 0b00011001;
break;
case 1: 
  PORTB = 0b00101001; 
  hold = 0b00101001; 
break;
case 2:
  PORTB = 0b00101100;
  hold =  0b00101100; 
  
break;
case 3:
  PORTB = 0b00110100;
  hold = 0b00110100;
break;
case 4:
  PORTB = 0b00110010;
  hold = 0b00110010;
break;

case 5:
  PORTB = 0b00011010;
  hold = 0b00011010;
break;

default:
  PORTB = 0b00111000;
  
break;

}

}
