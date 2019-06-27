#define LedCount 11
int Led[LedCount]={3,4,5,6,7,8,9,10,11,12,2};

void setup() {

  for(int i=0;i<LedCount;i++){
    pinMode(Led[i],OUTPUT);     
  }
  Serial.begin(9600);
  for(int i=0;i<LedCount;i++){
    digitalWrite(Led[i],HIGH);
    delay(200);
  }
}

void loop() {
    // put your main code here, to run repeatedly:
  int data=0;
  for(int j=0;j<10;j++){
    data = data + analogRead(A0);
    delay(10);
  }
  data =data/10;
  
  Serial.println(data);
  
  if(data<=100)
  {
    for(int i=0;i<LedCount;i++){
      digitalWrite(Led[i],LOW);
    }
  }
  ////////////////////////////////////////////////
  if(data<=250 && data>100 )
  { 
    for(int i=0;i<(LedCount-2);i++){
      digitalWrite(Led[i],LOW);
    }
  
    for(int i=0;i<(LedCount-8);i++){
      digitalWrite(Led[LedCount-1-i],HIGH);
    }
  }
  ////////////////////////////////////////////////
  if(data<=350 && data>250 )
  {
    for(int i=0;i<(LedCount-3);i++){
      digitalWrite(Led[i],LOW);
    }
  
    for(int i=0;i<(LedCount-7);i++){
      digitalWrite(Led[LedCount-1-i],HIGH);
    }
  }
  ////////////////////////////////////////////////
  if(data<=450 && data>350 )
  {
    for(int i=0;i<(LedCount-4);i++){
      digitalWrite(Led[i],LOW);
    }
  
    for(int i=0;i<(LedCount-6);i++){
      digitalWrite(Led[LedCount-1-i],HIGH);
    }
  }
  /////////////////////////////0///////////////////
  if(data<=550 && data>450 )
  {
    for(int i=0;i<(LedCount-5);i++){
      digitalWrite(Led[i],LOW);
    }
  
    for(int i=0;i<(LedCount-5);i++){
      digitalWrite(Led[LedCount-1-i],HIGH);
    }
  }
  ////////////////////////////////////////////////
  if(data<=700 && data>550 )
  {
    for(int i=0;i<(LedCount-6);i++){
      digitalWrite(Led[i],LOW);
    }
  
    for(int i=0;i<(LedCount-4);i++){
      digitalWrite(Led[LedCount-1-i],HIGH);
    }
  }
  ///////////////////////////////////////////////
  if(data<=800 && data>700 )
  {
    for(int i=0;i<(LedCount-7);i++){
      digitalWrite(Led[i],LOW);
    }
  
    for(int i=0;i<(LedCount-3);i++){
      digitalWrite(Led[LedCount-1-i],HIGH);
    }
  }
  //////////////////////////////////////////////
  if(data<=950 && data>800 )
  {
    for(int i=0;i<(LedCount-8);i++){
      digitalWrite(Led[i],LOW);
    }
  
    for(int i=0;i<(LedCount-2);i++){
      digitalWrite(Led[LedCount-1-i],HIGH);
    }
  }
  ///////////////////////////////////////////////
  if(data<=1000 && data>950 )
  {
    for(int i=0;i<(LedCount);i++){
      digitalWrite(Led[i],HIGH);
    }
  }
}
