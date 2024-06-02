#include <Arduino.h>
#include "HX711.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
HX711 scale;

void setup() {
  Serial.begin(57600);
  lcd.init();                    
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Dang Khoi Tao:");
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN); 
  scale.set_scale(-407.83);
  scale.tare();  
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Khoi Luong:");

  int khoiluong = (scale.get_units());
  if(khoiluong>0){
    if(khoiluong>1000){
      lcd.setCursor(3,1);
      lcd.print(khoiluong/1000.00);
      lcd.setCursor(8,1);
      lcd.print("kilogram");
    }
    else{
      lcd.setCursor(3,1);
      lcd.print(khoiluong);
      lcd.setCursor(6,1);
      lcd.print("      gram");     
    }
  }
  else{
  lcd.setCursor(3,1);
  lcd.print("0        gram");
  }

}