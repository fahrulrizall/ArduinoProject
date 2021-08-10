#include <SPI.h>
#include <Ethernet.h>
#include <OneWire.h>
#include <DallasTemperature.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
 
// Enter the IP address for Arduino, as mentioned we will use 192.168.0.16
// Be careful to use , insetead of . when you enter the address here
IPAddress ip(192,168,10,2);

int temp_sensor = 6;
float temperature = 0;
OneWire ourWire(temp_sensor);
DallasTemperature sensors(&ourWire); 

char server[] = "192.168.10.1"; // IMPORTANT: If you are using XAMPP you will have to find out the IP address of your computer and put it here (it is explained in previous article). If you have a web page, enter its address (ie. "www.yourwebpage.com")

// Initialize the Ethernet server library
EthernetClient client;

void setup() {
  sensors.begin();
  // Serial.begin starts the serial connection between computer and Arduino
  Serial.begin(9600);
 
  // start the Ethernet connection
  Ethernet.begin(mac, ip);
  Serial.print("oii");
    
}

void loop() {
 
  sensors.requestTemperatures(); 
  temperature = sensors.getTempCByIndex(0);
  //gantidata();
  //cek kondisi kekeruhan
  int sensorValue = analogRead(A0);// read the input on analog pin 0:
  float voltage1 = sensorValue * (5.0 / 1024.0);
  Serial.println(voltage1);
 
  // Connect to the server (your computer or web page)
    client.connect(server, 80);  
    client.print("GET /data/write_data_suhu.php?value="); // This
    client.print(temperature); 
    client.println(" HTTP/1.1"); 
    client.println("Host: 192.168.10.1");
    client.println("Connection: close");
    client.println(); 
    client.stop();
  delay(10000);
}
