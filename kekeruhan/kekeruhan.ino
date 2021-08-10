void setup() {
  Serial.begin(9600);
}
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1024.0)+1.06; 
  Serial.print ("ph = ");
  Serial.println(voltage);
  delay(2000);
}
