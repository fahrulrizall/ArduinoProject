const int PIN_11 = 6;
const int tombol = 7;

void setup()
{
pinMode(PIN_11, OUTPUT);
pinMode(tombol, INPUT);
digitalWrite (tombol, HIGH);
Serial.begin (9600);
}

void loop()
{
  if (digitalRead (tombol) == LOW){
    analogWrite(PIN_11, 255);
    Serial.println ("LOW");
    //delay(1000); // Tunda 1 detik
  }else 
  if (digitalRead (tombol)==HIGH){
    analogWrite(PIN_11, 10);
    Serial.println ("HIGH");
    //delay(1000); // Tunda 1 detik
   }
}
