/* program to servo control with led 
 * -----------------------------------
 */
#include <Servo.h>
#define RedLed 5
#define GreenLed 6
#define BlueLed 7
#define Pot A5
#define ServoMotor1 9
#define LedWait 300
#define ServoWait 20 

Servo myservo;           // create servo object to control a servo

int pos = 0;             // variable to store the servo position
int Data[10];            // Variable to store potentiometer data
int SmoothData=0;        // Variable to store potentiometer average data
///////////////////////////////////////////////////////
void setup() {
  myservo.attach(ServoMotor1);  // attaches the servo on pin 9 to the servo object

  pinMode(RedLed,OUTPUT);
  pinMode(GreenLed,OUTPUT);
  pinMode(BlueLed,OUTPUT);
  pinMode(Pot,INPUT);
  
  Serial.begin(9600);
}
/////////////////////////////////////////////////////
void loop(){
  Smoothing();
  
  myservo.write(SmoothData);                // tell servo to go to position in variable 'D'
  delay(ServoWait);                         // waits 15ms for the servo to reach the position

  LedAnimation();
}
//////////////////////////////////////////////////
/////////smoothing function starts here//////////
void Smoothing(){
 for(int i=0; i<10;i++){                   // Data Sampling Starts here
   Data[i]=analogRead(Pot);
   SmoothData=SmoothData+Data[i];
   delay(1);
 }
 SmoothData=SmoothData/10;                // We found the average Data
   
 delay(10);
 SmoothData=map(SmoothData,0,1023,0,180); // We found the Smoothed Mapped data
 Serial.println(SmoothData);  
}
//////////////////////////////////////////////////
///////ledanimation function starts here/////////
void LedAnimation(){
if(SmoothData<45){  
    digitalWrite(RedLed,0);
    delay(LedWait);
    digitalWrite(GreenLed,1);
    digitalWrite(BlueLed,1);
    delay(LedWait);
  }
  else if(SmoothData>=45&&SmoothData<90){
        digitalWrite(GreenLed,0);
        delay(LedWait);
        digitalWrite(RedLed,1);
        digitalWrite(BlueLed,1);
        delay(LedWait);
       }
        else if(SmoothData>=90&&SmoothData<135){
                digitalWrite(BlueLed,0);
                delay(LedWait);
                digitalWrite(GreenLed,1);
                digitalWrite(RedLed,1);
                delay(LedWait);
             }  
}
