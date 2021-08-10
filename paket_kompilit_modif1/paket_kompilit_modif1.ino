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
{'1', '2', '3', 'z'},
{'4', '5', '6', 'x'},
{'7', '8', '9', 'C'},
{'A', 'B', '#', 'D'}
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
float keruh = 3.0;

OneWire ourWire(temp_sensor);
DallasTemperature sensors(&ourWire);
long previousMillis = 0;
long interval = 1000; 

int button = 8;
void setup() 
{
sensors.begin();
  pinMode(button, INPUT);
  digitalWrite(button, HIGH);
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
//delay(5000);
lcd.clear();
lcd1.clear();
  
Serial.begin(9600);

//delay(1000);


//delay(1000);

lcd1.setCursor(4,0);
lcd1.print("Control Panel");
Ethernet.begin(mac, ip);

    //minph
    
}

void gantidata(){
  char key = myKeypad.getKey();
  if (key != NO_KEY && (key=='1')){
    lowerLimit = lowerLimit - 0.1;

    //}
  }else if (key != NO_KEY && (key=='2')){
    lowerLimit = lowerLimit + 0.1;

  }
  else if (key != NO_KEY && (key=='4')){
    upperLimit = upperLimit - 0.1;

   }
  else if (key != NO_KEY && (key=='5')){
    upperLimit = upperLimit + 0.1;

   }
  else if (key != NO_KEY && (key=='7')){
    minph = minph - 0.1;

   }
   else if (key != NO_KEY && (key=='8')){
    minph = minph + 0.1;

  }
   else if (key != NO_KEY && (key=='*')){
    maxph = maxph - 0.1;

  }
   else if (key != NO_KEY && (key=='0')){
    maxph = maxph + 0.1;

  }
  else if (key != NO_KEY && (key=='A')){
    keruh = keruh - 0.1;

  }
   else if (key != NO_KEY && (key=='B')){
    keruh = keruh + 0.1;

  }
}

void kirimdata(){
  sensors.requestTemperatures(); 
  temperature = sensors.getTempCByIndex(0);
  if (client.connect(server, 80)) {  
    client.print("GET /data/write_data_suhu.php?"); // This
    client.print("value="); // This
    client.print(temperature); // And this is what we did in the testing section above. We are making a GET request just like we would from our browser but now with live data from the sensor
    client.println(" HTTP/1.1"); // Part of the GET request
    client.println("Host: 192.168.10.1"); // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie.Host: "www.yourwebpage.com")
    client.println("Connection: close"); // Part of the GET request telling the server that we are over transmitting the message
    client.println(); // Empty line
    client.println(); // Empty line
    client.stop();    // Closing connection to server
  }
}

void loop() 
{
   if (digitalRead(button)==LOW){
    Serial.println("ganti data");
    gantidata();
  }else if (digitalRead(button)==HIGH){
    Serial.println("kirim data");
    kirimdata();
    }
  

    lcd1.setCursor (0,1);
    lcd1.print("p- = ");
    lcd1.setCursor (5,1);
    lcd1.print(minph);
    //maxph
    lcd1.setCursor (0,2);
    lcd1.print("p+ = ");
    lcd1.setCursor (5,2);
    lcd1.print(maxph);
    //mihsuhu
    lcd1.setCursor (10,1);
    lcd1.print("s- = ");
    lcd1.setCursor (15,1);
    lcd1.print(lowerLimit);
    //maxsuhu
    lcd1.setCursor (10,2);
    lcd1.print("s+ = ");
    lcd1.setCursor (15,2);
    lcd1.print(upperLimit);
    //keruh
    lcd1.setCursor (6,3);
    lcd1.print("krh = ");
    lcd1.setCursor (12,3);
    lcd1.print(keruh);
    //delay(500);
}







