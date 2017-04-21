#include <LiquidCrystal.h>

LiquidCrystal lcd[2] = { LiquidCrystal(12, 8, 5, 4, 3, 2),LiquidCrystal(12, 11, 5, 4, 3, 2) };

void setup() {
// set up the LCD's number of columns and rows:
lcd[0].begin(16, 2);
lcd[1].begin(16, 2);
lcd[0].setCursor(0, 0);

lcd[0].print("Hello");
lcd[1].setCursor(0, 0);
lcd[1].print("World!");
}

void loop()
{

 
}

