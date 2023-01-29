   #include <LiquidCrystal.h>
   #include <EEPROM.h>
   const int rs = 13 ,en =8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
   LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
   float count=0;
   int state=0;
void setup() {
  
  pinMode(A0,INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Meters");
  
}

void loop() {


   
  while(count < 450)
  {
  state=0;
  Serial.println(analogRead(A0));
  while (analogRead(A0) >= 1000)
  {
    if (state==0){   
      
    count+=0.093;
    lcd.setCursor(0, 1);
    lcd.print(count);
    delay(10);
    }
    state=1;
    
  }
  }

  if (count >= 450)
  {
      lcd.setCursor(0, 1);
      lcd.print("450m completed");
      
  }

  
}
