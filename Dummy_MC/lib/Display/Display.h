#ifndef DISPLAY_H
#define DISPLAY_H

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
