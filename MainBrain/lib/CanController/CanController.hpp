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

const int UNITEKREADID = 0x181;
const int UNITEKSENDID = 0x201;

// const int ORIONREADID = 0x181;   //not decided yet
const int ORIONSENDID = 0x840;

class CanController : public CANListener
{
public:
  CanController();

  void printFrame(CAN_message_t &frame, int mailbox);

  //overrides the parent version
  void gotFrame(CAN_message_t &frame, int mailbox);

  //TODO: read() and send() should be able to work for BMS and MC easily

  // void send(void);
  // void read(void);

};


#endif  //CANCONTROLLER_HPP
