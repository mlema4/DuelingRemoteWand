#include <Wire.h>
#include <IRremote.h>

const byte AnalogueInputPin = 0;
const byte SlaveDeviceId = 2;
int LED = 13;    // LED pin  
boolean LEDon = true; // initializing LEDon as true

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
// Start I²C bus as a slave
Wire.begin(SlaveDeviceId);
irrecv.enableIRIn(); // Start the receiver
// Set the callback to call when data is requested.
Wire.onRequest(requestCallback);
  //Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
   
//  if (irrecv.decode(&results)) 
//    {
//      
//      irrecv.resume();   // Receive the next value
//    }
//  
//   if (results.value == 16738455)  // this is where you put in your IR remote button #
//     {
//       if (LEDon == true)   // is LEDon equal to true? 
//         {
//           LEDon = false;   
//           digitalWrite(LED, HIGH);
//           delay(100);      // keeps the transistion smooth
//            
//         }
//         
//        else
//          {
//            LEDon = true;
//            digitalWrite(LED, LOW);
//            delay(100);
//            
//          }
//          
//     }
}

void requestCallback()
{


  if (irrecv.decode(&results)) 
    {
      
      irrecv.resume();   // Receive the next value
    } 
  
   if (results.value == 16738455)  // this is where you put in your IR remote button #
     {
       if (LEDon == true)   // is LEDon equal to true? 
         {
           LEDon = false;   
           digitalWrite(LED, HIGH);
           delay(100);      // keeps the transistion smooth
            
         }
         
        else
          {
            LEDon = true;
            digitalWrite(LED, LOW);
            delay(100);
            
          }
          
     }
// Contrived example – transmit a value from an analogue pin.
int input = analogRead(AnalogueInputPin);

// To send multiple bytes from the slave,
// you have to fill your own buffer and send it all at once.
uint8_t buffer[2];
buffer[0] = input >> 8;
buffer[1] = input & 0xff;
Wire.write(results.value);
}
