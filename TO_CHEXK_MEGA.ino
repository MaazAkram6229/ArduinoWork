int tempphase[7]={0,1,2,3,4,5,6}; 
bool A_STATE = true;
int phase[7]={0,6,4,5,2,1,3} ;   // sens val relation with phase  1,2,3,4,5,6   
int t=9000;
int hold=0b00111000;
int phaseCount=1;
const int sen1=18;
const int sen2=19;
const int sen3=20;
const int H1=22;
const int L1=25;
const int H2=23;
const int L2=26;
const int H3=24;
const int L3=27;
const int pot=A0;
int ph=1; 
int pwm=127;
int temp=0;
int period=0;
int in=0;
int of=0;
float gg=0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
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
  OCR2A = 200;// = (16*10^6) / (8000*8) - 1 (must be <256)
  OCR2B = 200;// = (16*10^6) / (8000*8) - 1 (must be <256)
  // turn on CTC mode
  TCCR2A |= (1 << WGM21);
    // Set CS21 bit for 8 prescaler
   // TCCR2B |= (1 << CS21);       // for 8
   TCCR2B |=(1 << CS01) | (1 << CS00);     // for 64        
  // enable timer compare interrupt for com A and B
  TIMSK2 |= (1 << OCIE2A)   ;   //|(1 << OCIE2B)
      
  sei();      
  period=OCR2A/100;
  //attachInterrupt(digitalPinToInterrupt(sen1), BLDC_move, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(sen2), BLDC_move, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(sen3), BLDC_move, CHANGE);
}

void loop() {
  Serial.println("loop");
  
  ph = ph + 1;
  if (ph == 7)
  { 
   ph = 1; 
  }
  phaseCount=tempphase[ph];
  hold=phaseCount;
  BLDC_move ();
  
  delayMicroseconds(10000);

  gg=(analogRead(A0)/10.23);
  in = 30;
  
  of=100-in;


  
}





ISR(TIMER2_COMPA_vect){
 /*
  
  A_STATE = !A_STATE;       //Invert LED state
  if (A_STATE){
      OCR2A = period*in;
      PORTA = hold;
      
      
  }
  else if (!A_STATE)
  {
      PORTA = 0b00111000;
      OCR2A = period*of; 
      
  }
  // digitalWrite(8,A_STATE);  //Write new state to the LED on pin D5
 */
  
}




void BLDC_move ()
{
  //phaseCount=digitalRead(sen1)+digitalRead(sen2)*2+digitalRead(sen3)*4;
  //phaseCount = (PIND>>1) & 7;                                     //18 , 19 , 20

    PORTA = 0b00111000;
    hold = 0b00111000;
    delayMicroseconds(10);
    Serial.println(phase[phaseCount]);
  switch(phase[phaseCount]){   
             
case 6:
  PORTA = 0b00011001;
  hold = 0b00011001;
break;
case 1: 
  PORTA = 0b00101001; 
  hold = 0b00101001; 
break;
case 2:
  PORTA = 0b00101100;
  hold =  0b00101100; 
  
break;
case 3:
  PORTA = 0b00110100;
  hold = 0b00110100;
break;
case 4:
  PORTA = 0b00110010;
  hold = 0b00110010;
break;

case 5:
  PORTA = 0b00011010;
  hold = 0b00011010;
break;

default:
  PORTB = 0b00111000;
  
break;

}

}
