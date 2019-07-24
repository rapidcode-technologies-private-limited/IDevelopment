void setup() {
  pinMode(2,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int a;
  a=digitalRead(2);
  Serial.println(a);
  // put your main code here, to run repeatedly:

}
