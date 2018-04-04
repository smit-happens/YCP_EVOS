/**  OrionController manages all data processing for the Orion BMS
 *
 * OrionController.cpp
 * Created 2-2-18 By: Smitty
 *
 * A longer description.
 */

#include "OrionController.hpp"


//to see if the instance of the class has been initialized yet
OrionController* OrionController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
OrionController* OrionController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new OrionController();

    return _pInstance;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
OrionController::~OrionController(void)
{
    delete orionModel;
}


/** 
 * @brief  
 * @note   
 * @retval 
 */
void OrionController::init(void)
{
    orionModel = new Orion();
}


/** 
 * @brief  Read the BMS CAN BUS to receive the data from the battery pack
 * @note   Use this data to update the model
 * @retval None
 */
void OrionController::poll(void)
{
    uint8_t* data_0x420;// = CanController.getOrionMessage(ID_0x420);
    uint8_t* data_0x421;// = CanController.getOrionMessage(ID_0x421);
    updateModelMessage_0x420(data_0x420);
    updateModelMessage_0x421(data_0x421);
}

/** 
 * @brief  Parse the message and update the model
 * @note   More explanation of the necessary changes to the values is present in the Orion.hpp in the definitions of the CanData_0x420 and CanData_0x421 structs
 * @param  messageToParse: the most recent CAN message from the BUS with ID = 0x420
 * @retval None
 */
void OrionController::updateModelMessage_0x420(uint8_t* messageToParse)
{
    orionModel->setStateOfCharge_Byte(messageToParse[0]);
    orionModel->setStateOfHealth_Byte(messageToParse[1]);
    orionModel->setHighestCellTemp_Byte(messageToParse[2]);
    orionModel->setAverageCellTemp_Byte(messageToParse[3]);
    orionModel->setMaxOpenCellVoltage_Byte1(messageToParse[4]);
    orionModel->setMaxOpenCellVoltage_Byte2(messageToParse[5]);
    orionModel->setMinOpenCellVoltage_Byte1(messageToParse[6]);
    orionModel->setMinOpenCellVoltage_Byte2(messageToParse[7]);
}


/** 
 * @brief  Parse the message and update the model
 * @note   More explanation of the necessary changes to the values is present in the Orion.hpp in the definitions of the CanData_0x420 and CanData_0x421 structs
 * @param  messageToParse: the most recent CAN message from the BUS with ID = 0x421
 * @retval None
 */
void OrionController::updateModelMessage_0x421(uint8_t* messageToParse)
{
    orionModel->setPackDischargeCurrentLimit_Byte1(messageToParse[0]);
    orionModel->setPackDischargeCurrentLimit_Byte2(messageToParse[1]);
    orionModel->setPackOpenVoltage_Byte1(messageToParse[2]);
    orionModel->setPackOpenVoltage_Byte2(messageToParse[3]);
    orionModel->setPackCurrent_Byte1(messageToParse[4]);
    orionModel->setPackCurrent_Byte2(messageToParse[5]);
    orionModel->setAverageOpenCellVoltage_Byte1(messageToParse[6]);
    orionModel->setAverageOpenCellVoltage_Byte2(messageToParse[7]);
}


//all of the get functions for the Orion Controller
//this is where the calculations from the raw data are done
/** 
 * @brief  Retrieve state of charge of the pack as a percent
 * @note   Range is 0-100%
 * @retval State of charge of the pack
 */
float OrionController::getStateOfCharge(void)
{
    //return the state of charge of the pack to the stateOfCharge_Byte divided by 2
    return (float)orionModel->getStateOfCharge_Byte() / 2.0;
}


/** 
 * @brief  Retrieve state of health of the pack as a percent
 * @note   Range is 0-100%
 * @retval State of health of the pack
 */
uint8_t OrionController::getStateOfHealth(void)
{
    //get the state of health of the battery pack by returning the stateOfHealth_Byte without modification
    return orionModel->getStateOfHealth_Byte();
}


/** 
 * @brief  Retrieve highest cell temperature of the pack
 * @note   Range is 0-255 degrees Celcius
 * @retval Highest cell temperature in the pack
 */
uint8_t OrionController::getHighestCellTemp(void)
{
    //get the highest temperature of the pack by returning the highestCellTemp_Byte without modification
    return orionModel->getHighestCellTemp_Byte();
}


/** 
 * @brief  Retrieve average cell temperature of the pack
 * @note   Range is 0-255 degrees Celcius
 * @retval Average cell temperature for the pack
 */
uint8_t OrionController::getAverageCellTemp(void)
{
    
    //get the average temperature of the pack by returning the averageCellTemp_Byte without modification
    return orionModel->getAverageCellTemp_Byte();
}


