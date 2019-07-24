void setup() {
 pinMode(2,INPUT);
 Serial.begin(9600);
 
  // put your setup code here, to run once:

}

void loop() {
 int ir=digitalRead(2);
  Serial.println(ir);
  // put your main code here, to run repeatedly:

}
