#include <Wire.h>
#include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;
byte spell;

void setup() {

  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  




  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value); // Print the Serial 'results.value'
      irrecv.resume();   // Receive the next value
    }
  if (results.value == 16738455)
    Wire.write("HEllO"); // respond with message of 6 bytes
  else
    Wire.write("NOTHING");
  // as expected by master
}
