//***************************************************************
// CAN.hpp
// Created 9-30-17
//

#ifndef CAN_HPP
#define CAN_HPP

#include <Arduino.h>
#include <FlexCAN.h>

class CAN : public CANListener
{
public:
  CAN();

  void printFrame(CAN_message_t &frame, int mailbox);

  //overrides the parent version so we can actually do something
  void gotFrame(CAN_message_t &frame, int mailbox);

  CAN_message_t setupMCMessage(uint8_t regID, uint8_t buf1, uint8_t buf2 = 0x00, bool polling = false);

};


#endif
