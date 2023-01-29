/* int output_1 = 8;
const int output_2 = 9;
const int output_3 = 10;
const int output_1L = 11;
const int output_2L = 12;
const int output_3L = 13;
*/

const int output_1 = 22;
const int output_2 = 23;
const int output_3 = 24;
const int output_1L = 25;
const int output_2L = 26;
const int output_3L = 27;


 int mic=0;
 int temp=0;
 int initial_delay=0;
 int pot= A0;
 int t = 10000;  
void setup()
{
  pinMode(output_1, OUTPUT); // Phase 1
  pinMode(output_2, OUTPUT); // Phase 2
  pinMode(output_3, OUTPUT); // Phase 3
  pinMode(output_1L, OUTPUT); // Phase 1 low
  pinMode(output_2L, OUTPUT); // Phase 2 low
  pinMode(output_3L, OUTPUT); // Phase 3 low 
  pinMode(pot,INPUT);
  Serial.begin(9600);
 
}
void loop()
{
  
  digitalWrite(output_1, HIGH);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, HIGH);
  
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, LOW);
  digitalWrite(output_3L, HIGH);
  
 
  delayMicroseconds(t);
  
  digitalWrite(output_1, HIGH);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, LOW);
  digitalWrite(output_3L, LOW);
  
  delayMicroseconds(t);
  digitalWrite(output_1, HIGH);
  digitalWrite(output_2, HIGH);
  digitalWrite(output_3, LOW);
  
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, LOW);

  //next half
  
  delayMicroseconds(t);
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, HIGH);
  digitalWrite(output_3, LOW);
  
  digitalWrite(output_1L, LOW);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, LOW);
  
  
  delayMicroseconds(t);
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, HIGH);
  digitalWrite(output_3, HIGH);
 
  digitalWrite(output_1L, LOW);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, HIGH);
 
  delayMicroseconds(t);
  
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, HIGH);
  
  digitalWrite(output_1L, LOW);
  digitalWrite(output_2L, LOW);
  digitalWrite(output_3L, HIGH);
  delayMicroseconds(t);
  /*
  temp = analogRead(pot);
  initial_delay=map(temp,0,1024,330,10000);
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
  Serial.println(t);
  */
}
// --------- <Electronics-project-hub>com -------- //
