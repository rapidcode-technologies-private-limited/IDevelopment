int Position=11;
int Noleds;
int pins[]={2,3,4,5,6,7,8,9,10,11,13};
void setup() {
  int i;
  for(i=0;i<11;i++)
  pinMode(i,OUTPUT);
 
}

void loop()   {
  for(;Position<=10;Position++)
  {
   for(int i=0;i<Noleds-Position;i++)
   {
    digitalWrite(pins[i],HIGH);
    delay(500);
   }
  }
   Position=0;
   for(;Position>=0;Position--)
   {
    for(int i=0;Noleds-Position;i++)
  {
    digitalWrite(pins[i],LOW);
    delay(500);
}

}
}
