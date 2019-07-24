/* program for timer
 *  -----------------------
 *  hardware configuratoin 
 *  1.seven segment display
 *  2.registers of 1Kohm
 * ------------------------ 
 */
void one();         //print one 
void two();         //print two
void three();       //print three
void four();        //print four 
void five();       //print five  
void six();        //print six 
void seven();      //print seven 
void eight();      //print eight
void nine();       //print nine
void zero();       //print zero

#define wait 5     //for wait in on
#define Offwait 0  //for wait in off
#define a 2       //turn on of led A   
#define b 3       //turn on of led B   
#define c 4       //turn on of led C
#define d 5       //turn on of led D
#define e 6       //turn on of led E
#define f 7       //turn on of led F
#define g 8       //turn on of led G
#define dp 9      //turn on of led displaypoint   
#define d3 11      //turn on of display3
#define d4 12      //turn on of display4
#define d5 10      //turn on of display5
#define d6 13      //turn on of display6
#define d1 A0      //turn on of display1
#define d2 A1      //turn on of display2
int displayPinCount=8;  //for led pins
int ControlPinCount=6;  //for display control pins
int displayPins[]={a,b,c,d,e,f,g,dp};   //arry for led pins 
int controlPins[]={d1,d2,d3,d4,d5,d6};  //arry to control display pins 

int Display[]={0,1,2,3,4,5};     //arry to count of display pins 

boolean Second_digitOne = false, Second_digitTwo = false;
int Seconds = 0;   //initial  count for seconds
int Minutes = 0;  // initial count for Minutes
int Hours=0;     //initial count for Hours
int timer1_counter;
boolean SendData=false;

void off()
{ 
    for(int i=0;i<displayPinCount;i++)       //
    {
      digitalWrite(displayPins[i],HIGH);
    }
}

void setup() 
{
 for(int i=0;i<displayPinCount;i++)
 {
    pinMode(displayPins[i],OUTPUT); // put your setup code here, to run once: 
 }

 for(int i=0;i<ControlPinCount;i++)
 {
    pinMode(controlPins[i],OUTPUT); // put your setup code here, to run once: 
 }

 off();

 for(int i=0;i<ControlPinCount;i++)    //loop for off the counts  
 {
    digitalWrite(controlPins[i],LOW); // put your setup code here, to run once: 
 }

  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // Set timer1_counter to the correct value for our interrupt interval
  // timer1_counter = 64911;   // preload timer 65536-16MHz/256/100Hz
  // timer1_counter = 64286;   // preload timer 65536-16MHz/256/50Hz
  // timer1_counter = 34286;   // preload timer 65536-16MHz/256/2Hz
     timer1_counter = 34286/2;
  
  TCNT1 = timer1_counter;   // preload timer
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts
}

ISR(TIMER1_OVF_vect)        // interrupt service routine 
{
  TCNT1 = timer1_counter;   // preload timer
  Seconds++;
  //SendData=true;
}

void loop()
{ 
  if(Seconds>59){      //start point seconds
     Seconds=0;
     Minutes++;
  }
  
  if(Minutes>2 )     //start point minutes
  {
    Minutes=0;
    Hours++;
  }

  if(Hours>24)     //start point hours
  {
    Hours=0;
    Minutes=0;
    Seconds=0;
  }

     DisplayTimeSec(Seconds);
     DisplayTimeMin(Minutes);
     DisplayTimeHrs(Hours);
}
void Control(int data)
{
   for(int i=0;i<ControlPinCount;i++)
    {
      if(i!=Display[data])
        digitalWrite(controlPins[i],LOW);
      else
        digitalWrite(controlPins[i],HIGH);  
    }
}

void zero()
{
  digitalWrite(displayPins[0],0);       //turn on led A  
  digitalWrite(displayPins[1],0);       //turn on led B  
  digitalWrite(displayPins[2],0);       //turn on led C
  digitalWrite(displayPins[3],0);       //turn on led D   
  digitalWrite(displayPins[4],0);       //turn on led E   
  digitalWrite(displayPins[5],0);       //turn on led F  
  digitalWrite(displayPins[6],1);       //turn off led G
  digitalWrite(displayPins[7],0);       //turn on led DP      
}

