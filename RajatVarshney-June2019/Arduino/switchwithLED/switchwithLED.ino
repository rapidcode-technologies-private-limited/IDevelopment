void setup() {
  // put your setup code here, to run once:
pinMode(9,INPUT_PULLUP);
pinMode(10,INPUT_PULLUP);
Serial.begin(9600);
}

void loop() {
  int a,b;
  a=digitalRead(9);
  Serial.println(a);
  Serial.print(",");
  b=digitalRead(10);
  Serial.print(b);
 { if(a==0)
  digitalWrite(2,HIGH);
  else
  digitalWrite(2,LOW);
 }
 {
  if(b==0)
  digitalWrite(4,HIGH);
  else
  digitalWrite(4,LOW);
 }
  
  // put your main code here, to run repeatedly:

}
