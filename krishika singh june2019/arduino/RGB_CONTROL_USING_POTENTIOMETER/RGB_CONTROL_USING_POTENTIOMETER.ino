/*       Program to control the RGB LED using Potentiometer  
 * -----------------------------------------------------------------
 * Hardware configured for RGB LED with Common Anode Configuration
 * RedLed:   9
 * GreenLEd: 5
 * BlueLed: 10
 *------------------------------------------------------------------
 */

#define Pot A0
#define RedLed 9
#define GreenLed 5
#define BlueLed 10
#define Delay 100    // Delayvalue for LED Control

int data=0;          // TO store potentiometer data
//////////////////////////////////////////////////////////////////////////////////////
void setup() {
 pinMode(RedLed, OUTPUT);    //configuring the RedLed as Output device 
 pinMode(GreenLed, OUTPUT);  //configuring the GreenLed as Output device
 pinMode(BlueLed, OUTPUT);   //configuring the BlueLed as Output device

 // We are making Sure that led is turned off //
 digitalWrite(RedLed, HIGH);
 digitalWrite(GreenLed, HIGH);
 digitalWrite(BlueLed, HIGH);

 Serial.begin(9600);         // Serial Window for debugging
}
//////////////////////////////////////////////////////////////////////////////////////
void loop() {
data= analogRead(Pot);      // Reading the potentiometer data 
MapData();                  // Calling Map Function 
//RGBControl();             // Calling RGB Function
}
//////////////////////////////////////////////////////////////////////////////////////
// RGB Brightness Control using Map Function Starts Here //
void MapData(){
  Serial.print("Actual Data: ");
  Serial.println(data);                  // Printing OUT the potentiometer actual Data
  
  data= map(data, 0, 1023, 0, 255); 
  
  Serial.print("After data mapping: ");
  Serial.println(data);                  // Printing OUT the potentiometer mapped Data
  Serial.println(""); 

  analogWrite(RedLed,data);              // Passsing the Mapped Data to RedLed
  delay(Delay);
  analogWrite(GreenLed,data);            // Passsing the Mapped Data to GreenLed
  delay(Delay);
  analogWrite(BlueLed,data);             // Passsing the Mapped Data to BlueLed
  delay(Delay);  
}
//////////////////////////////////////////////////////////////////////////////////////
// RGB Blinking Pattern Function Starts here  //
void RGBControl(){
  digitalWrite(RedLed,0);                //turning the redled on
  delay(data);
  digitalWrite(RedLed,1);                //turning the redled off
  delay(data);
  
  digitalWrite(GreenLed,0);              //turning the greenled on
  delay(data);
  digitalWrite(GreenLed,1);              //turning the greenled off
  delay(data);
  
  digitalWrite(BlueLed,0);               //turning the blueled on
  delay(data);
  digitalWrite(BlueLed,1);               //turning the blueled off
  delay(data);
}
