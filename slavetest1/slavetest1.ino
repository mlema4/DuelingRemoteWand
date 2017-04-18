#include <Wire.h>
#include <IRremote.h>


int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;


void setup() {
  Wire.begin(1);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  irrecv.enableIRIn();
}

void loop() {
  if(irrecv.decode(&results))
  {
    
    irrecv.resume();
  }
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(results.value); // respond with message of 6 bytes
  // as expected by master
}
