/* -------------------------------------------------|
 *        Application: Controlling the RGB LED      |
 * -------------------------------------------------|
 *            Hardware Configuration:               |
 *------------------------------------------------- | 
 *  Pin 7: Cathode of RED LED                       |
 *  Pin 6: Cathode of Green LED                     |
 *  Pin 5: Cathode of Blue LED                      |
 *  5V   : Anode Pin of LED                         |
 *  ------------------------------------------------|
 *            Author: Kamini Singh                  |
 *              Version: 1.0.0                      |
 *  ------------------------------------------------|
 *        Code Reviewed By : Abhishek Nair          |
 *--------------------------------------------------
 */ 

////////////////////Code Begins/////////////////////
///////////////////Configurations/////////////////////
#define RedLed 7
#define GreenLed 6
#define BlueLed 5

#define wait 600
////////////////////////////////////////////////////

void setup() {
  pinMode(RedLed,OUTPUT);    //configuring the RedLed as Output device
  pinMode(GreenLed,OUTPUT); //configuring the greenLed as Output device
  pinMode(BlueLed,OUTPUT); //configuring the BlueLed as Output device
}

void loop() {

	digitalWrite(RedLed,0); //turning the RedLed on
	delay(wait);
	digitalWrite(RedLed,1); //turning the RedLed off
	delay(wait);

	digitalWrite(GreenLed,0); //turning the GreenLed on
	delay(wait);
	digitalWrite(GreenLed,1); //turning the GreenLed off 
	delay(wait);

	digitalWrite(BlueLed,0); //turning the BlueLed on
	delay(wait);
	digitalWrite(BlueLed,1); //turning the BlueLed off
	delay(wait);
}