/** 
 * @brief  Retrieve max open cell voltage of the pack
 * @note   Range is 0-6.5535 volts
 * @retval Max open cell voltage value
 */
float OrionController::getMaxOpenCellVoltage(void)
{
    //return the max open cell voltage by building a 16-bit value from maxOpenCellVoltage_Byte 1 and 2 dividing by 10,000
    uint16_t maxOpenCellVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    maxOpenCellVoltage = (uint16_t)orionModel->getMaxOpenCellVoltage_Byte1() << 8;
    //OR in the second byte
    maxOpenCellVoltage |= (uint16_t)orionModel->getMaxOpenCellVoltage_Byte2();
    //now divide this value by 10,000 for the actual voltage and return it
    return (float)maxOpenCellVoltage / 10000.0;
}


/** 
 * @brief  Retrieve minimum open cell voltage of the pack
 * @note   Range is 0-6.5535 volts
 * @retval Min open cell voltage value
 */
float OrionController::getMinOpenCellVoltage(void)
{
    //return the min open cell voltage by building a 16-bit value from minOpenCellVoltage_Byte 1 and 2 dividing by 10,000
    uint16_t minOpenCellVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    minOpenCellVoltage = (uint16_t)orionModel->getMinOpenCellVoltage_Byte1() << 8;
    //OR in the second byte
    minOpenCellVoltage |= (uint16_t)orionModel->getMinOpenCellVoltage_Byte2();
    //now divide this value by 10,000 for the actual voltage and return it
    return (float)minOpenCellVoltage / 10000.0;
}


/** 
 * @brief  Retrieve the discharge current limit of the pack
 * @note   Range is 0-65535 amps
 * @retval Discharge current limit value
 */
uint16_t OrionController::getPackDischargeCurrentLimit(void)
{
    //get the discharge current limit of the pack by taking the value of packDischargeCurrentLimit_Byte 1 and 2 with no further modification
    //to do this, the packDischargeCurrentLimit has to be built from the two bytes into a 16 bit value
    uint16_t packDischargeCurrentLimit = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    packDischargeCurrentLimit = (uint16_t)orionModel->getPackDischargeCurrentLimit_Byte1() << 8;
    //OR in the second byte
    packDischargeCurrentLimit |= (uint16_t)orionModel->getPackDischargeCurrentLimit_Byte2();
    //return the discharge current limit value
    return packDischargeCurrentLimit;
}

/** 
 * @brief  Retrieve total open pack voltage of the pack to use for the 90% pre-charge setting
 * @note   Range is 0-6553.5 volts
 * @retval total voltage of all batteries
 */
float OrionController::getPackVoltage(void)
{
    //to get the pack open voltage, the packOpenVoltage has to be built from the two bytes from the model into a 16 bit value
    uint16_t packOpenVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    packOpenVoltage = (uint16_t)orionModel->getPackOpenVoltage_Byte1() << 8;
    //OR in the second byte
    packOpenVoltage |= (uint16_t)orionModel->getPackOpenVoltage_Byte2();
    //now divide this value by 10 and return it
    return (float)packOpenVoltage / 10.0;
}


/** 
 * @brief  Retrieve the output current of the pack
 * @note   Range is 0-6553.5 amps
 * @retval Output current value of the pack
 */
float OrionController::getPackCurrent(void)
{
    //get the the output current of the pack to the value of packCurrent_Byte 1 and 2 divided by 10
    //to do this, the packCurrent has to be built from the two bytes into a 16 bit value
    uint16_t packCurrent = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    packCurrent = (uint16_t)orionModel->getPackCurrent_Byte1() << 8;
    //OR in the second byte
    packCurrent |= (uint16_t)orionModel->getPackCurrent_Byte2();
    //now divide this value by 10 and return the value
    return (float)packCurrent / 10.0;
}


/** 
 * @brief  Retrieve average open cell voltage of the pack
 * @note   Range is 0-6.5335 volts
 * @retval Average open cell voltage value
 */
float OrionController::getAverageOpenCellVoltage(void)
{
    //get the average open cell voltage of the pack by building it from averageOpenCellVoltage_Byte 1 and 2 and divide by 10,000
    //to do this, the averageOpenCellVoltage has to be built from the two bytes into a 16 bit value
    uint16_t averageOpenCellVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    averageOpenCellVoltage = (uint16_t)orionModel->getAverageOpenCellVoltage_Byte1() << 8;
    //OR in the second byte
    averageOpenCellVoltage |= (uint16_t)orionModel->getAverageOpenCellVoltage_Byte2();
    //now divide this value by 10,000 and set it in the model
    return (float)averageOpenCellVoltage / 10000.0;
}
