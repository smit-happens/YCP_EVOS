/**  A one line description of the class.
 *
 * #include "Button.hpp"
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Arduino.h>

class Button
{
public:
  Button(void);

  int getState(void);

};


#endif  //BUTTON_HPP
