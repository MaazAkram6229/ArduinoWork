bool A_STATE = true;
bool B_STATE = true;

void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
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
  TIMSK2 |= (1 << OCIE2A) | (1 << OCIE2B) ; 
      
  sei();              
}

void loop() {
  
  
}



ISR(TIMER2_COMPA_vect){
  A_STATE = !A_STATE;       //Invert LED state
  digitalWrite(8,A_STATE);  //Write new state to the LED on pin D5
  
}

ISR(TIMER2_COMPB_vect){
  B_STATE = !B_STATE;       //Invert LED state
  digitalWrite(9,B_STATE);  //Write new state to the LED on pin D5
}
