/**  Virtual class for creating the various menus using OOP
 *
 * #include "DisplayController.hpp"
 * Created 10-01-17 By: Smitty
 *
 * Controls a graphical LCD from here: https://www.adafruit.com/product/250
 */

#ifndef DISPLAYCONTROLLER_HPP
#define DISPLAYCONTROLLER_HPP

#include <Arduino.h>
#include "ST7565.h"

// might move the backlight stuff into the Dashboard class
// only 3 pins though
// may just make a declaration header that every file that uses pins can import

// TODO: implement RGB backlight (wiring and code)
// const uint8_t BACKLIGHT_LED_R = 4;
// const uint8_t BACKLIGHT_LED_G = 4;
// const uint8_t BACKLIGHT_LED_B = 4;

/*
 * Contains the common code that will be used among all the various menus
 */
class BaseMenu
{
public:
  // Constructor for setting class-specific information. Each menu object has its own menu text.
  BaseMenu() { }

  // Virtual destructor. It must be made virtual, else you get memory leaks - read up on it
  virtual ~BaseMenu() { }

  // Only really used for the first menu
  virtual void initLcd(void) { }

  // This is a 'pure virtual method', as shown by the "= 0". It means it doesn't do anything. It's used to set up the framework
  virtual BaseMenu *getNextMenu(int iChoice) = 0;

  // Virtual method, might move more code here if it gets repetitive
  virtual void print(int index) { }

protected:
  // TODO: modify this for graphical layouts
  // This will be shared by all derived menu classes
};


// FirstMenu class is a type of BaseMenu
class FirstMenu : public BaseMenu
{
public:
  FirstMenu();

  void initLcd(void);

  // Defining the pure virtual method above
  BaseMenu *getNextMenu(int choice);

  void print(int index);
};



#endif  //DISPLAYCONTROLLER_HPP
