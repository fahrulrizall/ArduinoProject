#include "ThingSpeak.h"
#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Ethernet.h> 
LiquidCrystal_I2C lcd(0x27,20,4);
LiquidCrystal_I2C lcd1(0x23,20,4);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,10,2);
char server[] = "192.168.10.1";
EthernetClient client;

unsigned long myChannelNumber = 580879;
const char * myWriteAPIKey = "8TNI2XOF5CDPU90K";

// ThingSpeak Settings
//char thingSpeakAddress[] = “api.thingspeak.com”;
//String writeAPIKey = “8TNI2XOF5CDPU90K”;    // Write API Key for a ThingSpeak Channel
//const int updateInterval = 10000;        // Time interval in milliseconds to update ThingSpeak

//define relay
#define RELAY_ON 0 //relay off
#define RELAY_OFF 1 //relay on
#define RELAY_1  2   // pin yang digunakan yaitu pin 2
#define RELAY_2  3   // pin yang digunakan yaitu pin 3
#define RELAY_3  4   // pin yang digunakan yaitu pin 4
#define RELAY_4  5   // pin yang digunakan yaitu pin 5

//define ph
const int analogInPin = A1; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;


//untuk buzzer
const int buzzer=13;


//untuk suhu
int temp_sensor = 6;
float temperature = 0;    //Variable to store the temperature in
float lowerLimit = 27.0;      //define the lower threshold for the temperature
float upperLimit = 32.0;      //define the upper threshold for the temperature

//untuk ph
float minph = 7.6;
float maxph = 7.9;
float pHValue=0;

//untuk kekeruhan
float voltage1 = 0;
float keruh=3.5;

OneWire ourWire(temp_sensor);
DallasTemperature sensors(&ourWire);
long previousMillis = 0;
long interval = 1000; 
int button = 8;
int button1 = 9;
int button2 = 11;
int button3 = 22;
int button4 = 23;
int button5 = 24;
int button6 = 25;
int button7 = 26;
int button8 = 27;
int button9 = 28;
int button10 = 29;


void setup() 
{
sensors.begin();
//untuk lcd
lcd.init();                      // initialize the lcd 
lcd1.init();
lcd.backlight();
lcd1.backlight();
lcd1.setCursor(4,1);
lcd1.print("FAHRUL RIZAL");
lcd1.setCursor(5,2);
lcd1.print("1415051066");
lcd.setCursor(0,0);
lcd.print("PROTOTIPE MONITORING");
lcd.setCursor(0,1);
lcd.print("KUALITAS AIR TAMBAK");
lcd.setCursor(3,2);
lcd.print("IKAN KERAPU");
lcd.setCursor(1,3);
lcd.print("BERBASIS ARDUINO");
delay(5000);
lcd.clear();
lcd1.clear();
  
Serial.begin(9600);

pinMode(RELAY_1, OUTPUT);
digitalWrite(RELAY_1, RELAY_ON);
pinMode(RELAY_2, OUTPUT);
digitalWrite(RELAY_2, RELAY_ON);
pinMode(RELAY_3, OUTPUT);
digitalWrite(RELAY_3, RELAY_ON);
pinMode(RELAY_4, OUTPUT);
digitalWrite(RELAY_4, RELAY_ON);
//delay(1000);
Ethernet.begin(mac, ip);
ThingSpeak.begin(client);
lcd.setCursor(0,0);
lcd.print("Kualitas Air Tambak");
//lcd.setCursor(12,1);
//lcd.print("|");
//lcd.setCursor(12,2);
//lcd.print("|");
//lcd.setCursor(12,3);
//lcd.print("|");
//lcd1.setCursor(2,0);
lcd1.print("Control Panel");
//buzzzer
pinMode(buzzer, OUTPUT);
//tombol
pinMode(button, INPUT);
digitalWrite(button, HIGH);
pinMode(button1, INPUT);
digitalWrite(button1, HIGH);
pinMode(button2, INPUT);
digitalWrite(button2, HIGH);
pinMode(button3, INPUT);
digitalWrite(button3, HIGH);
pinMode(button4, INPUT);
digitalWrite(button4, HIGH);
pinMode(button5, INPUT);
digitalWrite(button5, HIGH);
pinMode(button6, INPUT);
digitalWrite(button6, HIGH);
pinMode(button7, INPUT);
digitalWrite(button7, HIGH);
pinMode(button8, INPUT);
digitalWrite(button8, HIGH);
pinMode(button9, INPUT);
digitalWrite(button9, HIGH);
pinMode(button10, INPUT);
digitalWrite(button10, HIGH);
//led
pinMode(30, OUTPUT);
pinMode(31, OUTPUT);
}



