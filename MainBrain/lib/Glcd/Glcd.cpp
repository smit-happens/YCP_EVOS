/**  Class for managing the Display and creating menus using OOP
 *
 * Glcd.cpp
 * Created 10-01-17 By: Smitty
 *
 * Implemented based off the code found here: https://stackoverflow.com/questions/16852978/navigating-console-menu
 * by user: https://stackoverflow.com/users/2386397/mike-b
 */

#include "Glcd.hpp"

// pin 17 - Serial data out (SID)
// pin 39 - Serial clock out (SCLK)
// pin 38 - Data/Command select (RS or A0)
// pin 37 - LCD reset (RST)
// pin 36 - LCD chip select (CS)
ST7565 glcd(17, 39, 38, 37, 36);


/**************************************************************************
 * STEPS TO MODIFY THIS CLASS                                             *
 * TODO: 1. make one main menu                                            *
 * TODO: 2. wire up the RGB backlight                                     *
 **************************************************************************/


/** 
 * @brief  Main menu constructor
 */
FirstMenu::FirstMenu(void)
{

}


/** 
 * @brief  The only menu able to initialize the LCD
 * @note   
 * @retval None
 */
void FirstMenu::initLcd(void)
{
  // initialize and set the contrast to 0x18
  glcd.begin(0x18);
  glcd.clear();

  // draw the bitmap
  // glcd.drawbitmap(0, 0, JustBarelyLogo, 128, 64, BLACK);
  // glcd.display();
}


/** 
 * @brief  Defining the pure virtual method
 * @note   
 * @param  choice: Index number user chose
 * @retval         BaseMenu pointer
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
      // newMenu = new SecondMenu;
      // Serial.println("ABOUT!");
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
 * @brief  Printing the menu to the LCD
 * @note   
 * @param  index: index Current index the user is at
 * @retval None
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
