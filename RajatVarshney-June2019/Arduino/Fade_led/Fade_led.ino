int ledPin=2;
int potentiometer=3;
void setup() {
  pinMode(ledPin,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  potentiometer=(analogRead(3)/4);
  analogWrite(ledPin,potentiometer);
  delay(2000);
  // put your main code here, to run repeatedly:

}
