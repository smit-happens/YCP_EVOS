/**  A one line description of the class.
 *
 * #include "Light.hpp"
 * Created 12-15-17  By: Smitty
 *
 * A longer description.
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include <Arduino.h>

class Light
{
public:
  Light(void);

  String getName(void);

  int getState(void);
  void setState(bool);
};


#endif  //LIGHT_HPP
