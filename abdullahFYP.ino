

#include <OneWire.h>
#include <DallasTemperature.h>
#include <DFRobot_DHT11.h>
#include <dht.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <LoRa.h>


dht DHT;
const int SENSOR_PIN = A0; // Arduino pin connected to DS18B20 sensor's DQ pin
int counter=0;
OneWire oneWire(SENSOR_PIN);         // setup a oneWire instance
DallasTemperature tempSensor(&oneWire); // pass oneWire to DallasTemperature library
const byte ph[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
const byte nitro[] = {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};

float tempCelsius;    
float tempFahrenheit; 
byte values[11];
const int sensor_pin = A1;                                        // A1 of SOIL MOISTURE SENSOR 

#define DHT11_PIN A3                                              //  DHT11 PIN                                            
#define RE 6                                                     // RE of PH 
#define DE 5                                                      // DE of PH 
SoftwareSerial mod(7,4);                                         // RO and DI of PH 

#define RE2 2                                                     // RE of NPK
#define DE2 A5                                                     // DE of NPK
SoftwareSerial mod2(3,A4);                                          // RO and DI of NPK

void setup() {
  // put your setup code here, to run once:
  tempSensor.begin();  
  Serial.begin(9600); 
  mod.begin(4800);
  //mod2.begin(4800);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);

  pinMode(RE2, OUTPUT);
  pinMode(DE2, OUTPUT);

  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

   


}

void loop() {
  
  byte val1,val2,val3;
  byte val;
  float moisture_percentage;
  int sensor_analog;

  
  
  
  
  tempSensor.requestTemperatures();             // send the command to get temperatures
  tempCelsius = tempSensor.getTempCByIndex(0);  // read temperature in Celsius
  tempFahrenheit = (tempCelsius * 9 / 5 + 32); // convert Celsius to Fahrenheit
  Serial.print("Temperature: ");
  Serial.print(tempCelsius);    // print the temperature in Celsius
  Serial.print("°C");
  Serial.print("  ~  ");        // separator between Celsius and Fahrenheit
  Serial.print(tempFahrenheit); // print the temperature in Fahrenheit
  Serial.println("°F");

  delay(500);

  int chk = DHT.read11(DHT11_PIN);                // dht OUTPUT
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(500);

  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n");
  delay(500);
  
 
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(100);
  if (mod.write(ph, sizeof(ph)) == 8)
  {
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 11; i++)
    {
      values[i] = mod.read();
      //Serial.print(values[i], HEX);
    }
    
  }
  float soil_ph = float(values[4]) / 10;
  
 
 
   Serial.print("Ph Value =");
   Serial.println(soil_ph, 1);
   delay(500);
 


  

  
  
  val1 = nitrogen();           // NPK Nitrogen Values 
  delay(10);
  val2 = phosphorous();         // NPK Phosphorous Value
  delay(10);
  val3 = potassium();           // NPK Potassium Value 
  delay(10);

  Serial.print("Nitrogen: ");
  Serial.print(val1);
  Serial.println(" mg/kg");
  Serial.print("Phosphorous: ");
  Serial.print(val2);
  Serial.println(" mg/kg");
  Serial.print("Potassium: ");
  Serial.print(val3);
  Serial.println(" mg/kg");
  delay(3000);

  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(tempCelsius);
  LoRa.endPacket();
  Serial.println("packet sent");
  

  

  
}

byte nitrogen(){
  digitalWrite(DE2,HIGH);
  digitalWrite(RE2,HIGH);
  delay(100);
  if(mod2.write(nitro,sizeof(nitro))==8){
    digitalWrite(DE2,LOW);
    digitalWrite(RE2,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod2.read(),HEX);
    values[i] = mod2.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}

byte phosphorous(){
  digitalWrite(DE2,HIGH);
  digitalWrite(RE2,HIGH);
  delay(100);
  if(mod2.write(phos,sizeof(phos))==8){
    digitalWrite(DE2,LOW);
    digitalWrite(RE2,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod2.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}
 
byte potassium(){
  digitalWrite(DE2,HIGH);
  digitalWrite(RE2,HIGH);
  delay(100);
  if(mod2.write(pota,sizeof(pota))==8){
    digitalWrite(DE2,LOW);
    digitalWrite(RE2,LOW);
    for(byte i=0;i<7;i++){
    //Serial.print(mod.read(),HEX);
    values[i] = mod2.read();
    Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];

  


  
  delay(5000);
}
