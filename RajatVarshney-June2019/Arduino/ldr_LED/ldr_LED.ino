#define ledPin 5
#define ldrPin A4
void setup() {

 Serial.begin(9600);
 pinMode(ledPin,OUTPUT);
 pinMode(ldrPin,INPUT);
 
  // put your setup code here, to run once:

}

void loop() {
 int ldrStatus=analogRead(ldrPin);
 if(ldrStatus<=200){
  digitalWrite(ledPin,HIGH);
  Serial.println(ldrStatus);
 }
 else{
  digitalWrite(ledPin,LOW);
  Serial.println(ldrStatus);
  
 }
  // put your main code here, to run repeatedly:

}
