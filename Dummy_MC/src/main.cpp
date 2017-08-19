//Created by Smitty :D
//8-16-17

#include <Arduino.h>
#include <FlexCAN.h>
#include <MCRegIDs.h>
#include <string>
#include <vector>
#include <Encoder.h>
#include <Display.h>
// #include <SPI.h>
// #include "SdFat.h"

using namespace std;

#define menuMainLen 8

void encoderWrapperA(void);
void encoderWrapperB(void);

// String menuMain[menuMainLen] {
//   "Smit item1",
//   "Smit item2",
//   "Smit item3",
//   "Smit item4",
//   "Smit item5",
//   "Smit item6",
//   "Smit item7",
//   "Smit item8"
// };

vector<string> menuMain {
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
Display screen;

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

    screen.printMenu(&menuMain, knob.getIndex());

  }
  return 0;
}


void encoderWrapperA(){
 knob.doEncoderA();
}

void encoderWrapperB(){
 knob.doEncoderB();
}