void loop(){ 
  lcd1.setCursor (0,1);
  lcd1.print("p- = ");
  lcd1.setCursor (5,1);
  lcd1.print(minph);
  lcd1.setCursor (0,2);
  lcd1.print("p+ = ");
  lcd1.setCursor (5,2);
  lcd1.print(maxph);
  lcd1.setCursor (10,1);
  lcd1.print("s- = ");
  lcd1.setCursor (15,1);
  lcd1.print(lowerLimit);
  lcd1.setCursor (10,2);
  lcd1.print("s+ = ");
  lcd1.setCursor (15,2);
  lcd1.print(upperLimit);
  lcd1.setCursor (6,3);
  lcd1.print("krh = ");
  lcd1.setCursor (12,3);
  lcd1.print(keruh);

  if (digitalRead(button)==LOW){
//  digitalWrite(30, LOW); 
//  digitalWrite(31, HIGH); 
  lcd1.setCursor(16,0);
  lcd1.print("ON");
  gantidata();
  }else if (digitalRead(button)==HIGH){
//  digitalWrite(31, LOW); 
//  digitalWrite(30, HIGH);  
  lcd1.setCursor(16,0);
  lcd1.print("OF");
  suhu();
  krh();
  ph();
  kirimdata();
  }
}


void notiftombol(){
  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW);
  delay(300);
  digitalWrite(buzzer,HIGH);
  delay(300);
  digitalWrite(buzzer,LOW);
  delay(300);
  }

void gantidata(){
   if (digitalRead(button1)==LOW){
      lowerLimit = lowerLimit - 0.1;
      delay(100);
   }
   if (digitalRead(button2)==LOW){
      lowerLimit = lowerLimit + 0.1;
      delay(100);
   } 
   if (digitalRead(button3)==LOW){
      upperLimit = upperLimit - 0.1;
      delay(100);
   }
   if (digitalRead(button4)==LOW){
      upperLimit = upperLimit + 0.1;
      delay(100);
   }
   if (digitalRead(button5)==LOW){
      minph = minph - 0.1;
      delay(100);
   }   
   if (digitalRead(button6)==LOW){
      minph = minph + 0.1;
      delay(100);
   } 
   if (digitalRead(button7)==LOW){
      maxph = maxph - 0.1;
      delay(100);
   } 
   if (digitalRead(button8)==LOW){
      maxph = maxph + 0.1;
      delay(100);
   } 
   if (digitalRead(button9)==LOW){
      keruh = keruh - 0.1;
      delay(100);
   }
   if (digitalRead(button10)==LOW){
      keruh = keruh + 0.1;
      delay(100);
   }  
 }

void suhu(){
  sensors.requestTemperatures(); 
  temperature = sensors.getTempCByIndex(0);
  lcd.setCursor(0,1);
  lcd.print("s = ");
  Serial.print("Temperature is ");
  Serial.print(temperature);
  lcd.print(temperature);
  //aksi suhu  
  if(temperature < lowerLimit){
  digitalWrite(RELAY_1, RELAY_OFF);
  notiftombol();
  digitalWrite(30, LOW);
  digitalWrite(31, HIGH);
  lcd.setCursor(10,1);
  lcd.print("T");
  lcd.setCursor(13,1);
  lcd.print("P1 = ON");
  }else 
  if(temperature >= lowerLimit && temperature <= upperLimit){
  digitalWrite(RELAY_1, RELAY_ON);
  digitalWrite(31, LOW);
  digitalWrite(30, HIGH); 
  lcd.setCursor(10,1);
  lcd.print("N");
  lcd.setCursor(13,1);
  lcd.print("P1 = OF");
  }else 
  if(temperature > upperLimit){
  digitalWrite(RELAY_1, RELAY_OFF);
  notiftombol();
  digitalWrite(30, LOW);
  digitalWrite(31, HIGH);
  lcd.setCursor(10,1);
  lcd.print("T");
  lcd.setCursor(13,1);
  lcd.print("P1 = ON");
  }
  ThingSpeak.writeField(myChannelNumber, 1, voltage, myWriteAPIKey);
}

