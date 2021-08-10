#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int temp_sensor = 6;
OneWire ourWire(temp_sensor);
DallasTemperature sensors(&ourWire);

#define buzzer 13
#define RELAY_ON 0 //relay off
#define RELAY_OFF 1 //relay off
#define RELAY_1  2   // pin yang digunakan yaitu pin 2
#define RELAY_2  3   // pin yang digunakan yaitu pin 3
#define RELAY_3  4   // pin yang digunakan yaitu pin 4
#define RELAY_4  5   // pin yang digunakan yaitu pin 5
//#define trigPin 9
//#define echoPin 10
long duration;
int distance, initialDistance, currentDistance, i;
int screenOffMsg =0;
String password="1234";
String tempPassword;
boolean activated = false; // State of the alarm
boolean isActivated;
boolean activateAlarm = false;
boolean alarmActivated = false;
boolean enteredPassword; // State of the entered password to stop the alarm
boolean passChangeMode = false;
boolean passChanged = false;
//untuk ph
const int analogInPin = A1; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;
float maxph = 7.9;
float minph = 7.6;
//untuk suhu

float temperature = 0;    //Variable to store the temperature in
int lowerLimit = 27;      //define the lower threshold for the temperature
int upperLimit = 32;      //define the upper threshold for the temperature
//untuk kekeruhan
float voltage1 = 0;
float keruh = 3.0;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//untuk keypad
char keypressed;
char keyMap[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {39, 41, 43, 45}; //Row pinouts of the keypad
byte colPins[COLS] = {47, 49, 51, 53}; //Column pinouts of the keypad
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS); 
 
