/**  Register constants for the Orion
 *
 * #include "OrionRegisters.hpp"
 * Created 11-09-17 By: Smitty
 * 
 * A longer description.
 */

#ifndef ORIONREGISTERS_HPP
#define ORIONREGISTERS_HPP

//TODO: Need to fill this out more

const int REG_MAX_SUPPORTED_CELLS           = 0xF006;
const int REG_SIGNED_PACK_CURRENT           = 0xF00C;
const int REG_UNSIGNED_PACK_CURRENT         = 0xF015;
const int REG_PACK_VOLTAGE                  = 0xF00D;
const int REG_PACK_CHARGE_AMOUNT            = 0xF00F;
const int REG_PACK_AMPHOURS                 = 0xF010;
const int REG_PACK_RESISTANCE               = 0xF011;
const int REG_PACK_HEALTH                   = 0xF013;
const int REG_PACK_SUMMED_VOLTAGE           = 0xF014;
const int REG_PACK_CHARGE_CYCLES            = 0xF018;

//Cell tempuratures
const int REG_MAX_TEMP                      = 0xF028;  //Celcius
const int REG_MIN_TEMP                      = 0xF029;  //Celcius
const int REG_AVG_TEMP                      = 0xF02A;  //Celcius
const int REG_HEATSINK_TEMP                 = 0xF02D;  //Celcius

//General cell voltage levels
const int MIN_CELL_VOLTAGE                  = 0xF032;
const int MAX_CELL_VOLTAGE                  = 0xF033;
const int AVG_CELL_VOLTAGE                  = 0xF034;

//Voltage levels of individual cells
const int CELL_VOLTAGE_1_12                 = 0xF100;
const int CELL_VOLTAGE_13_24                = 0xF101;
const int CELL_VOLTAGE_25_36                = 0xF102;
const int CELL_VOLTAGE_37_48                = 0xF103;
const int CELL_VOLTAGE_49_60                = 0xF104;
const int CELL_VOLTAGE_61_72                = 0xF105;
const int CELL_VOLTAGE_73_84                = 0xF106;
const int CELL_VOLTAGE_85_96                = 0xF107;

//Voltage levels of individual cells
const int CELL_INTERNAL_RESISTANCE_1_12     = 0xF100;
const int CELL_INTERNAL_RESISTANCE_13_24    = 0xF101;
const int CELL_INTERNAL_RESISTANCE_25_36    = 0xF102;
const int CELL_INTERNAL_RESISTANCE_37_48    = 0xF103;
const int CELL_INTERNAL_RESISTANCE_49_60    = 0xF104;
const int CELL_INTERNAL_RESISTANCE_61_72    = 0xF105;
const int CELL_INTERNAL_RESISTANCE_73_84    = 0xF106;
const int CELL_INTERNAL_RESISTANCE_85_96    = 0xF107;


#endif  //ORIONREGISTERS_HPP
