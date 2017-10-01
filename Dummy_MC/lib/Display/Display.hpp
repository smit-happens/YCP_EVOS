#ifndef __DISPLAY_HPP_INCLUDED__
#define __DISPLAY_HPP_INCLUDED__

#include <Arduino.h>
#include <LiquidCrystalFast.h>

const uint8_t lcdHeight = 4;

class Display
{
public:
  Display();

  void print(String text);
  void printMenu(int index);

};

#endif  //__DISPLAY_HPP_INCLUDED__
