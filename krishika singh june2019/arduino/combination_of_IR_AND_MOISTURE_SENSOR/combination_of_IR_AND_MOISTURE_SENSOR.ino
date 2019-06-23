/*     Program for combination of IR and SOILMOISTURE sensors
 * ----------------------------------------------------------
 *  Hardware configured sensors 
 *  SOILMOISTURE SENSORS:-8 
 *  IR SENSORS:-9
 * ----------------------------------------------------------
 */
#define ledpin 13      //Built in LED as Indicator
#define sensor1pin 8   //Soil Mositure Sensor Connected here
#define sensor2pin 9   //IR Sensor Connected here
///////////////////////////////////////////////////////////////////////////////
void setup() {  
  pinMode(ledpin,OUTPUT);         //configuring the ledpin as Output device 
  pinMode(sensor1pin,INPUT);     //configuring the Soil Mositure sensor pin as Output device 
  pinMode(sensor2pin,INPUT);    //configuring the IR sensor pin as Output device 
  Serial.begin(9600);          // Serial Window for debugging
}
///////////////////////////////////////////////////////////////////////////////
void loop() {
  SoilMoisture();                     //calling SoilMoisture function
  IR();                               //calling IR function
  Serial.println();
}
///////////////////////////////////////////////////////////////////////////////
///////SoilMoisture function starts here/////////////
void SoilMoisture(){
  int a;
  a = digitalRead(sensor1pin);      // Reads the output of sensor1pin 
  Serial.print("Soil Moisture Sensor Data: ");
  Serial.println(a);

  if (a)
    digitalWrite(ledpin,HIGH);           //turning the led on
  else
  {
    digitalWrite(ledpin,LOW);           //turning the led off
    delay(500);
  } 
}
///////////////////////////////////////////////////////////////////////////////
////////////IR function starts here/////////////////
void IR()
{
  int b;
  b = digitalRead(sensor2pin);      // Reads the output of sensor2pin 
  Serial.print("IR sensor Data: ");
  Serial.println(b);

  if (b)
    digitalWrite(ledpin,HIGH);           //turning the led on
  else
  {
    digitalWrite(ledpin,LOW);           //turning the led off
    delay(500);
  }
}
