const int output_1 = 5;
const int output_2 = 7;
const int output_3 =9;
const int output_1L =6;
const int output_2L = 8;
const int output_3L = 10;



 int t = 10000;  
void setup()
{
  pinMode(output_1, OUTPUT); // Phase 1   \Q1
  pinMode(output_2, OUTPUT); // Phase 2    \Q3
  pinMode(output_3, OUTPUT); // Phase 3    \Q5
  pinMode(output_1L, OUTPUT); // Phase 1 low  \Q4
  pinMode(output_2L, OUTPUT); // Phase 2 low  \Q6
  pinMode(output_3L, OUTPUT); // Phase 3 low   \Q2
 
}
void loop()
{
  
  digitalWrite(output_1, HIGH);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, LOW);
  
 
  delayMicroseconds(t);
  
  digitalWrite(output_1, HIGH);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, LOW);
  digitalWrite(output_3L, HIGH);
  
  delayMicroseconds(t);
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, HIGH);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, LOW);
  digitalWrite(output_3L, HIGH);

  //next half
  
  delayMicroseconds(t);
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, LOW);
  digitalWrite(output_3, HIGH);
  digitalWrite(output_1L, LOW);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, HIGH);
  
  
  delayMicroseconds(t);
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, HIGH);
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, LOW);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, HIGH);
 
  delayMicroseconds(t);
  
  digitalWrite(output_1, LOW);
  digitalWrite(output_2, HIGH);  
  digitalWrite(output_3, LOW);
  digitalWrite(output_1L, HIGH);
  digitalWrite(output_2L, HIGH);
  digitalWrite(output_3L, LOW);
  delayMicroseconds(t);

  
}
// --------- <Electronics-project-hub>com -------- //
