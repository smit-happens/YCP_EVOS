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
    Orion::CanData_0x420 *data_0x420;
    // = CanController.getOrionMessage(ID_0x420);
    Orion::CanData_0x421 *data_0x421;// = CanController.getOrionMessage(ID_0x421);
    updateModelMessage_0x420(data_0x420);
    updateModelMessage_0x421(data_0x421);
}

/** 
 * @brief  Parse the message and update the model
 * @note   More explanation of the necessary changes to the values is present in the Orion.hpp in the definitions of the CanData_0x420 and CanData_0x421 structs
 * @param  messageToParse: the most recent CAN message from the BUS with ID = 0x420
 * @retval None
 */
void OrionController::updateModelMessage_0x420(Orion::CanData_0x420 *messageToParse)
{
    //update the stateOfCharge of the pack to the stateOfCharge_Byte divided by 2 
    float newStateOfCharge = (float)messageToParse->stateOfCharge_Byte / 2.0;
    orionModel->setStateOfCharge(newStateOfCharge);

    //update the stateOfHealth of the pack to the stateOfHealth_Byte without modification
    uint8_t newStateOfHealth = messageToParse->stateOfHealth_Byte;
    orionModel->setStateOfHealth(newStateOfHealth);

    //update the highest temperature of the pack to the highestCellTemp_Byte without modification
    uint8_t newHighestCellTemp = messageToParse->highestCellTemp_Byte;
    orionModel->setHighestCellTemp(newHighestCellTemp);

    //update the average temperature of the pack to the averageCellTemp_Byte without modification
    uint8_t newAverageCellTemp = messageToParse->averageCellTemp_Byte;
    orionModel->setAverageCellTemp(newAverageCellTemp);

    //update the max open cell voltage to the value of maxOpenCellVoltage_Byte 1 and 2 divided by 10,000
    //to do this, the newMaxOpenCellVoltage has to be built from the two bytes into a 16 bit value
    uint16_t newMaxOpenCellVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    newMaxOpenCellVoltage = (uint16_t)messageToParse->maxOpenCellVoltage_Byte1 << 8;
    //OR in the second byte
    newMaxOpenCellVoltage |= (uint16_t)messageToParse->maxOpenCellVoltage_Byte2;
    //now divide this value by 10,000 for the actual voltage and set in the model
    orionModel->setMaxOpenCellVoltage((float)newMaxOpenCellVoltage / 10000.0);

    //update the min open cell voltage to the value of minOpenCellVoltage_Byte 1 and 2 divided by 10,000
    //to do this, the newMinOpenCellVoltage has to be built from the two bytes into a 16 bit value
    uint16_t newMinOpenCellVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    newMinOpenCellVoltage = (uint16_t)messageToParse->minOpenCellVoltage_Byte1 << 8;
    //OR in the second byte
    newMinOpenCellVoltage |= (uint16_t)messageToParse->minOpenCellVoltage_Byte2;
    //now divide this value by 10,000 for the actual voltage and set in the model
    orionModel->setMinOpenCellVoltage((float)newMinOpenCellVoltage / 10000.0);

    //the model is now updated with the values from message ID 0x420
}


/** 
 * @brief  Parse the message and update the model
 * @note   More explanation of the necessary changes to the values is present in the Orion.hpp in the definitions of the CanData_0x420 and CanData_0x421 structs
 * @param  messageToParse: the most recent CAN message from the BUS with ID = 0x421
 * @retval None
 */
void OrionController::updateModelMessage_0x421(Orion::CanData_0x421 *messageToParse)
{
    //update the discharge current limit of the pack to the value of packDischargeCurrentLimit_Byte 1 and 2 with no further modification
    //to do this, the newPackDischargeCurrentLimit has to be built from the two bytes into a 16 bit value
    uint16_t newPackDischargeCurrentLimit = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    newPackDischargeCurrentLimit = (uint16_t)messageToParse->packDischargeCurrentLimit_Byte1 << 8;
    //OR in the second byte
    newPackDischargeCurrentLimit |= (uint16_t)messageToParse->packDischargeCurrentLimit_Byte2;
    //update the model with this new discharge current limit value
    orionModel->setPackDischargeCurrentLimit(newPackDischargeCurrentLimit);

    //update the open voltage of the pack to the value of packOpenVoltate_Byte 1 and 2 divided by 10
    //to do this, the newPackOpenVoltage has to be built from the two bytes into a 16 bit value
    uint16_t newPackOpenVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    newPackOpenVoltage = (uint16_t)messageToParse->packOpenVoltage_Byte1 << 8;
    //OR in the second byte
    newPackOpenVoltage |= (uint16_t)messageToParse->packOpenVoltage_Byte2;
    //now divide this value by 10  and set in the model
    orionModel->setPackOpenVoltage((float)newPackOpenVoltage / 10.0);

    //update the pack current to the value of packCurrent_Byte 1 and 2 divided by 10
    //to do this, the newPackCurrent has to be built from the two bytes into a 16 bit value
    uint16_t newPackCurrent = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    newPackCurrent = (uint16_t)messageToParse->packCurrent_Byte1 << 8;
    //OR in the second byte
    newPackCurrent |= (uint16_t)messageToParse->packCurrent_Byte2;
    //now divide this value by 10 and set it in the model
    orionModel->setPackCurrent((float)newPackCurrent / 10.0);

    //update the Average open cell voltage of the pack with the value from averageOpenCellVoltage_Byte 1 and 2 and divide by 10,000
    //to do this, the newAverageOpenCellVoltage has to be built from the two bytes into a 16 bit value
    uint16_t newAverageOpenCellVoltage = 0;
    //build the 16 bit value
    //shift the first byte over by 8
    newAverageOpenCellVoltage = (uint16_t)messageToParse->averageOpenCellVoltage_Byte1 << 8;
    //OR in the second byte
    newAverageOpenCellVoltage |= (uint16_t)messageToParse->averageOpenCellVoltage_Byte2;
    //now divide this value by 10,000 and set it in the model
    orionModel->setAverageOpenCellVoltage((float)newAverageOpenCellVoltage / 10000.0);
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void OrionController::shutdown(void)
{
    //TODO: will we need this? 
}

/** 
 * @brief  gets total pack voltage for 90% pre-charge setting
 * @note   need to determine output type of orion
 * @retval total voltage of all batteries
 */
float OrionController::getPackVoltage(void)
{
    return orionModel->getPackOpenVoltage();
}