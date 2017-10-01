//***************************************************************
// CanController.cpp
// Created 9-30-17
//

#include "CanController.hpp"


//---------------------------------------------------------------
//CanController constructor
CanController::CanController(void)
{

}


//---------------------------------------------------------------
//Prints out a given CAN frame
void CanController::printFrame(CAN_message_t &frame, int mailbox)
{
  Serial.print("This just in!\n");
  Serial.print("ID: 0x");
  Serial.print(frame.id, HEX);

  //Print regID from buf[0]
  Serial.print(" RegID: 0x");
  Serial.print(frame.buf[0], HEX);

  //Print value from register in reverse byte order
  Serial.print(" Data: 0x");
  Serial.print(frame.buf[2], HEX);
  Serial.print(frame.buf[1], HEX);

  Serial.write('\n');
}


//---------------------------------------------------------------
//Called whenever a new CAN frame is recieved
void CanController::gotFrame(CAN_message_t &frame, int mailbox)
{
  printFrame(frame, mailbox);
}


//---------------------------------------------------------------
//Constructs a formatted MC message
CAN_message_t CanController::setupMCMessage(uint8_t regID, uint8_t buf1 = 0x00, uint8_t buf2 = 0x00, bool stopPolling = false)
{
  CAN_message_t tx;

  tx.ext = 0;
  tx.id = 0x201;
  tx.len = 3;

  if(regID == REG_READ)
  {
    //performing a read operation set buf[0] to READ command
    tx.buf[0] = REG_READ;
    tx.buf[1] = buf1;

    //default is 0 but can represent time (in ms) for polling
    tx.buf[2] = buf2;

    //deactivates polling
    if(stopPolling)
    {
      tx.buf[2] = REG_HALTPOLL;
    }
  }
  else
  {
    //performing write opration
    tx.buf[0] = regID;

    //storing the value in byte flipped order
    tx.buf[2] = buf1;
    tx.buf[1] = buf2;
  }

  return tx;
}
