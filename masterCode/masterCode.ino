#include <Wire.h>
int SlaveDeviceId = 0;
void setup()
{
// Start I²C bus as master
Wire.begin();
}

void loop()
{
// Request data from slave.
Wire.beginTransmission(SlaveDeviceId);
int available = Wire.requestFrom(SlaveDeviceId, (uint8_t)2);

if(available == 2)
{
int receivedValue = Wire.read() << 8 | Wire.read();
Serial.println(receivedValue);
}
else
{
Serial.print("Unexpected number of bytes received: ");
Serial.println(available);
}

if(SlaveDeviceId)
  SlaveDeviceId  = 1;
else
  SlaveDeviceId = 0;
Wire.endTransmission();

delay(1000);
}
