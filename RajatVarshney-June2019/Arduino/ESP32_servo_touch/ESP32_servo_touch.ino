#include <ESP32Servo.h>
Servo myServo;
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.printf("ESP Touch Test");
  myServo.attach(5);
  
  // put your setup code here, to run once:

}

void loop() {
int a,b,i;
Serial.println("pin 4=");
a=touchRead(4);
Serial.println(a);

  if(a<=30)
  {
    for(int i=0;i<90;i++)
    {
      myServo.write(i);
      delay(30);
    }
  }
  // put your main code here, to run repeatedly:
  b=touchRead(15);
Serial.println(b);

  if(b<=30)
  {
    for(int i=0;i<=180;i++)
    {
      myServo.write(i);
      delay(30);
    }
  }
}
