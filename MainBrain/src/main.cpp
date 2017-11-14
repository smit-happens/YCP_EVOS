/**  A one line description of the class.
 *
 * main.cpp
 * Created 11-06-17 By: Smitty
 *
 * A longer description.
 */

 // Testing unit Testing
 #ifndef UNIT_TEST

#include <Arduino.h>
#include <EncoderHandler.hpp>
#include <DisplayController.hpp>
#include <Logger.hpp>
#include <UnitekController.hpp>
#include <WatchdogHandler.hpp>

enum VehicleState 
{
  Startup,
  Standby,
  Drive,
  Shutdown,
  Error
};

//---------------------------------------------------------------
// Begin main function
int main(void)
{
  // Serial.begin(9600);

  // Object declarations
  // UnitekController mctest;
  WatchdogHandler puppy;
  VehicleState currentState = Startup;    //If Teensy is turning on, it's in the Startup state

  // using the builtin LED as a status light
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWriteFast(LED_BUILTIN, 1);

  // A pointer to the menu
  BaseMenu* currentMenu = new FirstMenu;

  // Initializing the LCD screen *MUST BE CALLED BEFORE print()*
  currentMenu->initLcd();

  // Variables
  uint16_t globalEventFlags = 0;
  uint16_t localEventFlags = 0;

  //---------------------------------------------------------------
  // Begin main program loop
  while(1)
  {

    //volatile operations
    noInterrupts();
    localEventFlags = globalEventFlags;
    globalEventFlags = 0;
    interrupts();

    
    switch(currentState)
    {
      case Startup:
        //TODO: Finish this state
        //Teensy SelfTest     //What would this even be?
        //SD card initialize
        //subsystem checks (log status of each)
          //Dashboard
          //LCD (boot logo)
          //TS master switch through BMS/BSPD
          //Orion
          //Unitek
          //Cooling system
            //Alert: Turn cooling on
        //Notification: All systens go. Ready to Precharge

      break;

      
      // Enter this state from Startup once precharge button is pressed
      case Standby:
        //TODO: Finish this state
        //CAN message sent to MC to start precharging
        

      break;


      case Drive:
        //TODO: Finish this state

      break;


      case Shutdown:
        //TODO: Finish this state

      break;


      case Error:
        //TODO: Finish this state

      break;
    }
  }

  return 0;
}

#endif
