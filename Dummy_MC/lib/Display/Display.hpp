#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Arduino.h>
#include <LiquidCrystalFast.h>

#define lcdHeight 4

class Display
{
public:
  Display();

  void printMenu(int index);

};

#endif
