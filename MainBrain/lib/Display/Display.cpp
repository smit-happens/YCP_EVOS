/**  Class for managing the Display and creating menus using OOP
 *
 * Display.cpp
 * Created 10-01-17 By: Smitty
 *
 * Implemented based off the code found here: https://stackoverflow.com/questions/16852978/navigating-console-menu
 * by user: https://stackoverflow.com/users/2386397/mike-b
 */

#include "Display.hpp"


// TODO: implement this backlight (wiring and code)
// the LCD backlight is connected up to a pin so you can turn it on & off
const uint8_t BACKLIGHT_LED = 4;

// pin 17 - Serial data out (SID)
// pin 39 - Serial clock out (SCLK)
// pin 38 - Data/Command select (RS or A0)
// pin 37 - LCD reset (RST)
// pin 36 - LCD chip select (CS)
ST7565 glcd(17, 39, 38, 37, 36);


void testdrawchar(void) {
  for (uint8_t i=0; i < 168; i++) {
    glcd.drawchar((i % 21) * 6, i/21, i);
  }
}

void testdrawcircle(void) {
  for (uint8_t i=0; i<64; i+=2) {
    glcd.drawcircle(63, 31, i, BLACK);
  }
}


void testdrawrect(void) {
  for (uint8_t i=0; i<64; i+=2) {
    glcd.drawrect(i, i, 128-i, 64-i, BLACK);
  }
}

void testfillrect(void) {
  for (uint8_t i=0; i<64; i++) {
      // alternate colors for moire effect
    glcd.fillrect(i, i, 128-i, 64-i, i%2);
  }
}

void testdrawline() {
  for (uint8_t i=0; i<128; i+=4) {
    glcd.drawline(0, 0, i, 63, BLACK);
  }
  for (uint8_t i=0; i<64; i+=4) {
    glcd.drawline(0, 0, 127, i, BLACK);
  }

  glcd.display();
  delay(1000);

  for (uint8_t i=0; i<128; i+=4) {
    glcd.drawline(i, 63, 0, 0, WHITE);
  }
  for (uint8_t i=0; i<64; i+=4) {
    glcd.drawline(127, i, 0, 0, WHITE);
  }
}

//---------------------------------------------------------------
// Defining the main menu
FirstMenu::FirstMenu(void)
{
  // lcd.clear();
  // menuText.push_back("About");
  // menuText.push_back("Monitor CAN");
  // menuText.push_back("Blink LED");
}


/**
 * The only menu able to initialize the LCD
 */
void FirstMenu::initLcd(void)
{
  // initialize and set the contrast to 0x18
  glcd.begin(0x18);

  glcd.display(); // show splashscreen
  delay(2000);
  glcd.clear();

  // draw a single pixel
  glcd.setpixel(10, 10, BLACK);
  glcd.display();        // show the changes to the buffer
  delay(2000);
  glcd.clear();

  // draw many lines
  testdrawline();
  glcd.display();       // show the lines
  delay(2000);
  glcd.clear();

  // draw rectangles
  testdrawrect();
  glcd.display();
  delay(2000);
  glcd.clear();

  // draw multiple rectangles
  testfillrect();
  glcd.display();
  delay(2000);
  glcd.clear();

  // draw mulitple circles
  testdrawcircle();
  glcd.display();
  delay(2000);
  glcd.clear();

  // draw a black circle, 10 pixel radius, at location (32,32)
  glcd.fillcircle(32, 32, 10, BLACK);
  glcd.display();
  delay(2000);
  glcd.clear();

  // draw the first ~120 characters in the font
  testdrawchar();
  glcd.display();
  delay(2000);
  glcd.clear();

  // draw a string at location (0,0)
  glcd.drawstring(0, 0, (char*)"Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation");
  glcd.display();
  delay(2000);
  glcd.clear();
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


/**
 * Defining the CAN menu
 */
SecondMenu::SecondMenu(void)
{
  // lcd.clear();
  // menuText.push_back("Version 0.0.001?");
  // menuText.push_back("By Smitty");
  // menuText.push_back("Select any option");
  // menuText.push_back("to go back");
}


/**
 * CAN menu option logic
 * @param  choice                Index number user chose
 * @return                       BaseMenu pointer
 */
BaseMenu *SecondMenu::getNextMenu(int choice) // This is us actually defining the pure virtual method above
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
