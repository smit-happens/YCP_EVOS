/**  Class for creating the various menus using OOP
 *
 * Menu.cpp
 * Created 10-01-17 By: Smitty
 *
 * Implemented based off the code found here: https://stackoverflow.com/questions/16852978/navigating-console-menu
 * by user: https://stackoverflow.com/users/2386397/mike-b
 */

#include "Menu.hpp"

testFunc::testFunc(void)
{
  BaseMenu* aCurrentMenu = new FirstMenu; // We have a pointer to our menu. We're using a pointer so we can change the menu seamlessly.
  bool isQuitOptionSelected = false;
  while (!isQuitOptionSelected) // We're saying that, as long as the quit option wasn't selected, we keep running
  {
    aCurrentMenu->printText();  // This will call the method of whichever MenuObject we're using, and print the text we want to display

    int choice = 0; // Always initialise variables, unless you're 100% sure you don't want to.
    // cin >> choice;

    BaseMenu* aNewMenuPointer = aCurrentMenu->getNextMenu(choice, isQuitOptionSelected); // This will return a new object, of the type of the new menu we want. Also checks if quit was selected

    if (aNewMenuPointer) // This is why we set the pointer to 0 when we were creating the new menu - if it's 0, we didn't create a new menu, so we will stick with the old one
    {
      delete aCurrentMenu; // We're doing this to clean up the old menu, and not leak memory.
      aCurrentMenu = aNewMenuPointer; // We're updating the 'current menu' with the new menu we just created
    }
  }
}


FirstMenu::FirstMenu(void)
{
  m_MenuText = "Main Menu\n"      // Setting up the string to be displayed later
               "1 - Start game\n"
               "2 - Options\n"
               "3 - Quit\n";
}

// This is defining the pure virtual method above
BaseMenu *FirstMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected)
{
  // Setting up the pointer here, but making sure it's null (0)
  BaseMenu *aNewMenu = 0;

  switch (choice)
  {
    case 2:
      aNewMenu = new SecondMenu; // We're creating our new menu object here, and will send it back to the main function below
    break;

    case 3:
      // They selected quit! Update the bool we got as input
      iIsQuitOptionSelected = true;
    break;

    default:
      // Do nothing - we won't change the menu
    break;
  }
  return aNewMenu; // Sending it back to the main function
}


SecondMenu::SecondMenu(void)
{
  m_MenuText = "OptionsMenu\n"
               "1 - ????"
               "2 - dafuq?";
}


BaseMenu *SecondMenu::getNextMenu(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
  BaseMenu *aNewMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

  switch (choice) //need to do this for all menus
  {
    case 1:
      aNewMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
    break;

    case 2:
      aNewMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
    break;

    default:
      // Do nothing - we won't change the menu
    break;
  }

  return aNewMenu; // Sending it back to the main function
}
