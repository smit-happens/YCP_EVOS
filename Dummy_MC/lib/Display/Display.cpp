/**  A one line description of the class.
 *
 * Display.cpp
 * Created XX-XX-17 By: Smitty
 *
 * A longer description.
 */

#include "Display.hpp"


//LiquidCrystalFast lcd(RS, RW, Enable, D4, D5, D6, D7);
LiquidCrystalFast lcd(33, 34, 35, 36, 37, 38, 39);

char menuMain[8][18] {
  "Smit item1~",
  "Smit item2~",
  "Smit item3~",
  "Smit item4~",
  "Smit item5~",
  "Smit item6~",
  "Smit item7~",
  "Smit item8~"
};

// const char *menuMain =
//   "Welcome to MC_SIM!\n"
//   "Select an option\n"
//   "1: Send a CAN message\n"
//   "2: Blink an LED\n";

//---------------------------------------------------------------
//Display class constructor
Display::Display(void)
{
  lcd.begin(20, lcdHeight);
  lcd.clear();
}


//---------------------------------------------------------------
//Print a given String to the display
void Display::print(String text)
{
  lcd.clear();
  lcd.print(text);
}


//---------------------------------------------------------------
//prints out menu on lcd based on index given
void Display::printMenu(int index)
{
  //TODO code for different menus

  //displaying initial menu so lcd doesn't start up blank
  for(uint16_t i = 0; i < lcdHeight; i++) {
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
