//***************************************************************
// Display.cpp
//
#include "Display.h"


//---------------------------------------------------------------
//Display class constructor
Display::Display(void)
{
  lcd.begin(20, lcdHeight);

  lcd.clear();

}


//---------------------------------------------------------------
//prints out menu on lcd based on index given
void printMenu(String * menu, int index)
{
  //displaying initial menu so lcd doesn't start up blank
  for(uint16_t i = 0; i < lcdHeight; i++) {
    lcd.setCursor(0, i);

    //the user display cursor logic
    if(i == index)
      lcd.print(">");
    else
      lcd.print(" ");

    lcd.print(i);
    lcd.print(" ");
    lcd.print(menu[i]);
  }
}
