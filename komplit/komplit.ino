#include <OneWire.h>
#include <DallasTemperature.h>

int temp_sensor = 6;
float temperature = 0;  
OneWire ourWire(temp_sensor);
DallasTemperature sensors(&ourWire);
void setup() 
{
Serial.begin(9600);
sensors.begin();
delay(1000);
sensors.begin();
}

void loop() 
{
  sensors.requestTemperatures(); 
  temperature = sensors.getTempCByIndex(0);
  Serial.print("Temperature is ");
  Serial.println(temperature);
  delay(500);
}


