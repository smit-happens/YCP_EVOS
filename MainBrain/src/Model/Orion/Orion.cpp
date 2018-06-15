/**  A one line description of the class.
 *
 * Orion.cpp
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#include "Orion.hpp"

/** 
 * @brief  Orion constructor
 */
Orion::Orion(void)
{
    pinMode(MB_BMS_STATUS, INPUT);
 
    data_0x420 = new CanData_0x420;
    data_0x421 = new CanData_0x421;

    //initialize data_0x420 to 0
    data_0x420->averageCellTemp_Byte = 0;
    data_0x420->highestCellTemp_Byte = 0;
    data_0x420->maxOpenCellVoltage_Byte1 = 0;
    data_0x420->maxOpenCellVoltage_Byte2 = 0;
    data_0x420->minOpenCellVoltage_Byte1 = 0;
    data_0x420->minOpenCellVoltage_Byte2 = 0;
    data_0x420->stateOfCharge_Byte = 0;
    data_0x420->stateOfHealth_Byte = 0;

    //initialize data_0x421 to 0
    data_0x421->averageOpenCellVoltage_Byte1 = 0;
    data_0x421->averageOpenCellVoltage_Byte2 = 0;
    data_0x421->packCurrent_Byte1 = 0;
    data_0x421->packCurrent_Byte2 = 0;
    data_0x421->packDischargeCurrentLimit_Byte1 = 0;
    data_0x421->packDischargeCurrentLimit_Byte2 = 0;
    data_0x421->packSummedVoltage_Byte1 = 0;
    data_0x421->packSummedVoltage_Byte2 = 0;
}


/** 
 * @brief  Orion destructor
 */
Orion::~Orion(void)
{
    delete data_0x420;
    delete data_0x421;
}


