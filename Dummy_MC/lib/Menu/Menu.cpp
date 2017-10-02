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
  menuText = "Main Menu\n"
             "1 - Start game\n"
             "2 - Options\n"
             "3 - Quit\n";
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
    case 1:
    {
      // We're creating our new menu object here, and will send it back to the main function below
      newMenu = new SecondMenu;
    }
    break;

    case 2:
    {
      // We're creating our new menu object here, and will send it back to the main function below
      newMenu = new SecondMenu;
    }
    break;

    case 3:
    {
      // Selected quit! Update the bool we got as input
      iIsQuitOptionSelected = true;
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
  // implement code
  char menuMain[8][18] {
    "About~",
    "Send CAN message~",
    "Smit item3~",
    "Smit item4~",
    "Smit item5~",
    "Smit item6~",
    "Smit item7~",
    "Smit item8~"
  };

  //displaying initial menu so lcd doesn't start up blank
  for(uint16_t i = 0; i < lcdHeight; i++)
  {
    lcd.setCursor(0, i);

    //the user display cursor logic
    if(i == index)
      lcd.print(">");
    else
      lcd.print(" ");

    lcd.printf("%i ");
    for(int j = 0; j<10; j++)
    {
      if(menuMain[i][j] != '~')
        lcd.write(menuMain[i][j]);
      else
        break;
    }
  }
}


//---------------------------------------------------------------
// Defining the CAN menu
SecondMenu::SecondMenu(void)
{
  menuText = "CAN Menu\n"
             "0: Back to main menu\n"
             "1 - Display CAN messages"
             "2 - dafuq?"
             "2 - dafuq?";
}


//---------------------------------------------------------------
// CAN menu option logic
BaseMenu *SecondMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
  BaseMenu *newMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

  switch (choice)
  {
    case 1:
      newMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
    break;

    case 2:
      newMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
    break;

    default:
      // Do nothing
    break;
  }

  // returning menu back
  return newMenu;
}
