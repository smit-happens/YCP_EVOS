/**  A one line description of the class.
 *
 * #include UnitekController.hpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#ifndef UNITEKCONTROLLER_HPP
#define UNITEKCONTROLLER_HPP

#include <Arduino.h>
#include "UnitekRegisters.hpp"

class UnitekController
{
public:
  UnitekController(void);

  uint8_t testFunc(void);

  // TODO: implement/refactor
  // CAN_message_t setupMCMessage(uint8_t regID, uint8_t buf1, uint8_t buf2 = 0x00, bool polling = false);

};


#endif  //UNITEKCONTROLLER_HPP
