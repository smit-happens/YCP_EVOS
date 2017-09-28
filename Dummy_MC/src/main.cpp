//Created by Smitty :D
//8-16-17

#include <Arduino.h>
#include <FlexCAN.h>
#include <MCRegIDs.h>
#include <Encoder.h>
#include <Display.h>
#include <Stepper.h>

//TODO use these later
// #include <SPI.h>
// #include "SdFat.h"

//---------------------------------------------------------------
// declaring encoder class variable and setting up interrupt functions
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
  // Serial.begin(9600);
  // Serial.println(REG_READ);

  //using the builtin LED as a status light
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, 1);

  Display screen;

  Stepper motor;

  //attachInterrupt function can't be called in any classes
  //encoder pinA & pinB interrupts
  attachInterrupt(encoderPinA, encoderWrapperA, CHANGE);
  attachInterrupt(encoderPinB, encoderWrapperB, CHANGE);

  while(1)
  {
    knob.updateIndex();

    screen.printMenu(knob.getIndex());

    motor.spin();
  }
  return 0;
}
