#include <SPI.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Ethernet.h> 
LiquidCrystal_I2C lcd(0x27,20,4);
LiquidCrystal_I2C lcd1(0x23,20,4);

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,2);
char server[] = "192.168.1.1";
EthernetClient client;


//untuk keypad
const byte numRows= 4; //baris pada keypad
const byte numCols= 4; //Kolom pada keypad
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
boolean presentValue = false;

//define relay
#define RELAY_ON 0 //relay off
#define RELAY_OFF 1 //relay off
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
int buzzer=13;


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
float keruh=3.0;

OneWire ourWire(temp_sensor);
DallasTemperature sensors(&ourWire);
long previousMillis = 0;
long interval = 1000; 

void setup() 
{
sensors.begin();

  
//untuk lcd
lcd.init();                      // initialize the lcd 
lcd1.init();
lcd.backlight();
lcd1.backlight();
lcd1.setCursor(3,0);
lcd1.print("WELCOME");
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

//delay(1000);

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
lcd.setCursor(0,0);
lcd.print("Kualitas Air Tambak");
lcd.setCursor(12,1);
lcd.print("|");
lcd.setCursor(12,2);
lcd.print("|");
lcd.setCursor(12,3);
lcd.print("|");
lcd1.setCursor(4,0);
lcd1.print("Control Panel");

}



void loop() 
{
  unsigned long currentMillis = millis();
  if(currentMillis - previousMillis > interval) {
  previousMillis = currentMillis;
  
  sensors.requestTemperatures(); 
  temperature = sensors.getTempCByIndex(0);
  if (client.connect(server, 80)) {  
    client.print("GET /data/write_data_suhu.php?"); // This
    client.print("value="); // This
    client.print(temperature); // And this is what we did in the testing section above. We are making a GET request just like we would from our browser but now with live data from the sensor
    client.println(" HTTP/1.1"); // Part of the GET request
    client.println("Host: 192.168.1.1"); // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie.Host: "www.yourwebpage.com")
    client.println("Connection: close"); // Part of the GET request telling the server that we are over transmitting the message
    client.stop();    // Closing connection to server
  }else{Serial.print ("salah");}
  
 
  //cek kondisi kekeruhan
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage1 = sensorValue * (5.0 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
   if (client.connect(server, 80)) {  
    client.print("GET /data/write_data_kekeruhan.php?"); // This
    client.print("value="); // This
    client.print(voltage1); // And this is what we did in the testing section above. We are making a GET request just like we would from our browser but now with live data from the sensor
    client.println(" HTTP/1.1"); // Part of the GET request
    client.println("Host: 192.168.1.1"); // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie.Host: "www.yourwebpage.com")
    client.println("Connection: close"); // Part of the GET request telling the server that we are over transmitting the message
    client.stop();    // Closing connection to server
  }else{Serial.print ("salah");}

  //cek kondisi ph
    for(int i=0;i<10;i++) { 
      buf[i]=analogRead(analogInPin);
      delay(10);
     }
        for(int i=0;i<9;i++)
        {
          for(int j=i+1;j<10;j++)
            {
              if(buf[i]>buf[j])
                {
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
    pHValue = -5.70 * pHVol + 21.34 - 1.2;
     if (client.connect(server, 80)) {  
    client.print("GET /data/write_data_ph.php?"); // This
    client.print("value="); // This
    client.print(pHValue); // And this is what we did in the testing section above. We are making a GET request just like we would from our browser but now with live data from the sensor
    client.println(" HTTP/1.1"); // Part of the GET request
    client.println("Host: 192.168.1.1"); // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie.Host: "www.yourwebpage.com")
    client.println("Connection: close"); // Part of the GET request telling the server that we are over transmitting the message
    client.stop();    // Closing connection to server
  }else{Serial.print ("salah");}
            
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
    
   //cetak lcd1
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
    //buzpend();
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
  
  char key = myKeypad.getKey();
  if (key != NO_KEY && (key=='1')){
    if (presentValue != true){
    lowerLimit = lowerLimit - 0.1;
    Serial.println(lowerLimit);
    }
  }else if (key != NO_KEY && (key=='2')){
    if (presentValue != true){
    lowerLimit = lowerLimit + 0.1;
    Serial.println(lowerLimit);
    }
  }
  else if (key != NO_KEY && (key=='4')){
    if (presentValue != true){
    upperLimit = upperLimit - 0.1;
    Serial.println(upperLimit);
    }
  }
  else if (key != NO_KEY && (key=='5')){
    if (presentValue != true){
    upperLimit = upperLimit + 0.1;
    Serial.println(upperLimit);
    }
  }
  else if (key != NO_KEY && (key=='7')){
    if (presentValue != true){
    minph = minph - 0.1;
    Serial.println(minph);
    }
  }
   else if (key != NO_KEY && (key=='8')){
    if (presentValue != true){
    minph = minph + 0.1;
    Serial.println(minph);
    }
  }
   else if (key != NO_KEY && (key=='*')){
    if (presentValue != true){
    maxph = maxph - 0.1;
    Serial.println(maxph);
    }
  }
   else if (key != NO_KEY && (key=='0')){
    if (presentValue != true){
    maxph = maxph + 0.1;
    Serial.println(maxph);
    }
  }
   else if (key != NO_KEY && (key=='3')){
    if (keruh != true){
    keruh = keruh - 0.1;
    Serial.println(keruh);
    }
  }
   else if (key != NO_KEY && (key=='A')){
    if (keruh != true){
    keruh = keruh + 0.1;
    Serial.println(keruh);
    }
  }

 }
}






