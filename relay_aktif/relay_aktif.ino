#define RELAY_ON 0
#define RELAY_OFF 1
#define RELAY_1  0   // pin yang digunakan yaitu pin 2

void setup()
{
  Serial.begin (9600);
  pinMode(RELAY_1, OUTPUT);
  digitalWrite(RELAY_1, RELAY_ON);
}
 
void loop()
{
digitalWrite (RELAY_1, RELAY_ON);
Serial.println ("ON");
delay(2000);
digitalWrite (RELAY_1, RELAY_OFF);
Serial.println ("OFF");
delay(2000);
digitalWrite (RELAY_1, RELAY_ON);
Serial.println ("ON");
delay(2000);
digitalWrite (RELAY_1, RELAY_OFF);
Serial.println ("OFF");
delay(2000);
digitalWrite (RELAY_1, RELAY_ON);
Serial.println ("ON");
delay(2000);
digitalWrite (RELAY_1, RELAY_OFF);
Serial.print ("OFF");
delay(2000);
}
