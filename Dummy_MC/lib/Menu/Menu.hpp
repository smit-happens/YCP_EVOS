/**  Virtual class for creating the various menus using OOP
 *
 * #include "Menu.hpp"
 * Created 10-01-17 By: Smitty
 *
 * Implemented based off the code found here: https://stackoverflow.com/questions/16852978/navigating-console-menu
 * by user: https://stackoverflow.com/users/2386397/mike-b
 */

#ifndef MENU_HPP
#define MENU_HPP

#include <Arduino.h>
#include <LiquidCrystalFast.h>
#include <vector>  //vector <type>

const uint8_t lcdHeight = 4;


class BaseMenu
{
public:
  // Constructor for setting class-specific information. Each menu object has its own menu text.
  BaseMenu() { }

  // Virtual destructor. It must be made virtual, else you get memory leaks - need read up on it
  virtual ~BaseMenu() { }

  virtual void initLcd(void) { }

  // This is a 'pure virtual method', as shown by the "= 0". It means it doesn't do anything. It's used to set up the framework
  virtual BaseMenu *getNextMenu(int iChoice, bool& iIsQuitOptionSelected) = 0;

  // This is made virtual, but doesn't *have* to be redefined. In the current code I have written, it is not redefined as we store the menu text as a string in the object
  virtual void print(int index) { }

  // Gets the size of the vector (type std::vector<T>::size_type), converts it to an int
  virtual int getMenuLength(void) { return static_cast<int>(menuText.size()); }

protected:
  // This string will be shared by all derived menu classes
  std::vector<String> menuText;
};


// FirstMenu class is a type of BaseMenu
class FirstMenu : public BaseMenu
{
public:
  FirstMenu();

  void initLcd(void);

  // Defining the pure virtual method above
  BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected);

  void print(int index);
};


class SecondMenu : public BaseMenu
{
public:
  SecondMenu();

  // Defining the pure virtual method above
  BaseMenu *getNextMenu(int choice, bool& iIsQuitOptionSelected);
};


#endif  //MENU_HPP
