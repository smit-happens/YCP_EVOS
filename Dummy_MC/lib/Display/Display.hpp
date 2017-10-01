/**  A one line description of the class.
 *
 * #include "Display.hpp"
 * Created XX-XX-17 By: Smitty
 *
 * A longer description.
 */

#ifndef DISPLAY_HPP
#define DISPLAY_HPP

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

#endif  //DISPLAY_HPP
