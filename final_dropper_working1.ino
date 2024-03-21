// C++ code
#include <Wire.h>

byte val = 0;  // value used to transmit Slave code
byte d = 2;
String name="";  // Variable to store input String
String aim="";
void setup() {
  Serial.begin(9600); 
  Wire.begin(); // Join I2C bus
  Serial.println("Enter dropper on or off");
   while(Serial.available()==0){
                             // to store dropper on or off info
   };
   aim=Serial.readString();
}

void loop() {
 
 
 
 while(aim=="dropper on"){
    Serial.println("Enter dropper state");
  while(Serial.available()==0){
                                // Wait for Serial input data
  };
  name=Serial.readString();
  
    Wire.beginTransmission(1);  // Transmit to device number 1
  if(name=="forward"){
    Wire.write(val+1);             // Sends value of 1 byte 
    Wire.endTransmission(); // Stop transmitting
 
    
                         
  }
  else if(name=="reverse"){
    
    Wire.write(val);               // Sends value of 0 byte
    Wire.endTransmission();      // Stop transmitting
  }
    
  else if(name=="dropper off"){
    
    Wire.write(d);         // Sends value of 2 byte
    Wire.endTransmission();   // Stop transmitting
      
  }
  
 }
 Wire.beginTransmission(1);
 Wire.write(d);            // remain the dropper off
 Wire.endTransmission();
   
    
    delay(1000);
  
    val=0;  
}
