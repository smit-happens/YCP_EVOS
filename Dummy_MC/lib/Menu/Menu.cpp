/**  Class for creating the various menus using OOP
 *
 * Menu.cpp
 * Created 10-01-17 By: Smitty
 *
 * Implemented based off the code found here: https://stackoverflow.com/questions/16852978/navigating-console-menu
 * by user: https://stackoverflow.com/users/2386397/mike-b
 */

#include "Menu.hpp"

//LiquidCrystalFast lcd(RS, RW, Enable, D4, D5, D6, D7);
LiquidCrystalFast lcd(33, 34, 35, 36, 37, 38, 39);


//---------------------------------------------------------------
// Defining the main menu
FirstMenu::FirstMenu(void)
{
  lcd.clear();
  menuText.push_back("About");
  menuText.push_back("Monitor CAN");
  menuText.push_back("Blink LED");
  // menuText.push_back("Start game");
}


/**
 * The only menu able to initialize the LCD
 */
void FirstMenu::initLcd(void)
{
  lcd.begin(20, lcdHeight);
  lcd.clear();
}


/**
 * Defining the pure virtual method
 * @param  choice                Index number user chose
 * @param  iIsQuitOptionSelected Debricated param
 * @return                       BaseMenu pointer
 */
BaseMenu *FirstMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected)
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

    case 2:
    {
      // TODO: remove/modify this
      // iIsQuitOptionSelected = true;

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
  for(uint16_t i = 0; i < lcdHeight && i < menuText.size(); i++)
  {
    lcd.setCursor(0, i);

    //the user display cursor logic
    if(i == index)
      lcd.print(">");
    else
      lcd.print(" ");

    lcd.printf("%i ");
    lcd.print(menuText[i]);
  }
}


/**
 * Defining the CAN menu
 */
SecondMenu::SecondMenu(void)
{
  lcd.clear();
  menuText.push_back("Version 0.0.001?");
  menuText.push_back("By Smitty");
  menuText.push_back("Select any option");
  menuText.push_back("to go back");
}


/**
 * CAN menu option logic
 * @param  choice                Index number user chose
 * @param  iIsQuitOptionSelected Debricated param
 * @return                       BaseMenu pointer
 */
BaseMenu *SecondMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
  // Setting up the pointer, but makin sure it's null (0)
  BaseMenu *newMenu = 0;

  switch (choice)
  {
    case 0:
    {
      // Creating a new menu object
      newMenu = new FirstMenu;
    }
    break;

    case 1:
    {
      // Creating a new menu object
      newMenu = new FirstMenu;
    }
    break;

    case 2:
    {
      // Creating a new menu object
      newMenu = new FirstMenu;
    }
    break;

    case 3:
    {
      // Creating a new menu object
      newMenu = new FirstMenu;
    }
    break;

    default:
      // Do nothing
    break;
  }

  // returning menu pointer back
  return newMenu;
}


/**
 * Printing the menu to the LCD
 * @param index Current index the user is at
 */
void SecondMenu::print(int index)
{
  for(uint16_t i = 0; i < lcdHeight && i < menuText.size(); i++)
  {
    lcd.setCursor(0, i);

    //the user display cursor logic
    if(i == index)
      lcd.print(">");
    else
      lcd.print(" ");

    lcd.printf("%i ");
    lcd.print(menuText[i]);
  }
}
