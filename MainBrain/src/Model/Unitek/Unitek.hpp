/**  A one line description of the class.
 *
 * #include Unitek.hpp
 * Created 09-30-17 By: Smitty
 *
 * A longer description.
 */

#ifndef UNITEK_HPP
#define UNITEK_HPP

#include <Arduino.h>
#include "UnitekRegisters.hpp"

const int RPM_LIMIT = 7000; //0xC8
const int MAX_VAL = 32767;  //0x7FFF

//TODO: Precharge pins (RFE, RTD, RUN)

class Unitek
{
public:
  Unitek(void);

  int calculateSpeedValue(int rpm);
  int calculateRpm(int speedValue);

  int precharge(void);

  //TODO: implement to construct CAN message
  int setupCan(uint8_t regID, uint8_t buf1, uint8_t buf2, bool polling);

  int parseCan(void);

};


#endif  //UNITEK_HPP
