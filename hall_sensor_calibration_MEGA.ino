int t=10000;
int temp=200;
int initial_delay=0;
int phaseCount=0;
int phaseCoun=0;
const int H1=22;
const int H2=23;
const int H3=24;
const int L1=25;
const int L2=26;
const int L3=27;
const int sen1=18;
const int sen2=19;
const int sen3=20;


void setup(){

pinMode (H1, OUTPUT); // phase 1 high
 pinMode (H2, OUTPUT);  //phase 2 high
  pinMode (H3, OUTPUT);  //phase 3 high
  pinMode (L1, OUTPUT);   //phase 1 LOW
  pinMode (L2, OUTPUT);     //phase 1 LOW
  pinMode (L3, OUTPUT);    //phase 2 LOW
pinMode (A0, INPUT);    //phase 3 LOW
pinMode (sen1, INPUT); 
pinMode (sen2, INPUT);  
pinMode (sen3, INPUT);  
Serial.begin(9600);

attachInterrupt(digitalPinToInterrupt(sen1), BLDC_move, CHANGE);
attachInterrupt(digitalPinToInterrupt(sen2), BLDC_move, CHANGE);
attachInterrupt(digitalPinToInterrupt(sen3), BLDC_move, CHANGE);

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
      
case 6:
  digitalWrite(H1, HIGH);      // on 
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);      //on 
  
  
  
break;
case 1:
  digitalWrite(H1, HIGH);     //on
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);      //on 
  digitalWrite(L3, HIGH);    
  
break;
case 2:
  
  
  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);    //on 
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);     //on 
  digitalWrite(L3, HIGH);
  
break;
case 3:

  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);     //on 
  digitalWrite(L1, LOW);      //on
  digitalWrite(L2, HIGH);   
  digitalWrite(L3, HIGH);
  
break;
case 4:
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);    //on 
  digitalWrite(H3, LOW);
  digitalWrite(L1, LOW);     //on
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  
break;
case 5:
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);     //on 
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);      //on
   
break;

}

  
  



//Serial.print(digitalRead(20));
//Serial.print(digitalRead(19));
//Serial.println(digitalRead(18));
  
}

void BLDC_move()
{
   
   phaseCoun = (PIND>>1) & 7;   
   //Serial.println(phaseCoun);
 
 
  

Serial.print(digitalRead(18));
Serial.print(digitalRead(19));
Serial.println(digitalRead(20));
  
 

}