//all of the public get functions
//gets for values from message 0x420
/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getStateOfCharge_Byte(void)
{
    return data_0x420->stateOfCharge_Byte;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getStateOfHealth_Byte(void)
{
    return data_0x420->stateOfHealth_Byte;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getHighestCellTemp_Byte(void)
{
    return data_0x420->highestCellTemp_Byte;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getAverageCellTemp_Byte(void)
{
    return data_0x420->averageCellTemp_Byte;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getMaxOpenCellVoltage_Byte1(void)
{
    return data_0x420->maxOpenCellVoltage_Byte1;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getMaxOpenCellVoltage_Byte2(void)
{
    return data_0x420->maxOpenCellVoltage_Byte2;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getMinOpenCellVoltage_Byte1(void)
{
    return data_0x420->minOpenCellVoltage_Byte1;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getMinOpenCellVoltage_Byte2(void)
{
    return data_0x420->minOpenCellVoltage_Byte2;
}



//gets for values from message 0x421
/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getPackDischargeCurrentLimit_Byte1(void)
{
    return data_0x421->packDischargeCurrentLimit_Byte1;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getPackDischargeCurrentLimit_Byte2(void)
{
    return data_0x421->packDischargeCurrentLimit_Byte2;
}


/** 
 * @brief  get the first byte of the pack summed voltage
 * @note   
 * @retval first byte of the pack summed voltage
 */
uint8_t Orion::getPackSummedVoltage_Byte1(void)
{
    return data_0x421->packSummedVoltage_Byte1;
}


/** 
 * @brief  get the second byte of the pack summed voltage
 * @note   
 * @retval second byte of the pack summed voltage
 */
uint8_t Orion::getPackSummedVoltage_Byte2(void)
{
    return data_0x421->packSummedVoltage_Byte2;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getPackCurrent_Byte1(void)
{
    return data_0x421->packCurrent_Byte1;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getPackCurrent_Byte2(void)
{
    return data_0x421->packCurrent_Byte2;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getAverageOpenCellVoltage_Byte1(void)
{
    return data_0x421->averageOpenCellVoltage_Byte1;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
uint8_t Orion::getAverageOpenCellVoltage_Byte2(void)
{
    return data_0x421->averageOpenCellVoltage_Byte2;
}




//all of the public set functions
//gets for values from message 0x420
/** 
 * @brief  
 * @note   
 * @param  newStateOfCharge_Byte: 
 * @retval None
 */
void Orion::setStateOfCharge_Byte(uint8_t newStateOfCharge_Byte)
{
    data_0x420->stateOfCharge_Byte = newStateOfCharge_Byte;
}


/** 
 * @brief  
 * @note   
 * @param  newStateOfHealth_Byte: 
 * @retval None
 */
void Orion::setStateOfHealth_Byte(uint8_t newStateOfHealth_Byte)
{
    data_0x420->stateOfHealth_Byte = newStateOfHealth_Byte;
}


/** 
 * @brief  
 * @note   
 * @param  newHighestCellTemp_Byte: 
 * @retval None
 */
void Orion::setHighestCellTemp_Byte(uint8_t newHighestCellTemp_Byte)
{
    data_0x420->highestCellTemp_Byte = newHighestCellTemp_Byte;
}


/** 
 * @brief  
 * @note   
 * @param  newAverageCellTemp_Byte: 
 * @retval None
 */
void Orion::setAverageCellTemp_Byte(uint8_t newAverageCellTemp_Byte)
{
    data_0x420->averageCellTemp_Byte = newAverageCellTemp_Byte;
}


/** 
 * @brief  
 * @note   
 * @param  newMaxOpenCellVoltage_Byte1: 
 * @retval None
 */
void Orion::setMaxOpenCellVoltage_Byte1(uint8_t newMaxOpenCellVoltage_Byte1)
{
    data_0x420->maxOpenCellVoltage_Byte1 = newMaxOpenCellVoltage_Byte1;
}


/** 
 * @brief  
 * @note   
 * @param  newMaxOpenCellVoltage_Byte2: 
 * @retval None
 */
void Orion::setMaxOpenCellVoltage_Byte2(uint8_t newMaxOpenCellVoltage_Byte2)
{
    data_0x420->maxOpenCellVoltage_Byte2 = newMaxOpenCellVoltage_Byte2;
}


/** 
 * @brief  
 * @note   
 * @param  newMinOpenCellVoltage_Byte1: 
 * @retval None
 */
void Orion::setMinOpenCellVoltage_Byte1(uint8_t newMinOpenCellVoltage_Byte1)
{
    data_0x420->minOpenCellVoltage_Byte1 = newMinOpenCellVoltage_Byte1;
}


/** 
 * @brief  
 * @note   
 * @param  newMinOpenCellVoltage_Byte2: 
 * @retval None
 */
void Orion::setMinOpenCellVoltage_Byte2(uint8_t newMinOpenCellVoltage_Byte2)
{
    data_0x420->minOpenCellVoltage_Byte2 = newMinOpenCellVoltage_Byte2;
}


//gets for values from message 0x421
/** 
 * @brief  
 * @note   
 * @param  newPackDischargeCurrentLimit: 
 * @retval None
 */
void Orion::setPackDischargeCurrentLimit_Byte1(uint8_t newPackDischargeCurrentLimit_Byte1)
{
    data_0x421->packDischargeCurrentLimit_Byte1 = newPackDischargeCurrentLimit_Byte1;
}


/** 
 * @brief  
 * @note   
 * @param  newPackDischargeCurrentLimit: 
 * @retval None
 */
void Orion::setPackDischargeCurrentLimit_Byte2(uint8_t newPackDischargeCurrentLimit_Byte2)
{
    data_0x421->packDischargeCurrentLimit_Byte2 = newPackDischargeCurrentLimit_Byte2;
}


/** 
 * @brief  
 * @note   
 * @param  newPackOpenVoltage: 
 * @retval None
 */
void Orion::setPackSummedVoltage_Byte1(uint8_t newPackOpenVoltage_Byte1)
{
    data_0x421->packSummedVoltage_Byte1 = newPackOpenVoltage_Byte1;
}


/** 
 * @brief  
 * @note   
 * @param  newPackOpenVoltage: 
 * @retval None
 */
void Orion::setPackSummedVoltage_Byte2(uint8_t newPackOpenVoltage_Byte2)
{
    data_0x421->packSummedVoltage_Byte2 = newPackOpenVoltage_Byte2;
}


/** 
 * @brief  
 * @note   
 * @param  newPackCurrent: 
 * @retval None
 */
void Orion::setPackCurrent_Byte1(uint8_t newPackCurrent_Byte1)
{
    data_0x421->packCurrent_Byte1 = newPackCurrent_Byte1;
}


/** 
 * @brief  
 * @note   
 * @param  newPackCurrent: 
 * @retval None
 */
void Orion::setPackCurrent_Byte2(uint8_t newPackCurrent_Byte2)
{
    data_0x421->packCurrent_Byte2 = newPackCurrent_Byte2;
}


/** 
 * @brief  
 * @note   
 * @param  newAverageOpenCellVoltage: 
 * @retval None
 */
void Orion::setAverageOpenCellVoltage_Byte1(uint8_t newAverageOpenCellVoltage_Byte1)
{
    data_0x421->averageOpenCellVoltage_Byte1 = newAverageOpenCellVoltage_Byte1;
}


/** 
 * @brief  
 * @note   
 * @param  newAverageOpenCellVoltage: 
 * @retval None
 */
void Orion::setAverageOpenCellVoltage_Byte2(uint8_t newAverageOpenCellVoltage_Byte2)
{
    data_0x421->averageOpenCellVoltage_Byte2 = newAverageOpenCellVoltage_Byte2;
}