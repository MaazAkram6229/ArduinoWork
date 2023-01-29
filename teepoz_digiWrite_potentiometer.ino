const int output_1 = 5;
const int output_2 =7;
const int output_3 = 9;
const int output_1L = 6;
const int output_2L = 8;
const int output_3L = 10;
const int pot =A0;
int temp=0;
int initial_delay=10;
int dif=10;
const int sen1=18;
const int sen2=19;
const int sen3=20;
int phaseCoun=0;


 int t = 6000;  
void setup()
{
  pinMode(output_1, OUTPUT); // Phase 1   \Q1
  pinMode(output_2, OUTPUT); // Phase 2    \Q3
  pinMode(output_3, OUTPUT); // Phase 3    \Q5
  pinMode(output_1L, OUTPUT); // Phase 1 low  \Q4
  pinMode(output_2L, OUTPUT); // Phase 2 low  \Q6
  pinMode(output_3L, OUTPUT); // Phase 3 low   \Q2
  pinMode(pot,INPUT);
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(sen1), BLDC_move, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(sen2), BLDC_move, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(sen3), BLDC_move, CHANGE);
 
}

void loop()

{
 
  
 
  
  digitalWrite(output_1, HIGH);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, LOW);
  digitalWrite(output_3L, HIGH);
  
  
  delayMicroseconds(t);
 // Serial.println(digitalRead(sen1));
  
  digitalWrite(output_1, HIGH);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, LOW);
  
  delayMicroseconds(t);
  //Serial.println(digitalRead(sen1));
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, HIGH);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, LOW);

  //next half
  
  delayMicroseconds(t);
  //Serial.println(digitalRead(sen1));
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, HIGH);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, LOW);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, HIGH);
  
  
  delayMicroseconds(t);
  //Serial.println(digitalRead(sen1));
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, HIGH);
  digitalWrite(output_1L, LOW);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, HIGH);
 
  delayMicroseconds(t);
  //Serial.println(digitalRead(sen1));
  
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, HIGH);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, LOW);
  digitalWrite(output_3L, HIGH);
  delayMicroseconds(t);
 // Serial.println(digitalRead(sen1));
  
 
   
  temp = analogRead(pot);
  initial_delay=map(temp,0,1024,300,20000);
  if (initial_delay - t > dif )
  {
    t+=dif;
  }
  else if (initial_delay - t < 0 )
  {
    t-=dif;
  }
  else
  {
    t= initial_delay;
  }
  Serial.println(A0);
}


/*
void BLDC_move()
{
   //phaseCoun = (PIND>>1) & 7;   
   //Serial.println(phaseCoun);
 
 
  

//Serial.print(digitalRead(20));
//Serial.print(digitalRead(19));
Serial.println(digitalRead(18));
  
  

}
*/
// --------- <Electronics-project-hub>com -------- //
