//Created by Smitty :D
//8-16-17

#include <Arduino.h>
#include <FlexCAN.h>
#include <MCRegIDs.h>
#include <Encoder.h>
#include <Display.h>

//TODO use these later
// #include <SPI.h>
// #include "SdFat.h"


//---------------------------------------------------------------
//declaring encoder class variable and setting up interrupt functions
Encoder knob;

void encoderWrapperA(){
 knob.doEncoderA();
}

void encoderWrapperB(){
 knob.doEncoderB();
}


//---------------------------------------------------------------
//Begin main function
int main(void)
{
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, 1);

  Display screen;

  //attachInterrupt function can't be called in any classes
  //encoder pinA & pinB interrupts
  attachInterrupt(encoderPinA, encoderWrapperA, CHANGE);
  attachInterrupt(encoderPinB, encoderWrapperB, CHANGE);

  while(1)
  {
    // Serial.println(REG_READ);
    // delay(200);

    knob.updateIndex();

    screen.printMenu(knob.getIndex());

  }
  return 0;
}
