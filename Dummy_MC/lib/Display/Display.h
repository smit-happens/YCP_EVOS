#include <Arduino.h>
#include <LiquidCrystalFast.h>

#define lcdHeight 4

//LiquidCrystalFast lcd(RS, RW, Enable, D4, D5, D6, D7);
LiquidCrystalFast lcd(33, 34, 35, 36, 37, 38, 39);

class Display
{
public:
  Display(void);
  void printMenu(String * menu, int index);

  void testFunc(void);
// private:
  // int index;
};
