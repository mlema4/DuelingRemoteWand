#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd[2] =  { LiquidCrystal(12, 8, 5, 4, 3, 2), LiquidCrystal (12,11,5,4,3,2 ) };
struct spells {
  int stupefy = 0;       //5 sec cooldown,  30 hp damage
  int rennervate = 0;    //3 sec cooldown,  reduces 15 damage
  int reducto = 5;       //5 sec cooldown,  25 hp damage
  int protego = 3;       //3 sec cooldown,  reduces 20 damage
  int expelliarmus = 5;  //5 sec cooldown,  10 damage

};
int player1Address = 8;
int player2Address = 9;
typedef struct spells Spells;

struct player{
  Spells spell;
  int health = 100;
  int damage;
  int protect;
};
typedef struct player Player;
Player Player1, Player2;
int timeInterval;
boolean beginning = true;

void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for o tput

  lcd[0].begin(16,2);
  lcd[1].begin(16,2);
  
  lcd[0].setCursor(0,0);
  lcd[0].print("Hello Player 1");
  
  lcd[1].setCursor(0,0);
  lcd[1].print("Hello Player 2"); 
  delay(2000);
}

void loop() {
  boolean start0 = true;
  boolean start1 = true;
  //if(beginning)
      lcd[0].clear();
      lcd[1].clear();
      lcd[0].print("Get Ready!");
      lcd[1].print("Get Ready!");
      delay(1000);
//      lcd[0].clear();
//      lcd[1].clear();
//      lcd[0].print("       3");
//      lcd[1].print("       3");
//      delay(1000);
//      lcd[0].clear();
//      lcd[1].clear();
//      lcd[0].print("       2");
//      lcd[1].print("       2");
//      delay(1000);
      lcd[0].clear();
      lcd[1].clear();
      lcd[0].print("       1");
      lcd[1].print("       1");
      delay(1000);
      lcd[0].clear();
      lcd[1].clear();
      lcd[0].print("      GO!");
      lcd[1].print("      GO!");
      delay(1000);

  
  Wire.requestFrom(player1Address, 7);    // request 6 bytes from slave device #8
   
  while (Wire.available()) {
    if(start0){
      char letter = Wire.read();
   Serial.print(letter);
   if(letter == 'S'){
     // Serial.print("BUG");
      if(Player1.spell.stupefy == 0){
       // Serial.print("BUG2");
       // Player1.spell.stupefy = 5;
        Player1.damage = 30;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("Stupefy!");
        //delay(500);
      }    
      else
      {
        Player1.damage = 0;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("You did nothing");
        //delay(500);
      }
   }
   else if(letter == 'R'){   
      if(Player1.spell.rennervate == 0){
     //   Player1.spell.rennervate = 3;
        Player1.damage = 0;
        Player1.protect = 15;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("Renneervate!");
      }
       else{
        Player1.damage = 0;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("You did nothing");
       }
   }
   
  else if(letter == 'Q'){
      if(Player1.spell.reducto ==0){
     //   Player1.spell.reducto = 5;
        Player1.damage = 25;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("Reducto");

      }
      else {
        Player1.damage = 0;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("You did nothing");       
      }
   }
   
  else if(letter == 'P'){
      if(Player1.spell.protego ==0){
      //  Player1.spell.protego = 3;
        Player1.damage = 0;
        Player1.protect = 20;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("Protego");
      }
      else{
        Player1.damage = 0;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("You did nothing");
      }
   }
   
   else if(letter == 'E'){
      if(Player1.spell.expelliarmus == 0){
      //  Player1.spell.expelliarmus = 5;
        Player1.damage = 10;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("Expelliarmus");
      }
      else{
        Player1.damage = 10;
        Player1.protect = 0;
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("You did nothing");      
      }
   }  
  else{
        lcd[0].clear();
        lcd[0].setCursor(0,0);
        lcd[0].print("You did nothing");
  }
  start0 = false;
    }
  
//  Serial.println(number);
//  while (Wire.available()) { // slave may send less than requested
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
   // Serial.print(Wire.read());
    
  }


  
    Wire.requestFrom(player2Address, 8);    // request 6 bytes from slave device #8

    Serial.println("");
  while (Wire.available()) {
    if(start1){
      char letter = Wire.read();
   Serial.print(letter);
   if(letter == 'S'){
      Serial.print("BUG");
      if(Player2.spell.stupefy == 0){
        Serial.print("BUG2");
      //  Player2.spell.stupefy = 5;
        Player2.damage = 30;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("1Stupefy!");
        //delay(500);
      }    
      else
      {
        Player2.damage = 0;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("You did nothing");
        //delay(500);
      }
   }
   else if(letter == 'R'){   
      if(Player2.spell.rennervate == 0){
       // Player2.spell.rennervate = 3;
        Player2.damage = 0;
        Player2.protect = 15;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("Renneervate!");
      }
       else{
        Player2.damage = 0;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("You did nothing");
       }
   }
   
  else if(letter == 'Q'){
      if(Player2.spell.reducto ==0){
       // Player2.spell.reducto = 5;
        Player2.damage = 25;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("Reducto");
      }
      else {
        Player2.damage = 0;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("You did nothing");       
      }
   }
   
  else if(letter == 'P'){
      if(Player2.spell.protego ==0){
       // Player2.spell.protego = 3;
        Player2.damage = 0;
        Player2.protect = 20;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("Protego");
      }
      else{
        Player2.damage = 0;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("You did nothing");
      }
   }
   
   else if(letter == 'E'){
      if(Player2.spell.expelliarmus == 0){
     //   Player2.spell.expelliarmus = 5;
        Player2.damage = 10;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("Expelliarmus");
      }
      else{
        Player2.damage = 10;
        Player2.protect = 0;
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("You did nothing");      
      }
   }  
  else{
        lcd[1].clear();
        lcd[1].setCursor(0,0);
        lcd[1].print("You did nothing");
  }
  start1 = false;
    }
        char c = Wire.read(); // receive a byte as character
    Serial.print(c);  
  }
//  while (Wire.available()) { // slave may send less than requested
//    char d = Wire.read(); // receive a byte as character
//    Serial.print(d);         // print the character
//   // Serial.print(Wire.read());
//    
//  }
Serial.println();
  delay(5000);
}
