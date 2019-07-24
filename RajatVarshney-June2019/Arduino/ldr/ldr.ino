void setup() {
  pinMode(4,INPUT);
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  
  // put your setup code here, to run once:

}

void loop() {
  
int  ldr=analogRead(4);
int b=ldr/4;
  Serial.println(255-b);
  analogWrite(3,b);
  // put your main code here, to run repeatedly:

}
