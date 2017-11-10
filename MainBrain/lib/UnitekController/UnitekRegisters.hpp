/**  Register constants for the Motor Controller
 *
 * #include UnitekRegisters.hpp
 * Created XX-XX-17 By: Smitty
 *
 * NOTE: All registers are Read Only (RO) unless otherwise stated
 *       Write only == SP
 *       Read/Write == RW
 * NOTE: MC == Unitek Bamocar-D3 Motor Contoller
 */

#ifndef UNITEKREGISTERS_HPP
#define UNITEKREGISTERS_HPP

#include <Arduino.h>


//Command values/Registers
const int REG_READ      = 0x3D;  //Read a register (followed by reg to rd from)
const int REG_HALTPOLL  = 0xFF;  //Stop the MC sending values constantly

//Status oriented registers
const int REG_ERROR     = 0x8F;  //[0:31] Error bits; [16:31] Warning bits
const int REG_STATE     = 0x40;  //[0:28] Various internal states of the MC
const int REG_DPORT     = 0xD8;  //[0:15] State of all ports on the dig conn. on MC
const int REG_RUN       = 0xE8;  //[0:1]  Digital run pin enabled (FRG)
const int REG_BTB       = 0xE2;  //[0:1]  Safety relay pin enabled
const int REG_GO        = 0xE3;  //[0:2]  Internal drive enable (everything's good to go)
const int REG_HVBUS     = 0xEB;  //[0:15] HV Bus voltage

//Speed related registers
const int REG_SPEEDVAL  = 0x31;  //(SP) [0:15] Speed (in RPM) from 0-100% (0-7FFF) of RPM limit (0x59)
const int REG_SPEEDLIM  = 0xC8;  //(RW) [0:15] 100% Speed limit (in RPM) max will be 6000rpm
const int REG_SPEEDRN   = 0x30;  //[0:15] Current speed value right now (RN)

//Digital input/output states
const int REG_DOUT1     = 0xE0;  //[0:1]  State of digital output 1
const int REG_DOUT2     = 0xE1;  //[0:1]  State of digital output 2
//TODO: test what bit position DOUT 2 and 3 are!!!!!!!!!!!!!!!!!!!!!!
//const int REG_DOUT3     = 0xE1;  //[0:1]  State of digital output 3
const int REG_DIN1      = 0xE6;  //[0:1]  State of digital input 1
const int REG_DIN2      = 0xE7;  //[0:1]  State of digital input 2

//Internal values of comparison values
const int REG_VAR1      = 0xD1;  //(RW) [0:15] Reference Value 1
const int REG_VAR2      = 0xD2;  //(RW) [0:15] Reference Value 2
const int REG_VAR3      = 0xD3;  //(RW) [0:15] Reference Value 3
const int REG_VAR4      = 0xD4;  //(RW) [0:15] Reference Value 4

//Tempurature registers
const int REG_MTEMPLIM  = 0xA3;  //(RW) [0:15] Temp. limit for the motor temp. error bit to be set
const int REG_TEMPM     = 0x49;  //[0:15] Temperature of Motor
//TODO: need to figure out what's an "output stage"/////////////////
const int REG_TEMPOUTMC = 0x4A;  //[0:15] Temperature of Output stage
const int REG_TEMPAIRMC = 0x4B;  //[0:15] Temperature of MC interior air

//Mode and Core option registers
const int REG_MODE      = 0x51;  //(RW) [0:9]  Mode bits for some drive settings
const int REG_CORE      = 0x5A;  //(RW) [0:31] Core option bits for Motor/MC settings

#endif  //UNITEKREGISTERS_HPP
