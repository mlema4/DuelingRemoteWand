/*This slave will use the black wand
 * Black Wand           White Wand
0 - 16738455            0 - 16738455
1 - 16724175            1 - 16724175
2 - 16718055            2 - 16718055
3 - 16743045            3 - 16743045
4 - 16716015            4 - 16716015
5 - 16726215            5 - 16726215
6 - 16734855            6 - 16734855
7 - 16728765            7 - 16728765
8 - 16730805            8 - 16730805
9 - 16732845            9 - 16732845
power  - 16753245       ch- 16753245
vol+  16736925          ch  16736925
func - 16769565         ch+16769565
rewind - 16720605       prev - 16720605
play - 16712445         next - 16712445
forward - 16761405        play - 16761405
down - 16769055         vol- 16769055
vol- 16754775           vol+ 16754775
up - 16748655           EQ - 16748655
EQ - 16750695         100+  16750695
st - 16756815           200+ 16756815
 */
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
  delay(1000);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value); // Print the Serial 'results.value'
      irrecv.resume();   // Receive the next value
    }
  if (results.value == 16738455) //16738455 is button 0
    Wire.write("Stupefy"); // respond with message of 6 bytes
  else if (results.value == 16724175) 
    Wire.write("Rennervate");
  else if (results.value == 16718055) 
    Wire.write("QReducto");
  else if (results.value == 16743045) 
    Wire.write("Protego");
  else if (results.value ==  16716015) 
    Wire.write("Expelliarmus");
  else     
    Wire.write("1nothing");
  // as expected by master
}
