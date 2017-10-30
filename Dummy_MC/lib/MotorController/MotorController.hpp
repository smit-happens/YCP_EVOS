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

  // TODO: implement/refactor
  // CAN_message_t setupMCMessage(uint8_t regID, uint8_t buf1, uint8_t buf2 = 0x00, bool polling = false);

};


#endif  //MOTORCONTROLLER_HPP
