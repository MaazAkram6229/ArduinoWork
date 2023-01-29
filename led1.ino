#include <Keypad.h>
#include <LiquidCrystal.h>

char keys[4][4] = {
  {'1','2','3','A'},
  {'4','5','6','B' },
  {'7','8','9','C'},
  {'.','0','#','D'}
};
byte colPins[4] = {8, 9, A4, A5}; //connect to the row pinouts of the keypad
byte rowPins[4] = {10, 11, 12, 13}; //connect to the column pinouts of the keypad

LiquidCrystal lcd(7, 6, 5, 4, 3, A3);

const byte interruptPin = 2;
long int metters=0;
static unsigned long last_interrupt_time = 0;


void setup() {
 Serial.begin(9600);
 lcd.begin(16, 2);
 
 lcd.setCursor(5, 0);
 lcd.print("P");
 delay(500);
  lcd.print("E");
 delay(500);
  lcd.print("N");
 delay(500);
  lcd.print("C");
 delay(500);
  lcd.print("O");
 delay(500);
 lcd.setCursor(0, 1);
 lcd.print("Enter Val or OK");
 pinMode(A0,INPUT);

 pinMode(interruptPin, LOW);
 attachInterrupt(digitalPinToInterrupt(interruptPin), blink, HIGH);
}

int count=0;
int var=0;
int met[8]={0,0,0,0,0,0,0,0};
double value=0;
int point=0;

void loop() {
   
   char key = keypad.getKey();
    
    if (key){
    
    if(key!='A' && key!='B' && key!='C'  && key!='#' )
    {
       if(count==0){
      lcd.clear();
      lcd.print("Meters");
    }
     
    lcd.setCursor(var,1 );
    lcd.print(key);
    met[var]= key-48;
    if (met[var]==-2)
    {
         point=var; 
    }
    Serial.println(key);
    Serial.println(count);
    Serial.println(var);
    Serial.println(met[var]);
     count++;
     var++;
    }
   if(key== 'A' )
   {

          if(count==0){
            lcd.clear();
            performance(0,value);
          
           }
      
            
           if(count!=0){
              
               lcd.clear();
               value=vaal(met,var,point);
               lcd.print(value);
               performance(1,value);
            
            
            }
     
     


  }
    }
}



double vaal (int *matrix ,int vari ,int deci )
{
  
   double ans=0;
    double ans1=0;
   double mm=1;
  if (deci==0)
  {
      for(int i=var-1 ;i>=0 ;i--)
      {
        ans= ans+(matrix[i]*mm);
        mm=mm*10;
      }
  }
  if (deci!=0)
  {
    for(int i=var-1 ;i>deci ;i--)
      {
        ans1= ans1+(matrix[i]*mm);
        mm=mm*10;
       
      }
      int a= var-deci-1;
      int b=1;
      for(int j=0 ;j<a ;j++)
      {
         b= b*10;
      }
      ans1=(ans1/(b));
      mm=1;
      for(int k=(deci-1) ;k>=0 ;k--)
      {
        ans= ans+(matrix[k]*mm);
        mm=mm*10;
      }
      ans=ans+ans1;
  }
  return ans;
}



void performance(int mod , double variable )
{
  lcd.clear();
  
  
   if (mod=0)
   {
    lcd.print("meters done:");
    
      
       lcd.setCursor(0,1 );
        lcd.print(metters);
         Serial.println("in loop");
        
   }
   if(mod=1)
   {
     lcd.print("Race to ");
      lcd.print(variable);
    
    while(metters<=variable)
    {
     
       
       lcd.setCursor(0,1 );
        lcd.print(metters);
        Serial.println("in loop");
        Serial.println(metters);
        
    }
  
   }
  
}

void blink() {
  
  
  
   
     metters++;
     
 
  
}
  
