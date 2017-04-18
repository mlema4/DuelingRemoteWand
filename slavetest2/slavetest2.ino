#include <Wire.h>
#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;
#define SLAVE_ADDRESS 0x29
byte spell;

void setup() {
  //Wire.begin(SLAVE_ADDRESS);                // join i2c bus with address #8
  Wire.begin(6);
  Wire.onRequest(requestEvent); // register event
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  if(irrecv.decode(&results))
  {
     Serial.print(results.value);
    irrecv.resume();
    Serial.println();
    if(results.value == 16738455 )
    spell = 0;
    Wire.beginTransmission(0x10);
    Wire.write(0x10);
    Wire.endTransmission();
  }
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Serial.println("SENDING");
  Wire.beginTransmission(0x10);
  Wire.write(spell); // respond with message of 6 bytes
  // as expected by master
  Wire.endTransmission();
}
