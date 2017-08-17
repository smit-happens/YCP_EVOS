//Created by Smitty :D
//8-16-17

#include <Arduino.h>
#include <FlexCAN.h>
#include <MCRegIDs.h>
#include <LiquidCrystalFast.h>

#define encoderPinA  17
#define encoderPinB  18

volatile int8_t encoderPos = 0;

boolean A_set = false;
boolean B_set = false;

void doEncoderA(void);
void doEncoderB(void);

LiquidCrystalFast lcd(33, 34, 35, 36, 37, 38, 39);
//LiquidCrystalFast lcd(RS, RW, Enable, D4, D5, D6, D7);

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
  int up = 1, down = 1;
  bool change = true;

  lcd.setCursor(0, 0);
  lcd.print("cw=  ");
  lcd.setCursor(9, 0);
  lcd.print("goUp=  ");
  lcd.setCursor(0, 1);
  lcd.print("ccw= ");
  lcd.setCursor(9, 1);
  lcd.print("goDwn= ");

  while(1) {
    // Serial.println(REG_READ);
    if (0 > encoderPos) {
      cw++;
      ccw = 0;
      change = true;
    }
    else if(0 < encoderPos) {
      ccw++;
      cw = 0;
      change = true;
    }
    else
      change = false;

    //doesn't excecute if encoder hasn't turned
    if(change == true) {
      encoderPos = 0;

      //notches are at every 4 steps on the encoder
      //checks every 4 steps to move up/down a menu item
      if(cw >= 4) {
        cw = 0;
        ccw = 0;
        lcd.setCursor(9, 0);
        lcd.print("goUp=  ");
        lcd.print(up++);
      }
      else if(ccw >= 4) {
        ccw = 0;
        cw = 0;
        lcd.setCursor(9, 1);
        lcd.print("goDwn= ");
        lcd.print(down++);
      }

      lcd.setCursor(0, 0);
      lcd.print("cw=  ");
      lcd.println(cw);
      lcd.print("ccw= ");
      lcd.print(ccw);
    }
  }
  return 0;
}


// Interrupt on A changing state
void doEncoderA() {
  // Test transition
  A_set = digitalRead(encoderPinA) == HIGH;
  // and adjust counter + if A leads B
  encoderPos = (A_set != B_set) ? +1 : -1;
}


// Interrupt on B changing state
void doEncoderB() {
  // Test transition
  B_set = digitalRead(encoderPinB) == HIGH;
  // and adjust counter + if B follows A
  encoderPos = (A_set == B_set) ? +1 : -1;
}
