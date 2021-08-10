

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);



const byte numRows= 4; //baris pada keypad
const byte numCols= 4; //Kolom pada keypad

/*keymap mendefinisikan tombol ditekan sesuai
dengan baris dan kolom seperti muncul pada keypad*/
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};


byte rowPins[numRows]= {39,41,43,45}; 
byte colPins[numCols]= {47,49,51,53}; 


Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

float data = 10.7;
float as = 10.0;
void setup()
{
lcd.init();                      // initialize the lcd 
lcd.init();
lcd.backlight();
Serial.begin(9600);
lcd.clear();
}


void loop()
{
  lcd.setCursor(0,2);
  lcd.print("Tekan KEYPAD");
  char key = myKeypad.getKey();
//  if (key!=NO_KEY){
//      lcd.clear();
//     lcd.setCursor(0,0);
//     lcd.print(key);
//     delay(1000);
//   }else{
//    lcd.setCursor(0,0);
//    lcd.print("tidak ada key");
//   }
   
  
  if (key != NO_KEY && (key=='1')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }else if (key != NO_KEY && (key=='2')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='3')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='4')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='5')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='6')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='7')){
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='8')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='9')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='0')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key != NO_KEY && (key=='A')){
    lcd.setCursor(0,0);
    lcd.print(key);
  }
  else if (key != NO_KEY && (key=='B')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  
  else if (key != NO_KEY && (key=='C')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  
  else if (key != NO_KEY && (key=='D')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  
  else if (key != NO_KEY && (key=='*')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  
  else if (key != NO_KEY && (key=='#')){
    
    lcd.setCursor(0,0);
    lcd.print(key);
    
  }
  else if (key = NO_KEY){
    
    lcd.setCursor(0,0);
    lcd.print("tidak ada input");
    
  }else{
    lcd.setCursor(0,1);
  lcd.print("tidak ada key");
    }
  
}
