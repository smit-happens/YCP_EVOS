//Created by Smitty :D
//8-16-17

#include <Arduino.h>
#include <FlexCAN.h>
#include <MCRegIDs.h>
#include <string>
#include <Encoder.h>
#include <Display.h>
// #include <SPI.h>
// #include "SdFat.h"

using namespace std;

#define menuMainLen 8

void encoderWrapperA(void);
void encoderWrapperB(void);

String menuMain[menuMainLen] {
  "Smit item1",
  "Smit item2",
  "Smit item3",
  "Smit item4",
  "Smit item5",
  "Smit item6",
  "Smit item7",
  "Smit item8"
};

Encoder knob;

int main(void)
{
  // Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 1);

  // encoder pinA interrupt
  attachInterrupt(encoderPinA, encoderWrapperA, CHANGE);
  // encoder pinB interrupt
  attachInterrupt(encoderPinB, encoderWrapperB, CHANGE);

  while(1)
  {
    // Serial.println(REG_READ);

    knob.updateIndex();
    //move to encoder class
    // if (0 > encoderPos)
    // {
    //   cw++;
    //   ccw = 0;
    //   change = true;
    // }
    // else if(0 < encoderPos)
    // {
    //   ccw++;
    //   cw = 0;
    //   change = true;
    // }
    //end move to encoder class

    //doesn't excecute if encoder hasn't turned
    // if(change == true)
    // {
    //   //reset values so this condition isn't executed repeatedly
    //   encoderPos = 0;
    //   change = false;
    //
    //   //notches are at every 4 steps on the encoder
    //   //checks every 4 steps to move up/down a menu item
    //   if(cw >= 4)
    //   {
    //     cw = 0;
    //     index--;
    //   }
    //   else if(ccw >= 4)
    //   {
    //     ccw = 0;
    //     index++;
    //   }
    // }
  } //end while(1) loop
  return 0;
}


void encoderWrapperA(){
 knob.doEncoderA();
}

void encoderWrapperB(){
 knob.doEncoderB();
}
