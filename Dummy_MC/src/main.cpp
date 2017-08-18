//Created by Smitty :D
//8-16-17

#include <Arduino.h>
#include <FlexCAN.h>
#include <MCRegIDs.h>
#include <LiquidCrystalFast.h>
#include <array>
#include <string>
using namespace std;

#define encoderPinA  17
#define encoderPinB  18
#define lcdHeight 4

volatile int8_t encoderPos = 0;

boolean A_set = false;
boolean B_set = false;

LiquidCrystalFast lcd(33, 34, 35, 36, 37, 38, 39);
//LiquidCrystalFast lcd(RS, RW, Enable, D4, D5, D6, D7);

array <String, 8> menuMain {
  "Smit item1",
  "Smit item2",
  "Smit item3",
  "Smit item4",
  "Smit item5",
  "Smit item6",
  "Smit item7",
  "Smit item8",
};

void doEncoderA(void);
void doEncoderB(void);


int main(void)
{
  // Serial.begin(9600);
  lcd.begin(20, 4);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);

  // encoder pinA interrupt
  attachInterrupt(encoderPinA, doEncoderA, CHANGE);
  // encoder pinB interrupt
  attachInterrupt(encoderPinB, doEncoderB, CHANGE);

  digitalWrite(LED_BUILTIN, 1);
  lcd.clear();

  int cw = 0, ccw = 0;
  int index = 0;
  bool change = false;

  //displaying initial menu so lcd doesn't start up blank
  for(uint16_t i = 0; i < lcdHeight; i++) {
    lcd.setCursor(0, i);

    //the user display cursor logic
    if(i == index)
      lcd.print(">");
    else
      lcd.print(" ");

    lcd.print(i);
    lcd.print(" ");
    lcd.print(menuMain[i]);
  }

  while(1)
  {
    // Serial.println(REG_READ);
    if (0 > encoderPos)
    {
      cw++;
      ccw = 0;
      change = true;
    }
    else if(0 < encoderPos)
    {
      ccw++;
      cw = 0;
      change = true;
    }

    //doesn't excecute if encoder hasn't turned
    if(change == true)
    {
      //reset values so this condition isn't executed repeatedly
      encoderPos = 0;
      change = false;

      //notches are at every 4 steps on the encoder
      //checks every 4 steps to move up/down a menu item
      if(cw >= 4)
      {
        cw = 0;
        index--;
      }
      else if(ccw >= 4)
      {
        ccw = 0;
        index++;
      }

      //updating the cursor position on the display
      for(uint16_t i = 0; i < lcdHeight; i++) {
        lcd.setCursor(0, i);

        //the user display cursor logic
        if(i == index)
          lcd.print(">");
        else
          lcd.print(" ");

        lcd.print(i);
        lcd.print(" ");
        lcd.print(menuMain[i]);
      }
    }
  } //end while(1) loop
  return 0;
}


// Interrupt on A changing state
void doEncoderA()
{
  // Test transition
  A_set = digitalRead(encoderPinA) == HIGH;
  // and adjust counter + if A leads B
  encoderPos = (A_set != B_set) ? +1 : -1;
}


// Interrupt on B changing state
void doEncoderB()
{
  // Test transition
  B_set = digitalRead(encoderPinB) == HIGH;
  // and adjust counter + if B follows A
  encoderPos = (A_set == B_set) ? +1 : -1;
}
