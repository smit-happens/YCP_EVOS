//Created by Smitty :D
//8-16-17

#include <Arduino.h>
//Custom libraries
#include <Encoder.hpp>
#include <Display.hpp>
#include <Stepper.hpp>
#include <MotorController.hpp>

//TODO implement these later
// #include <SPI.h>
// #include "SdFat.h"


//---------------------------------------------------------------
//Declaring encoder class variable and setting up interrupt functions
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

  //using the builtin LED as a status light
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, 1);

  Display screen;

  Stepper motor;

  MotorController mctest;

  //attachInterrupt() can only be called in main()
  //encoder pinA & pinB interrupts
  attachInterrupt(encoderPinA, encoderWrapperA, CHANGE);
  attachInterrupt(encoderPinB, encoderWrapperB, CHANGE);

  while(1)
  {
    // knob.updateIndex();
    //
    // screen.printMenu(knob.getIndex());
    //
    // motor.spin();

    uint8_t var = mctest.testFunc();
    String sentence = String(var) + " testing";

    Serial.print(sentence);

    delay(1000);

  }
  return 0;
}
