#include <SoftwareSerial.h>
#include <OneWire.h>
#include <DallasTemperature.h>
SoftwareSerial wifi (10,11); // Rx Tx

#define nama_wifi "wifiii"
#define pass_wifi "nasibiru"
#define ip_host "192.168.137.1"  // ip computer kita, bisa liat di CMD (ipconfig)

int temp_sensor = 6;
float temperature = 0; 
boolean connected = false;
OneWire ourWire(temp_sensor);
DallasTemperature sensors(&ourWire);

void setup() {
sensors.begin();
  // put your setup code here, to run once:
wifi.begin(9600);
Serial.begin(9600);
wifi.setTimeout(5000);
Serial.println("ESP8266 cek cek");
delay (1000);
wifi.println("AT+RST");
delay(10000);
if(wifi.find("WIFI GOT IP"))
{
  Serial.println(" ESP8266 SIAP ");
}
else {
  Serial.println(" Tidak Ada Response dari ESP8266 ");
  while(1);
}
delay(1000);

for (int i=0; i<5; i++){
  connect_to_wifi();
  if (connected){
    break;
  }
}
  if (!connected){
    while(1);
  }
  delay(5000);
  wifi.println("AT+CIPMUX=0");
  delay(10000);
}

void loop() {
sensors.requestTemperatures(); 
temperature = sensors.getTempCByIndex(0);
  // put your main code here, to run repeatedly:
String cmd = "AT+CIPSTART=\"TCP\",\"";
cmd+= ip_host;
cmd+="\",80";
wifi.println(cmd);
Serial.println(cmd);
if (wifi.find("Error")){
  Serial.println("Koneksi eror");
  return;
}
//nilai_sensor = analogRead(sensorPin);
cmd = "GET /data/write_data.php?value=";
cmd+=temperature;
cmd+="HTTP/1.0/1/\r\n";
cmd+="\r\n";
wifi.print("AT+CIPSEND=");
wifi.println(cmd.length());
if (wifi.find(">")){
  Serial.print(">");
} else {
  wifi.println("AT+CIPCLOSE");
  Serial.println("Koneksi Timeout");
  delay(1000);
  return;
}
wifi.print(cmd);
delay(2000);

while(wifi.available())
{
  char c =wifi.read();
  Serial.write(c);
  if (c=='\r') Serial.print('\n');
}
Serial.println("-----end");
delay(10000);
}

void connect_to_wifi()
{
  wifi.println("AT+CWMODE=1");
  String cmd = "AT+CWJAP=\"";
  cmd+=nama_wifi;
  cmd+="\",\"";
  cmd+=pass_wifi;
  cmd+="\"";
  wifi.println(cmd);
  Serial.println(cmd);
  if (wifi.find("OK")){
    Serial.println("Berhasil Terkoneksi ke internet");
  connected=true;
  } else {
    Serial.println("Gagal Terkoneksi");
  connected=false;
  }

}
