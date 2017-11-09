/**  Class for managing the Display and creating menus using OOP
 *
 * DisplayController.cpp
 * Created 10-01-17 By: Smitty
 *
 * Implemented based off the code found here: https://stackoverflow.com/questions/16852978/navigating-console-menu
 * by user: https://stackoverflow.com/users/2386397/mike-b
 */

#include "DisplayController.hpp"

// pin 17 - Serial data out (SID)
// pin 39 - Serial clock out (SCLK)
// pin 38 - Data/Command select (RS or A0)
// pin 37 - LCD reset (RST)
// pin 36 - LCD chip select (CS)
ST7565 glcd(17, 39, 38, 37, 36);


/**************************************************************************
 * STEPS TO MODIFY AND TEST THIS CLASS                                    *
 * TODO: 1. make one main menu                                            *
 * TODO: 2. wire up the RGB backlight                                     *
 * TODO: 3. implement a basic notification the goes away untouched        *
 * TODO: 4. implement some alert-looking notification that is persistent  *
 *          until some condition is met                                   *
 **************************************************************************/


/**
 *  Main menu constructor
 */
FirstMenu::FirstMenu(void)
{

}


/**
 * The only menu able to initialize the LCD
 */
void FirstMenu::initLcd(void)
{
  // initialize and set the contrast to 0x18
  glcd.begin(0x18);

  // draw a string at location (0,0)
  glcd.drawstring(0, 0, (char*)"Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation");
  glcd.display();
}


/**
 * Defining the pure virtual method
 * @param  choice                Index number user chose
 * @return                       BaseMenu pointer
 */
BaseMenu *FirstMenu::getNextMenu(int choice)
{
  // Setting up the pointer, but making sure it's null (0)
  BaseMenu *newMenu = 0;

  switch (choice)
  {
    case 0:
    {
      // Creating a new menu object
      newMenu = new SecondMenu;
      // Serial.println("ABOUT!");
    }
    break;

    case 1:
    {
      // Creating a new menu object
      newMenu = new SecondMenu;
      // Serial.println("MONITOR CAN!");
    }
    break;

    default:
    {
      // Do nothing
    }
    break;
  }

  // returning menu back
  return newMenu;
}


/**
 * Printing the menu to the LCD
 * @param index Current index the user is at
 */
void FirstMenu::print(int index)
{
  // for(uint16_t i = 0; i < lcdHeight && i < menuText.size(); i++)
  // {
  //   lcd.setCursor(0, i);
  //
  //   //the user display cursor logic
  //   if(i == index)
  //     lcd.print(">");
  //   else
  //     lcd.print(" ");
  //
  //   lcd.printf("%i ");
  //   lcd.print(menuText[i]);
  // }
}
