const int pwm1 = PA1 ;
const int pwm2 = PA2 ; //initializing pin 2 as ‘pwm’ variable
void setup()
{
    pinMode(PD13,OUTPUT) ;     //Set pin 2 as output
    pinMode(pwm2,OUTPUT) ;
}
void loop()
{
    analogWrite(PD13,1000);
    
   
    //setting pwm to 25 
               //delay of 50 ms
    
}
