#include <Wire.h>

const byte AnalogueInputPin = 0;
const byte SlaveDeviceId = 1;

void setup()
{
// Start I²C bus as a slave
Wire.begin(SlaveDeviceId);
// Set the callback to call when data is requested.
Wire.onRequest(requestCallback);
}

void loop()
{
}

void requestCallback()
{
// Contrived example – transmit a value from an analogue pin.
int input = analogRead(AnalogueInputPin);

// To send multiple bytes from the slave,
// you have to fill your own buffer and send it all at once.
uint8_t buffer[2];
buffer[0] = input >> 8;
buffer[1] = input & 0xff;
Wire.write(buffer, 2);
}
