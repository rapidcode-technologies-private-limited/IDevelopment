int pins[]={3,4,5,6,7,8,9,10,11,12,2};
int Noleds=11;
int Position=0;

void setup() {
  for(int i=0;i<Noleds;i++){
    pinMode(pins[i],OUTPUT);  
  }
  for(int i=0;i<Noleds;i++)
   { 
        digitalWrite(pins[i],HIGH);
        
   }
 }

void loop() {
  for(;Position<=10;Position++)
  { 
   for(int i=0;i<Noleds-Position;i++)
   { 
        digitalWrite(pins[i],LOW);
        delay(500);
   }
  
  Position=0;
  for(;Position>=0;Position--)
  { 
   for(int i=0;i<Noleds-Position;i++)
   { 
        digitalWrite(pins[i],HIGH);
        delay(500);
   }
  }
       
}
}