void one()
{ 
    digitalWrite(displayPins[0],HIGH);       //turn off led A 
    digitalWrite(displayPins[1],LOW);        //turn on led B  
    digitalWrite(displayPins[2],LOW);        //turn on led C  
    digitalWrite(displayPins[3],HIGH);       //turn off led D  
    digitalWrite(displayPins[4],HIGH);       //turn off led E    
    digitalWrite(displayPins[5],HIGH);       //turn off led F   
    digitalWrite(displayPins[6],HIGH);       //turn off led G  
    digitalWrite(displayPins[7],LOW);        //turn on led DP 
}

void two()
{ 
    digitalWrite(displayPins[0],LOW);       //turn on led A  
    digitalWrite(displayPins[1],LOW);       //turn on led B  
    digitalWrite(displayPins[2],HIGH);      //turn off led C  
    digitalWrite(displayPins[3],LOW);       //turn on led D  
    digitalWrite(displayPins[4],LOW);       //turn on led E  
    digitalWrite(displayPins[5],HIGH);      //turn off led F  
    digitalWrite(displayPins[6],LOW);       //turn on led G  
    digitalWrite(displayPins[7],LOW);       //turn on led DP  
}

void three()
{
  digitalWrite(displayPins[0],LOW);       //turn on led A  
  digitalWrite(displayPins[1],LOW);       //turn on led B  
  digitalWrite(displayPins[6],LOW);       //turn on led G  
  digitalWrite(displayPins[2],LOW);       //turn on led C  
  digitalWrite(displayPins[3],LOW);       //turn on led D  
  digitalWrite(displayPins[4],HIGH);      //turn off led E  
  digitalWrite(displayPins[5],HIGH);      //turn off led F  
  digitalWrite(displayPins[7],LOW);       //turn on led DP  
}
void four()
{
  digitalWrite(displayPins[5],0);       //turn on led F  
  digitalWrite(displayPins[6],0);       //turn on led G  
  digitalWrite(displayPins[2],0);       //turn on led C
  digitalWrite(displayPins[1],0);       //turn on led B  
  digitalWrite(displayPins[0],1);       //turn off led A
  digitalWrite(displayPins[3],1);       //turn off led D  
  digitalWrite(displayPins[4],1);       //turn off led E  
  digitalWrite(displayPins[7],0);       //turn on led DP  
}
void five()
{
  digitalWrite(displayPins[0],0);       //turn on led A
  digitalWrite(displayPins[5],0);       //turn on led F  
  digitalWrite(displayPins[6],0);       //turn on led G  
  digitalWrite(displayPins[2],0);       //turn on led C  
  digitalWrite(displayPins[3],0);       //turn on led D  
  digitalWrite(displayPins[1],1);       //turn off led B  
  digitalWrite(displayPins[4],1);       //turn off led E  
  digitalWrite(displayPins[7],0);       //turn on led DP  
}
  void six()
  {
    digitalWrite(displayPins[0],0);       //turn on led A  
    digitalWrite(displayPins[5],0);       //turn on led F  
    digitalWrite(displayPins[6],0);       //turn on led G  
    digitalWrite(displayPins[4],0);       //turn on led E  
    digitalWrite(displayPins[3],0);       //turn on led D  
    digitalWrite(displayPins[2],0);       //turn on led C  
    digitalWrite(displayPins[7],0);       //turn on led DP  
    digitalWrite(displayPins[1],1);       //turn off led B  
   }
void seven()
{
  digitalWrite(displayPins[0],0);       //turn on led A  
  digitalWrite(displayPins[1],0);       //turn on led B  
  digitalWrite(displayPins[2],0);       //turn on led C  
  digitalWrite(displayPins[3],1);       //turn off led D  
  digitalWrite(displayPins[4],1);       //turn off led E  
  digitalWrite(displayPins[5],1);       //turn off led F  
  digitalWrite(displayPins[6],1);       //turn off led G  
  digitalWrite(displayPins[7],0);       //turn on led DP  
}
void eight()
{
    digitalWrite(displayPins[0],0);       //turn on led A  
    digitalWrite(displayPins[1],0);       //turn on led B     
    digitalWrite(displayPins[2],0);       //turn on led C     
    digitalWrite(displayPins[3],0);       //turn on led D
    digitalWrite(displayPins[4],0);       //turn on led E   
    digitalWrite(displayPins[5],0);       //turn on led F   
    digitalWrite(displayPins[6],0);       //turn on led G     
    digitalWrite(displayPins[7],0);       //turn on led DP
    }
