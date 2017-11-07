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

  //overrides the parent version
  void gotFrame(CAN_message_t &frame, int mailbox);

  //TODO: implement function to construct CAN message given ID and data
  //TODO: should be able to work for BMS and MC easily

};


#endif  //CANCONTROLLER_HPP
