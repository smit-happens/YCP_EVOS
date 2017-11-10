/**  Register constants for the Orion
 *
 * #include "OrionRegisters.hpp"
 * Created 11-09-17 By: Smitty
 * 
 * A longer description.
 */

 #ifndef ORIONREGISTERS_HPP
 #define ORIONREGISTERS_HPP

 #include <Arduino.h>


const int REG_MAX_SUPPORTED_CELLS       = 0xF006;
const int REG_SIGNED_PACK_CURRENT       = 0xF00C;
const int REG_UNSIGNED_PACK_CURRENT     = 0xF015;
const int REG_PACK_VOLTAGE              = 0xF00D;
const int REG_PACK_CHARGE_AMOUNT        = 0xF00F;
const int REG_PACK_AMPHOURS             = 0xF010;
const int REG_PACK_RESISTANCE           = 0xF011;
const int REG_PACK_HEALTH               = 0xF013;
const int REG_PACK_SUMMED_VOLTAGE       = 0xF014;
const int REG_PACK_CHARGE_CYCLES        = 0xF018;

//Cell tempuratures
const int REG_MAX_TEMP                  = 0xF028;  //Celcius
const int REG_MIN_TEMP                  = 0xF029;  //Celcius
const int REG_AVG_TEMP                  = 0xF02A;  //Celcius
const int REG_HEATSINK_TEMP             = 0xF02D;  //Celcius

//Cell voltage levels
const int MIN_CELL_VOLTAGE              = 0xF032;
const int MAX_CELL_VOLTAGE              = 0xF033;
const int AVG_CELL_VOLTAGE              = 0xF034;




 #endif  //ORIONREGISTERS_HPP
