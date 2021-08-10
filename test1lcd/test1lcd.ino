//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x23,20,4);

void setup()
{
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(7,1);
  lcd.print("GOTIK");
  lcd.setCursor(1,2);
  lcd.print("- Go..GO..GO -");
}


void loop()
{
}
