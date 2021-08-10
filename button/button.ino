int button =8;
void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  digitalWrite(button, HIGH); //activate arduino internal pull up
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(button)==LOW){ 
      Serial.println("ganti data");
  }else 
  if (digitalRead(button)==HIGH){
      Serial.println("kirim data");
   }
   
}
