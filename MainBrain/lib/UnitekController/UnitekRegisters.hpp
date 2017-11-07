/**  Constants for the Motor Controller
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
const uint8_t REG_READ      = 0x3D;  //Read a register (followed by reg to rd from)
const uint8_t REG_HALTPOLL  = 0xFF;  //Stop the MC sending values constantly

//Status oriented registers
const uint8_t REG_ERROR     = 0x8F;  //[0:31] Error bits; [16:31] Warning bits
const uint8_t REG_STATE     = 0x40;  //[0:28] Various internal states of the MC
const uint8_t REG_DPORT     = 0xD8;  //[0:15] State of all ports on the dig conn. on MC
const uint8_t REG_RUN       = 0xE8;  //[0:1]  Digital run pin enabled (FRG)
const uint8_t REG_BTB       = 0xE2;  //[0:1]  Safety relay pin enabled
const uint8_t REG_GO        = 0xE3;  //[0:2]  Internal drive enable (everything's good to go)
const uint8_t REG_HVBUS     = 0xEB;  //[0:15] HV Bus voltage

//Speed related registers
const uint8_t REG_SPEEDVAL  = 0x31;  //(SP) [0:15] Speed (in RPM) from 0-100% (0-7FFF) of RPM limit (0x59)
const uint8_t REG_SPEEDLIM  = 0xC8;  //(RW) [0:15] 100% Speed limit (in RPM) max will be 6000rpm
const uint8_t REG_SPEEDRN   = 0x30;  //[0:15] Current speed value right now (RN)

//Digital input/output states
const uint8_t REG_DOUT1     = 0xE0;  //[0:1]  State of digital output 1
const uint8_t REG_DOUT2     = 0xE1;  //[0:1]  State of digital output 2
//TODO: test what bit position DOUT 2 and 3 are!!!!!!!!!!!!!!!!!!!!!!
//const uint8_t REG_DOUT3     = 0xE1;  //[0:1]  State of digital output 3
const uint8_t REG_DIN1      = 0xE6;  //[0:1]  State of digital input 1
const uint8_t REG_DIN2      = 0xE7;  //[0:1]  State of digital input 2

//Internal values of comparison values
const uint8_t REG_VAR1      = 0xD1;  //(RW) [0:15] Reference Value 1
const uint8_t REG_VAR2      = 0xD2;  //(RW) [0:15] Reference Value 2
const uint8_t REG_VAR3      = 0xD3;  //(RW) [0:15] Reference Value 3
const uint8_t REG_VAR4      = 0xD4;  //(RW) [0:15] Reference Value 4

//Tempurature registers
const uint8_t REG_MTEMPLIM  = 0xA3;  //(RW) [0:15] Temp. limit for the motor temp. error bit to be set
const uint8_t REG_TEMPM     = 0x49;  //[0:15] Temperature of Motor
//TODO: need to figure out what's an "output stage"/////////////////
const uint8_t REG_TEMPOUTMC = 0x4A;  //[0:15] Temperature of Output stage
const uint8_t REG_TEMPAIRMC = 0x4B;  //[0:15] Temperature of MC interior air

//Mode and Core option registers
const uint8_t REG_MODE      = 0x51;  //(RW) [0:9]  Mode bits for some drive settings
const uint8_t REG_CORE      = 0x5A;  //(RW) [0:31] Core option bits for Motor/MC settings

#endif  //UNITEKREGISTERS_HPP
