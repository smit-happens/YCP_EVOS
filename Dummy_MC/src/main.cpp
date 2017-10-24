/**  A one line description of the class.
 *
 * main.cpp
 * Created 08-16-17 By: Smitty
 *
 * A longer description.
 */

#include <Arduino.h>
#include <Encoder.hpp>
#include <Menu.hpp>
#include <Logger.hpp>
#include <Stepper.hpp>
#include <MotorController.hpp>


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
  knob.pressButton();
  delay(10);
}

// Testing unit Testing
// #ifndef UNIT_TEST

//---------------------------------------------------------------
// Begin main function
int main(void)
{
  // Serial.begin(9600);

  // Object declarations
  // Stepper motor;
  // MotorController mctest;

  // using the builtin LED as a status light
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, 1);

  // attachInterrupt() can only be called in main()
  // encoder pinA & pinB interrupts
  attachInterrupt(encoderPinA, encoderWrapperA, CHANGE);
  attachInterrupt(encoderPinB, encoderWrapperB, CHANGE);
  // encoder button interrupt
  // TODO: fix interrupt logic (make more reliable)
  attachInterrupt(buttonPin, encoderWrapperButton, CHANGE);

  // A pointer to the menu
  BaseMenu* currentMenu = new FirstMenu;

  // Initializing the LCD screen *MUST BE CALLED BEFORE print()*
  currentMenu->initLcd();

  // Variables
  bool extraParams = false;  //get rid of this
  int choice = -1;


  //---------------------------------------------------------------
  // Begin main program loop
  while(1)
  {
    // motor.spin();

    knob.updateIndex(currentMenu->getMenuLength());

    // Call the print method of whichever MenuObject we're using
    // Print its text and the current cursor position
    currentMenu->print(knob.getIndex());

    if(knob.isButtonPressed())
    {
      choice = knob.getIndex();
    }

    // Will return a new object, of the type of the new menu we want
    // extraParams can be filled in with values of things
    BaseMenu* newMenuPointer = currentMenu->getNextMenu(choice, extraParams);

    choice = -1;

    // if pointer is 0, we didn't create a new menu, so keep the current one
    if (newMenuPointer)
    {
      // Clean up the old menu, and not leak memory.
      delete currentMenu;
      // Update the 'current menu' with the new menu just created
      currentMenu = newMenuPointer;
    }
  }

  return 0;
}

// #endif
