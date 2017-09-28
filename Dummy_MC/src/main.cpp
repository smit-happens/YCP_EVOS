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

#define STEPPER_COIL_PIN_A 29
#define STEPPER_COIL_PIN_B 30
#define STEPPER_COIL_PIN_C 31
#define STEPPER_COIL_PIN_D 32

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

  //using the builtin LED as a status light
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, 1);

  pinMode(STEPPER_COIL_PIN_A, OUTPUT);
  pinMode(STEPPER_COIL_PIN_B, OUTPUT);
  pinMode(STEPPER_COIL_PIN_C, OUTPUT);
  pinMode(STEPPER_COIL_PIN_D, OUTPUT);

  digitalWriteFast(STEPPER_COIL_PIN_A, 1);
  digitalWriteFast(STEPPER_COIL_PIN_B, 1);
  digitalWriteFast(STEPPER_COIL_PIN_C, 1);
  digitalWriteFast(STEPPER_COIL_PIN_D, 1);

  Display screen;

  //attachInterrupt function can't be called in any classes
  //encoder pinA & pinB interrupts
  attachInterrupt(encoderPinA, encoderWrapperA, CHANGE);
  attachInterrupt(encoderPinB, encoderWrapperB, CHANGE);

  //Setting the stepper's inital state
  digitalWriteFast(STEPPER_COIL_PIN_B, 0);
  digitalWriteFast(STEPPER_COIL_PIN_D, 0);

  // while(1)
  // {
  //   // Serial.println(REG_READ);
  //   // delay(200);
  //
  //   // knob.updateIndex();
  //   //
  //   // screen.printMenu(knob.getIndex());
  //
  // }
  while(1)
  {
    // Serial.println("Looping stepper");

    knob.updateIndex();

    screen.printMenu(knob.getIndex());

    // digitalWriteFast(STEPPER_COIL_PIN_D, 1);
    // // delay(2);
    // digitalWriteFast(STEPPER_COIL_PIN_C, 0);
    // // delay(100);
    // delay(3);
    //
    // digitalWriteFast(STEPPER_COIL_PIN_B, 1);
    // // delay(2);
    // digitalWriteFast(STEPPER_COIL_PIN_A, 0);
    // // delay(100);
    // delay(3);
    //
    // digitalWriteFast(STEPPER_COIL_PIN_C, 1);
    // // delay(2);
    // digitalWriteFast(STEPPER_COIL_PIN_D, 0);
    // // delay(100);
    // delay(3);
    //
    // digitalWriteFast(STEPPER_COIL_PIN_A, 1);
    // // delay(2);
    // digitalWriteFast(STEPPER_COIL_PIN_B, 0);
    // // delay(100);
    // delay(3);
  }
  return 0;
}
