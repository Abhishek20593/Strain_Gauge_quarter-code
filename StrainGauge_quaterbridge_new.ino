#include <EEPROM.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include<math.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
int value=0;          
float  volts=0.0;
char voltage_value[15];

void setup() 
{
  Serial.begin(9600);   
  lcd.begin(16,2);
  lcd.setBacklightPin(3,POSITIVE);
  lcd.setBacklight(HIGH);
  

}

void loop() 
{
  value=analogRead(A0);
  volts=(0.0095*value)-2.8072;
  dtostrf(volts,6,4,voltage_value);
  Serial.print("Voltage= "); 
  Serial.println(voltage_value);
  lcd.setCursor(0,0);
  lcd.print("VOLTAGE= ");
  lcd.setCursor(0,1);
  lcd.print(voltage_value);
  lcd.print(" V");
}
