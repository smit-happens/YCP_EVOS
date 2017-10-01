/**  A one line description of the class.
 *
 * main.cpp
 * Created 08-16-17 By: Smitty
 *
 * A longer description.
 */

#include <Arduino.h>
#include <Encoder.hpp>
#include <Display.hpp>
#include <Menu.hpp>
#include <Stepper.hpp>
#include <MotorController.hpp>

//TODO implement these later
// #include <SPI.h>
// #include "SdFat.h"


//---------------------------------------------------------------
//Declaring encoder object variable and setting up interrupt functions
Encoder knob;

void encoderWrapperA(){
 knob.doEncoderA();
}

void encoderWrapperB(){
 knob.doEncoderB();
}

void encoderWrapperButton(){
  knob.doButtonPress();
}


//---------------------------------------------------------------
//Begin main function
int main(void)
{
  // Serial.begin(9600);

  //object declarations
  Display screen;
  // Stepper motor;
  MotorController mctest;

  //using the builtin LED as a status light
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, 1);

  //attachInterrupt() can only be called in main()
  //encoder pinA & pinB interrupts
  attachInterrupt(encoderPinA, encoderWrapperA, CHANGE);
  attachInterrupt(encoderPinB, encoderWrapperB, CHANGE);

  BaseMenu* aCurrentMenu = new FirstMenu;
  String sentence = aCurrentMenu->printText();

  // uint8_t var = mctest.testFunc();
  // String sentence = String(var) + " testing\n";
  //
  // screen.print(sentence);

  while(1)
  {
    knob.updateIndex();

    screen.printMenu(knob.getIndex());

    // motor.spin();



    delay(1000);

  }
  return 0;
}
