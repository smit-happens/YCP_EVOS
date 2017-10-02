/**  A one line description of the class.
 *
 * #include MotorController.hpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#ifndef MOTORCONTROLLER_HPP
#define MOTORCONTROLLER_HPP

#include <Arduino.h>
#include "MotorControllerRegisters.hpp"

class MotorController
{
public:
  MotorController(void);

  uint8_t testFunc(void);

};


#endif  //MOTORCONTROLLER_HPP
