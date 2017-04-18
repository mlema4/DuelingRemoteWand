#include <Wire.h>

void setup() {
  Wire.begin(0x10);        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output
}

void loop() {
  //Serial.println("BEGIN");
//  if (Wire.requestFrom(0x29, 12, false)) // request 6 bytes from slave device #2
//    Serial.println("ABOUT TO ENTER WHILE");
//  else
//    Serial.println("NOTHING");
 
 // Wire.beginTransmission(0x29);
 // Wire.write(0x00);
 // Wire.endTransmission();
  //Wire.requestFrom(0x29,1);
Wire.requestFrom(6,10);
  
  //for (int i = 0; i < 3; i++)
 // {
 while(Wire.available())
 {
//  byte spell = Wire.read();
    Serial.println(Wire.read());
  //}

 }
//  while (Wire.available()) {
//    // slave may send less than requested
//    char c = Wire.read(); // receive a byte as character
//    Serial.print("HELLO");    // print the character
//    Serial.println("While looping");
//  }

  delay(1000);
  //Serial.print("Looping");
}




