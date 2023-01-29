void setup ()
{
  TCCR1A = (TCCR1A & 0x0F) | 0xB0 ; // set pin 10 inverted
  int val = 100 ;
  int dead = 2 ;
  analogWrite (9, val) ;
  analogWrite (10, val+dead) ;
}
void loop ()
{}