void setup() { 
  //lcd.begin(16,2); 
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, RELAY_ON);
  pinMode(RELAY_2, OUTPUT);
  digitalWrite(RELAY_2, RELAY_ON);
  pinMode(RELAY_3, OUTPUT);
  digitalWrite(RELAY_3, RELAY_ON);
  pinMode(RELAY_4, OUTPUT);
  digitalWrite(RELAY_4, RELAY_ON);
  sensors.begin();
  //pinMode(buzzer, OUTPUT); // Set buzzer as an output
  //pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  //pinMode(echoPin, INPUT); // Sets the echoPin as an Input
}
void loop() {
  if (activateAlarm) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alarm will be");
    lcd.setCursor(0,1);
    lcd.print("activated in");
   
    int countdown = 9; // 9 seconds count down before activating the alarm
    while (countdown != 0) {
      lcd.setCursor(13,1);
      lcd.print(countdown);
      countdown--;
      tone(buzzer, 700, 100);
      delay(1000);
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Alarm Activated!");
    //initialDistance = getDistance();
    activateAlarm = false;
    alarmActivated = true;
  }
  if (alarmActivated == true){
      lcd.setCursor(0,0);
      lcd.print("Kualitas Air Tambak");
      lcd.setCursor(12,1);
      lcd.print("|");
      lcd.setCursor(12,2);
      lcd.print("|");
      lcd.setCursor(12,3);
      lcd.print("|");
      //cek kondisi suhu
      sensors.requestTemperatures(); 
      temperature = sensors.getTempCByIndex(0);
      Serial.print("Suhu = ");
      Serial.print(temperature);
      Serial.println(" °C");
      //cek kondisi kekeruhan
      int sensorValue = analogRead(A0);// read the input on analog pin 0:
      float voltage1 = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
      //cek kondisi ph
      for(int i=0;i<10;i++) { 
      buf[i]=analogRead(analogInPin);
      delay(10);
      }
      for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
          if(buf[i]>buf[j]){
             temp=buf[i];
             buf[i]=buf[j];
             buf[j]=temp;
             }
           }
        }
        avgValue=0;
        for(int i=2;i<8;i++)
        avgValue+=buf[i];
        float pHVol=(float)avgValue*5.0/1024/6;
        float pHValue = -5.70 * pHVol + 21.34 - 1.2;   
        //cetak di lcd 
        lcd.setCursor(0,1);
        lcd.print("s = ");
        lcd.print(temperature);
        lcd.setCursor(0,2);
        lcd.print("k = ");
        lcd.print(voltage1);
        lcd.setCursor(0,3);
        lcd.print("p = ");
        lcd.print(pHValue);
        //penentuan aksi suhu
        if(temperature < lowerLimit){
        digitalWrite(RELAY_1, RELAY_OFF);
        lcd.setCursor(10,1);
        lcd.print("TN");
        lcd.setCursor(14,1);
        lcd.print("P = ON");
        }else 
        if(temperature >= lowerLimit && temperature <= upperLimit){
        digitalWrite(RELAY_1, RELAY_ON);
        lcd.setCursor(10,1);
        lcd.print("N");
        lcd.setCursor(14,1);
        lcd.print("P = OF");
        }else 
        if(temperature > upperLimit){
        digitalWrite(RELAY_1, RELAY_OFF);
        lcd.setCursor(10,1);
        lcd.print("TN");
        lcd.setCursor(14,1);
        lcd.print("P = ON");
        }
       //penentuan aksi kekeruhan
       if(voltage1 < keruh){
       digitalWrite(RELAY_2, RELAY_OFF);
       lcd.setCursor(10,2);
       lcd.print("TN");
       lcd.setCursor(14,2);
       lcd.print("P = ON");
       }else {
       digitalWrite(RELAY_2, RELAY_ON);
       lcd.setCursor(10,2);
       lcd.print("N");
       lcd.setCursor(14,2);
       lcd.print("P = OF");
       }
      //penentuan aksi pH
      if(pHValue < minph){
      digitalWrite(RELAY_3, RELAY_OFF);
      lcd.setCursor(10,3);
      lcd.print("TN");
      lcd.setCursor(14,3);
      lcd.print("P = ON");
      }else 
      if(pHValue >= minph && pHValue <= maxph){
      digitalWrite(RELAY_3, RELAY_ON);
      lcd.setCursor(10,3);
      lcd.print("N");
      lcd.setCursor(14,3);
      lcd.print("P = OF");
      }else 
      if(temperature > maxph){
      digitalWrite(RELAY_3, RELAY_OFF);
      lcd.setCursor(10,3);
      lcd.print("TN");
      lcd.setCursor(14,3);
      lcd.print("P = ON");
      }
      }
   }
  if (!alarmActivated) {
    if (screenOffMsg == 0 ){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("mau ganti?");
      lcd.setCursor(0,1);
      lcd.print("A - tidak");
      lcd.setCursor(0,2);
      lcd.print("B - ganti");
      screenOffMsg = 1;
    }
    keypressed = myKeypad.getKey();
     if (keypressed =='A'){        //If A is pressed, activate the alarm
      tone(buzzer, 1000, 200);
      activateAlarm = true;            
    }
    else if (keypressed =='B') {
      lcd.clear();
      int i=1;
      tone(buzzer, 2000, 100);
      tempPassword = "";
      lcd.setCursor(0,0);
      lcd.print("Current Password");
      lcd.setCursor(0,1);
      lcd.print(">");
      passChangeMode = true;
      passChanged = true;   
      while(passChanged) {      
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
         tempPassword += keypressed;
         lcd.setCursor(i,1);
         lcd.print("*");
         i++;
         tone(buzzer, 2000, 100);
        }
      }
      if (i > 5 || keypressed == '#') {
        tempPassword = "";
        i=1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Current Password");
        lcd.setCursor(0,1);
        lcd.print(">"); 
      }
      if ( keypressed == '*') {
        i=1;
        tone(buzzer, 2000, 100);
        if (password == tempPassword) {
          tempPassword="";
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Set New Password");
          lcd.setCursor(0,1);
          lcd.print(">");
          while(passChangeMode) {
            keypressed = myKeypad.getKey();
            if (keypressed != NO_KEY){
              if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
                  keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
                  keypressed == '8' || keypressed == '9' ) {
                tempPassword += keypressed;
                lcd.setCursor(i,1);
                lcd.print("*");
                i++;
                tone(buzzer, 2000, 100);
              }
            }
            if (i > 5 || keypressed == '#') {
              tempPassword = "";
              i=1;
              tone(buzzer, 2000, 100);
              lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("Set New Password");
              lcd.setCursor(0,1);
              lcd.print(">");
            }
            if ( keypressed == '*') {
              i=1;
              tone(buzzer, 2000, 100);
              password = tempPassword;
              passChangeMode = false;
              passChanged = false;
              screenOffMsg = 0;
            }            
          }
        }
      }
    }
   }
 }
}
void enterPassword() {
  int k=5;
  tempPassword = "";
  activated = true;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" *** ALARM *** ");
  lcd.setCursor(0,1);
  lcd.print("Pass>");
      while(activated) {
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
          tempPassword += keypressed;
          lcd.setCursor(k,1);
          lcd.print("*");
          k++;
        }
      }
      if (k > 9 || keypressed == '#') {
        tempPassword = "";
        k=5;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(" *** ALARM *** ");
        lcd.setCursor(0,1);
        lcd.print("Pass>");
      }
      if ( keypressed == '*') {
          activated = false;
          alarmActivated = false;
          noTone(buzzer);
          screenOffMsg = 0;  
      }    
    }
}
// Custom function for the Ultrasonic sensor
long getDistance(){
  //int i=10;
  
  //while( i<=10 ) {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration*0.034/2;
  //sumDistance += distance;
  //}
  //int averageDistance= sumDistance/10;
  return distance;
}
