
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

int data;

void setup() {
  // put your setup code here, to run once:
   mySerial.begin(9600);
   Serial.begin(9600);
//  mySerial.println("");
pinMode(6,OUTPUT);
}

void loop() {
  
  if (mySerial.available()) {
    data=mySerial.read();
    Serial.write(data);
    Serial.println();
  }

if(data=='1')
{
  digitalWrite(6,HIGH);
  delay(100);
  Serial.println("1");
}  
if(data=='2')
{
  digitalWrite(6,LOW);
  delay(100);
  Serial.println("2");
}
if(data=='4')
{
  Serial.println("4");
  digitalWrite(6,HIGH);
  delay(300);
  digitalWrite(6,LOW);
  delay(300);
  
 }
}

  
