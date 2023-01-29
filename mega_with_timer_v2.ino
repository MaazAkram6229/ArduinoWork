bool A_STATE = true;
int phase[7]={0,6,4,5,2,1,3} ;
int t=9000;
int phaseCount=0;
const int sen1=18;
const int sen2=19;
const int sen3=20;
const int H1=22;
const int L1=23;
const int H2=24;
const int L2=25;
const int H3=26;
const int L3=27;
const int pot=A0;
int pwm=127;
int temp=0;
int up=0;
int lo=0;
int flag=0;


void setup() {



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
  
  cli();                      //stop interrupts for till we make the settings 
 
  //compare match register = [ 16,000,000Hz/ (prescaler * desired interrupt frequency) ] - 1

  
  //set timer2 interrupt at 8kHz
  TCCR2A = 0;// set entire TCCR2A register to 0
  TCCR2B = 0;// same for TCCR2B
  TCNT2  = 0;//initialize counter value to 0
  // set compare match register for 8khz increments
  OCR2A = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  OCR2B = 249;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
    // Set CS21 bit for 8 prescaler
   // TCCR2B |= (1 << CS21);       // for 8
   TCCR2B |=(1 << CS01) | (1 << CS00);     // for 64        
   
  // enable timer compare interrupt for com A and B
  TIMSK2 |= (1 << OCIE2A)   ;   //|(1 << OCIE2B)
      
  sei();      

  attachInterrupt(digitalPinToInterrupt(sen1), BLDC_move, CHANGE);
  attachInterrupt(digitalPinToInterrupt(sen2), BLDC_move, CHANGE);
  attachInterrupt(digitalPinToInterrupt(sen3), BLDC_move, CHANGE);
}

void loop() {
  //Serial.println(up);
  //Serial.println(lo);
  
  //Serial.println(phase[phaseCount]);
  //Serial.println("Nxt");
  
  
}



ISR(TIMER2_COMPA_vect){
    if (flag==0)
  {
  digitalWrite(9,HIGH);
  digitalWrite(up,HIGH);
  digitalWrite(lo,LOW);
  flag=1;
  }
  /*
  else
  {
  digitalWrite(9,LOW);
  digitalWrite(up,LOW);
  digitalWrite(lo,HIGH);
  flag=0;
  }
  */

  



  
  A_STATE = !A_STATE;       //Invert LED state
  //digitalWrite(up,A_STATE);
  
  digitalWrite(8,A_STATE);  //Write new state to the LED on pin D5
 
  
}


void BLDC_move ()
{
  Serial.println(lo);
  
  phaseCount=digitalRead(sen1)+digitalRead(sen2)*2+digitalRead(sen3)*4;

  switch(phase[phaseCount]){   
      
case 6:
  digitalWrite(H1, HIGH);      // on 
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);      //on 
  up=H1;
  lo=L3;
  
  
break;
case 1:
  digitalWrite(H1, HIGH);     //on
  digitalWrite(H2, LOW);
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);      //on 
  digitalWrite(L3, HIGH);    
  up=H1;
  lo=L2;
break;
case 2:
  
  
  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);    //on 
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);     //on 
  digitalWrite(L3, HIGH);
  up=H3;
  lo=L2;
break;
case 3:

  digitalWrite(H1, LOW);
  digitalWrite(H2, LOW);
  digitalWrite(H3, HIGH);     //on 
  digitalWrite(L1, LOW);      //on
  digitalWrite(L2, HIGH);   
  digitalWrite(L3, HIGH);
  up=H3;
  lo=L1;
break;
case 4:
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);    //on 
  digitalWrite(H3, LOW);
  digitalWrite(L1, LOW);     //on
  digitalWrite(L2, HIGH);
  digitalWrite(L3, HIGH);
  up=H2;
  lo=L1;
break;
case 5:
  digitalWrite(H1, LOW);
  digitalWrite(H2, HIGH);     //on 
  digitalWrite(H3, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, HIGH);
  digitalWrite(L3, LOW);      //on
  up=H2;
  lo=L3; 
break;

}

}
