/**  A one line description of the class.
 *
 * #include "Button.hpp"
 * Created 12-13-17  By: Smitty
 *
 * A longer description.
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <Arduino.h>
#include "../Constants/Port.hpp"

class Button
{
public:
  Button(void);

  String getName(void);

  int getState(void);
  void setState(void);
};


#endif  //BUTTON_HPP
