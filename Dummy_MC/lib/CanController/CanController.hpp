/**  A one line description of the class.
 *
 * #include "CanController.hpp"
 * Created 09-30-17  By: Smitty
 *
 * A longer description.
 */

#ifndef CANCONTROLLER_HPP
#define CANCONTROLLER_HPP

#include <Arduino.h>
#include <FlexCAN.h>


class CanController : public CANListener
{
public:
  CanController();

  void printFrame(CAN_message_t &frame, int mailbox);

  //overrides the parent version so we can actually do something
  void gotFrame(CAN_message_t &frame, int mailbox);

  // TODO: move this into MotorController lib
  // CAN_message_t setupMCMessage(uint8_t regID, uint8_t buf1, uint8_t buf2 = 0x00, bool polling = false);

};


#endif  //CANCONTROLLER_HPP
