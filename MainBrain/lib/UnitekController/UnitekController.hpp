/**  A one line description of the class.
 *
 * #include UnitekController.hpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#ifndef UNITEKCONTROLLER_HPP
#define UNITEKCONTROLLER_HPP

#include "UnitekRegisters.hpp"

const int RPM_LIMIT = 7000; //0xC8
const int MAX_VAL = 32767;  //0x7FFF

//TODO: Precharge pins (RFE, RTD, RUN)

class UnitekController
{
public:
  UnitekController(void);

  int calculateSpeedValue(int rpm);
  int calculateRpm(int speedValue);

  int precharge(void);

  //TODO: implement to construct CAN message
  int setupCan(uint8_t regID, uint8_t buf1, uint8_t buf2, bool polling);

  int parseCan(void);

};


#endif  //UNITEKCONTROLLER_HPP
