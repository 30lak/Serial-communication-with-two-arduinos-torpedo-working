// C++ code
#include<Wire.h>
byte x=0;   // byte to store data
void setup()
{
  Serial.begin(9600);
  Wire.begin(1);       // begin data transfer from master to slave
  Wire.onReceive(receiveEvent); //to receive data from master by declaring function
  
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
}

void loop()
{
  
}
void receiveEvent(int howmany){
   x=Wire.read(); // to read data transmitted from master
  Serial.println(x); // to print the received byte
  if(x==1){
    
    digitalWrite(9,HIGH);  // for clockwise rotation
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);
    
  }
  else if(x==0){
    
      
      digitalWrite(9,HIGH);  // for anticlockwise rotation
      digitalWrite(8,LOW);
      digitalWrite(7,HIGH);
  }
  else if(x==2){
      
      
      digitalWrite(9,LOW);  // for no rotation
      digitalWrite(8,LOW);
      digitalWrite(7,HIGH);
    
  }
}
  



