#include <SoftwareSerial.h>

int RX_PIN = 6;
int TX_PIN = 7;
int BAUD_IDE = 9600;
int BAUD_WEIGHT_SENSOR = 9600;

// serial port from weight controller
SoftwareSerial mySerial = SoftwareSerial(RX_PIN, TX_PIN);

void setup() {   
  mySerial.begin(BAUD_WEIGHT_SENSOR);
  Serial.begin(BAUD_IDE);
}

void loop() {
if (mySerial.available()){
Serial.print((char)mySerial.read());
}
}