void krh(){
  //cek kondisi kekeruhan
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage1 = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  lcd.setCursor(0,2);
  lcd.print("k = ");
  lcd.print(voltage1);
  //penentuan aksi kekeruhan
  if(voltage1 < keruh){
  digitalWrite(RELAY_2, RELAY_OFF);
  notiftombol();
  digitalWrite(30, LOW);
  digitalWrite(31, HIGH);
  lcd.setCursor(10,2);
  lcd.print("T");
  lcd.setCursor(13,2);
  lcd.print("P2 = ON");
  }else {
  digitalWrite(RELAY_2, RELAY_ON);
  digitalWrite(31, LOW);
  digitalWrite(30, HIGH); 
  lcd.setCursor(10,2);
  lcd.print("N");
  lcd.setCursor(13,2);
  lcd.print("P2 = OF");
 }
}

void ph() {
  //cek kondisi ph
    for(int i=0;i<10;i++) { 
    buf[i]=analogRead(analogInPin);
    delay(10);}
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
    pHValue = pHVol+5.7;
              
   //cetak di lcd    
   lcd.setCursor(0,3);
   lcd.print("p = ");
   lcd.print(pHValue);
   //penentuan aksi pH
   if(pHValue < minph){
   digitalWrite(RELAY_3, RELAY_OFF);
   notiftombol();
   digitalWrite(30, LOW);
   digitalWrite(31, HIGH);
   lcd.setCursor(10,3);
   lcd.print("T");
   lcd.setCursor(13,3);
   lcd.print("P3 = ON");
   }else 
   if(pHValue >= minph && pHValue <= maxph){
   digitalWrite(RELAY_3, RELAY_ON);
   digitalWrite(31, LOW);
   digitalWrite(30, HIGH); 
   lcd.setCursor(10,3);
   lcd.print("N");
   lcd.setCursor(13,3);
   lcd.print("P3 = OF");
   }else 
   if(temperature > maxph){
   digitalWrite(RELAY_3, RELAY_OFF);
   notiftombol();
   digitalWrite(30, LOW);
   digitalWrite(31, HIGH);
   lcd.setCursor(10,3);
   lcd.print("T");
   lcd.setCursor(13,3);
   lcd.print("P3 = ON");
  }
}


//void kirimdata(){
//  if (client.connect(server, 80)){
//  //kirimdatasuhu
//  client.connect(server, 80);
//  client.print("POST /update?api_key=8TNI2XOF5CDPU90K&field1=");
//  client.print(temperature);
//  client.println();
//  client.println(" HTTP/1.1"); 
//  client.println("Host: api.thingspeak.com");
//  client.println("Connection: close");
//  client.stop(); 
//  // //kirimdataph
//  client.connect(server, 80);
//  client.print("POST /data/write_data_ph.php?value=");
//  client.print(pHValue);
//  client.println();
//  client.println(" HTTP/1.1"); 
//  client.println("Host: 192.168.10.1");
//  client.println("Connection: close");
//  client.stop(); 
//  //kirimdatakeruh
//  client.connect(server, 80);
//  client.print("POST /data/write_data_kekeruhan.php?value=");
//  client.print(keruh);
//  client.println();
//  client.println(" HTTP/1.1"); 
//  client.println("Host: 192.168.10.1");
//  client.println("Connection: close");
//  client.stop();
//  }else{Serial.print(" ");}
//}






