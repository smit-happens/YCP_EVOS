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


//---------------------------------------------------------------
// FirstMenu should be the only menu able to initialize the LCD
void FirstMenu::initLcd(void)
{
  lcd.begin(20, lcdHeight);
  lcd.clear();
}


//---------------------------------------------------------------
// This is defining the pure virtual method above
BaseMenu *FirstMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected)
{
  // Setting up the pointer here, but making sure it's null (0)
  BaseMenu *newMenu = 0;

  switch (choice)
  {
    case 0:
    {
      // We're creating our new menu object here
      newMenu = new SecondMenu;
      // Serial.println("ABOUT!");
    }
    break;

    case 1:
    {
      // We're creating our new menu object here
      newMenu = new SecondMenu;
      // Serial.println("MONITOR CAN!");
    }
    break;

    case 2:
    {
      // Selected quit! Update the bool we got as input
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

//---------------------------------------------------------------
// Printing the menu to the LCD
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


//---------------------------------------------------------------
// Defining the CAN menu
SecondMenu::SecondMenu(void)
{
  lcd.clear();
  menuText.push_back("Version 0.0.001?");
  menuText.push_back("By Smitty");
  menuText.push_back("Select any option");
  menuText.push_back("to go back");
}


//---------------------------------------------------------------
// CAN menu option logic
BaseMenu *SecondMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
  // We're setting up the pointer here, but makin sure it's null (0)
  BaseMenu *newMenu = 0;

  switch (choice)
  {
    case 0:
    {
      // We're creating our new menu object here
      newMenu = new FirstMenu;
    }
    break;

    case 1:
    {
      // We're creating our new menu object here
      newMenu = new FirstMenu;
    }
    break;

    case 2:
    {
      // We're creating our new menu object here
      newMenu = new FirstMenu;
    }
    break;

    case 3:
    {
      // We're creating our new menu object here
      newMenu = new FirstMenu;
    }
    break;

    default:
      // Do nothing
    break;
  }

  // returning menu back
  return newMenu;
}


//---------------------------------------------------------------
// Printing the menu to the LCD
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
