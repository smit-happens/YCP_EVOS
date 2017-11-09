/**  A one line description of the class.
 *
 * EncoderHandler.cpp
 * Created XX-XX-17 By: Smitty
 *
 * A longer description.
 */

#include "EncoderHandler.hpp"


/*
 * Encoder constructor
 */
EncoderHandler::EncoderHandler(void)
{
  index = 0;
  cw = 0;
  ccw = 0;
  change = false;
  A_set = false;
  B_set = false;

  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  pinMode(buttonPin, INPUT);
}


/**
 * Interrupt on A changing state
 */
void EncoderHandler::doEncoderA(void)
{
  // Test transition
  A_set = digitalRead(encoderPinA) == HIGH;
  // and adjust counter + if A leads B
  encoderPos = (A_set != B_set) ? +1 : -1;
}


/**
 * Interrupt on B changing state
 */
void EncoderHandler::doEncoderB(void)
{
  // Test transition
  B_set = digitalRead(encoderPinB) == HIGH;
  // and adjust counter + if B follows A
  encoderPos = (A_set == B_set) ? +1 : -1;
}


/**
 * For finding the current encoder index
 * @return  Index value
 */
int EncoderHandler::getIndex(void)
{
  return index;
}


/**
 * Updates index based on encoder direction
 * TODO: maybe refactor logic here (ugly-ish but it works)
 * @param menuLength Used for wrap around calculation
 */
void EncoderHandler::updateIndex(int menuLength)
{
  // Checking for any change in rotation cw or ccw represented by encoderPos variable
  if (0 > encoderPos)
  {
    cw++;
    ccw = 0;
    change = true;
  }
  else if(0 < encoderPos)
  {
    ccw++;
    cw = 0;
    change = true;
  }

  if(change == true)
  {
    // Reset values so this condition isn't executed repeatedly
    encoderPos = 0;
    change = false;

    //TODO: ADD/FIX SCROLLING/////////////////////////// (in menu.cpp)

    // Notches are at every 4 steps on the encoder
    // Checks every 4 steps to move up/down a menu item
    if(cw >= 4)
    {
      cw = 0;

      // Loop back to the bottom (index = menuLength -1)
      if(index <= 0)
      {
        index = menuLength - 1;
      }
      else
      {
        index--;
      }
    }
    else if(ccw >= 4)
    {
      ccw = 0;

      // Loop back to the top (index = 0) if greater than our menu length
      if(index >= menuLength - 1)
      {
        index = 0;
      }
      else
      {
        index++;
      }
    }
  }
}


/**
 * Iterrupt on a changing button state
 * TODO: fix this, either through hardware or software
 */
void EncoderHandler::pressButton(void)
{
    buttonState = !buttonState;
}


/**
 * TODO: (better) implement pushbutton of the encoder to select things
 * @return  State of the button
 */
bool EncoderHandler::isButtonPressed(void)
{
    return buttonState;
}
