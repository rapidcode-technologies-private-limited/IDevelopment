void setup() {
  // put your setup code here, to run once:
  pinMode(5,OUTPUT);
  pinMode(4,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);

  Serial.begin(9600);
  
  digitalWrite(5, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
 if((digitalRead(4)==0) && (digitalRead(3)==0)){
    digitalWrite(5, LOW);
    Serial.println("Switch Pressed");
}
 else if((digitalRead(4)==0) && (digitalRead(3)==1)){
        digitalWrite(5,LOW);
        Serial.println("Switch Pressed");
      }
      else if((digitalRead(4)==1) && (digitalRead(3)==0)){
              digitalWrite(5, LOW);
              Serial.println("Switch pressed");  
            }
             else if ((digitalRead(4)==1) && (digitalRead(3)==1)){
                      digitalWrite(5,HIGH);
//                      Serial.println("Switch Pressed");
                     } 
}