void nine()
{
    digitalWrite(displayPins[0],0);       //turn on led A     
    digitalWrite(displayPins[1],0);       //turn on led B     
    digitalWrite(displayPins[2],0);       //turn on led C      
    digitalWrite(displayPins[3],0);       //turn on led D  
    digitalWrite(displayPins[4],1);       //turn off led E   
    digitalWrite(displayPins[5],0);       //turn on led F        
    digitalWrite(displayPins[6],0);       //turn on led G  
    digitalWrite(displayPins[7],0);       //turn on led DP  
}
///////////////////function for Seconds////////////////
void DisplayTimeSec(int Time){     //Display: T1 T2
  int T1=Time/10;
  int T2=Time%10;
  
    if(T1 == 0){
      Control(4);
      zero();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 0){
      Control(5);
      zero();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 1){
      Control(4);
      one();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 1){
      Control(5);
      one();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 2){
      Control(4);
      two();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 2){
      Control(5);
      two();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 3){
      Control(4);
      three();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 3){
      Control(5);
      three();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 4){
      Control(4);
      four();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 4){
      Control(5);
      four();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 5){
      Control(4);
      five();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 5){
      Control(5);
      five();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 6){
      Control(4);
      six();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 6){
      Control(5);
      six();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 7){
      Control(4);
      seven();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 7){
      Control(5);
      seven();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 8){
      Control(4);
      eight();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 8){
      Control(5);
      eight();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 9){
      Control(4);
      nine();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 9){
      Control(5);
      nine();
      delay(wait);
      off();
      delay(Offwait);
    }
}
/////////////////Function for Minutes////////////////////
void DisplayTimeMin(int Time){        //Display: T1 T2
  int T1=Time/10;
  int T2=Time%10;
  
    if(T1 == 0){
      Control(3);
      zero();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 0){
      Control(2);
      zero();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 1){
      Control(3);
      one();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 1){
      Control(2);
      one();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 2){
      Control(3);
      two();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 2){
      Control(2);
      two();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 3){
      Control(3);
      three();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 3){
      Control(2);
      three();
      delay(wait);
      off();  
      delay(Offwait);
    }
    if(T1 == 4){
      Control(3);
      four();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 4){
      Control(2);
      four();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 5){
      Control(3);
      five();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 5){
      Control(2);
      five();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 6){
      Control(3);
      six();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 6){
      Control(2);
      six();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 7){
      Control(3);
      seven();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 7){
      Control(2);
      seven();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 8){
      Control(3);
      eight();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 8){
      Control(2);
      eight();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 9){
      Control(3);
      nine();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 9){
      Control(2);
      nine();
      delay(wait);
      off();
      delay(Offwait);
    }
}

/////////////function for Hours////////////
void DisplayTimeHrs(int Time){        //Display: T1 T2
  int T1=Time/10;
  int T2=Time%10;
  
    if(T1 == 0){
      Control(0);
      zero();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 0){
      Control(1);
      zero();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 1){
      Control(0);
      one();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 1){
      Control(1);
      one();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 2){
      Control(0);
      two();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 2){
      Control(1);
      two();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 3){
      Control(0);
      three();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 3){
      Control(1);
      three();
      delay(wait);
      off();  
      delay(Offwait);
    }
    if(T1 == 4){
      Control(0);
      four();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 4){
      Control(1);
      four();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 5){
      Control(0);
      five();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 5){
      Control(1);
      five();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 6){
      Control(0);
      six();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 6){
      Control(1);
      six();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 7){
      Control(0);
      seven();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 7){
      Control(1);
      seven();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 8){
      Control(0);
      eight();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 8){
      Control(1);
      eight();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T1 == 9){
      Control(0);
      nine();
      delay(wait);
      off();
      delay(Offwait);
    }
    if(T2 == 9){
      Control(1);
      nine();
      delay(wait);
      off();
      delay(Offwait);
    }
}
