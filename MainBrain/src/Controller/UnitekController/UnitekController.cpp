/**  Operates the logic around controlling the Unitek motor controller
 *
 * UnitekController.cpp
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */

#include "UnitekController.hpp"


//to see if the instance of the class has been initialized yet
UnitekController* UnitekController::_pInstance = NULL; 

/** 
 * @brief  Used to maintain the singleton format
 * @note   
 * @retval 
 */
UnitekController* UnitekController::getInstance()
{
    // Only allow one instance of class to be generated.
    if (!_pInstance)
        _pInstance = new UnitekController();

    return _pInstance;
}


/** 
 * @brief  UnitekController destructor
 * @note   Delete any instantiated varibles/objects
 * @retval None
 */
UnitekController::~UnitekController(void)
{
    delete unitekModel;
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekController::init(void)
{
    unitekModel = new Unitek();
}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekController::poll(void)
{

}


/** 
 * @brief  
 * @note   
 * @retval None
 */
void UnitekController::shutdown(void)
{
    
}


/** 
 * @brief  Convert RPM to a compatible MC speed value
 * @note   The speed value represents a percentage from 0 to 0x7FFF
 *         That percentage represents the RPM from 0 to RPM_LIMIT (Ex: 7000)
 * @param  rpm: RPM value
 * @retval      Speed value for the MC
 */
int UnitekController::calculateSpeedValue(float rpm)
{
    float percentage = rpm / unitekModel->getRpmLimit();
    return percentage * unitekModel->MAX_VALUE;
}


/** 
 * @brief  Convert a given MC speed value to RPM
 * @note   
 * @param  speedValue: Given from MC
 * @retval             RPM value
 */
float UnitekController::calculateRpm(int speedValue)
{
    float percentage = (float)speedValue / unitekModel->MAX_VALUE;
    return percentage * unitekModel->getRpmLimit();
}


/** 
 * @brief  calculate numeric speed value to send to the MC
 * @note   percent will be calculate by getPercentageGas() in PedalController
 * @param  percent: is the gas pedal percentage pressed
 * @retval 16 bit value that will be sent over CAN to control motor
 */
uint16_t UnitekController::calculateSpeedSetPoint(float percent)
{
    uint16_t rpmSetPoint = unitekModel->MAX_VALUE * percent;
    return rpmSetPoint;
}


 /**  
 * @brief  calculate the numerical 90 charge to send to MC
 * @note   
 * @param  batteryVoltage: total battery voltage 
 * @retval numeric value for 90% charge
 */
uint16_t UnitekController::calculate90Charge(float batteryVoltage)
{
    //batteryPercent is based off of internal unitek where 32767=2*VMains
    float batteryPercent = batteryVoltage / (float)unitekModel->VOLTAGE_MAX; 
    //batteryVoltageNumeric gives the battery voltage on scale of 0-32767
    float batteryVoltageNumeric = batteryPercent * (float)unitekModel->MAX_VALUE;
    //finds 90% of numeric battery voltage
    float percent90Charge = 0.9 * batteryVoltageNumeric;
    return (uint16_t)percent90Charge;
}


 /**  
 * @brief calculate the numerical percentage based off Unitek Numeric/Voltage constant
 * @note   
 * @param  batteryVoltage: total battery voltage 
 * @retval numeric value for given voltage
 */
uint16_t UnitekController::convertVoltageToNumeric(float batteryVoltage)
{
    //we don't care about the decimals in this calculation
    return batteryVoltage * unitekModel->NUMERIC_PER_VOLTAGE;
}

/** 
 * @brief  used to store the recieved speed value from CAN
 * @note   
 * @param  RpmSpeed: recieved numeric value from MC that is converted to RPMs using calculateRPM
 * @retval None
 */
void  UnitekController::storeRpmSpeedValue(float RpmSpeed)
{
    unitekModel->setSpeedValueFromUnitek(RpmSpeed);
}


/** 
 * @brief  stores rpm limit if we ever need to change it
 * @note   should only ever be used if we implement reverse mode
 * @param  RpmLimit: new RPM limit that should have been set in MC
 * @retval None
 */
void UnitekController::storeRpmLimit(uint16_t RpmLimit)
{
    unitekModel->setRpmLimit(RpmLimit);
}


/** 
 * @brief  stores error register value
 * @note   
 * @param  errorReg: recieved value of error reg from CAN
 * @retval None
 */
void UnitekController::storeErrorReg(uint16_t errorReg)
{
    unitekModel->setErrorReg_0x8F(errorReg);
}


/** 
 * @brief  stores warning register value
 * @note   
 * @param  warningReg: recieved value of wanring reg from CAN
 * @retval None
 */
void UnitekController::storeWarningReg(uint16_t warningReg)
{
    unitekModel->setWarningReg_0x8F(warningReg);
}


/** 
 * @brief  store state register value
 * @note   
 * @param  stateReg: recieved value of state reg from CAN
 * @retval None
 */
void UnitekController::storeStateReg(uint16_t stateReg)
{
    unitekModel->setStateReg_0x40(stateReg);
}


/** 
 * @brief  store mode register value
 * @note   
 * @param  modeReg: received value of mode reg from CAN
 * @retval None
 */
void UnitekController::storeModeReg(uint16_t modeReg)
{
    unitekModel->setModeReg_0xD8(modeReg);
}


/** 
 * @brief  store voltage value of hv bus 
 * @note   value is in unitek resolution
 * @param  HvBus: received value of HV bus from CAN
 * @retval None
 */
void UnitekController::storeVoltageHvBus(uint8_t* messageToParse)
{
    //FIXME: convert to logger call instead of Serial.print
    Serial.println((messageToParse[2] << 8) | messageToParse[1]);
    unitekModel->setHvBus((messageToParse[2] << 8) | messageToParse[1]);

}


uint16_t UnitekController::getHvBusNumeric(void)
{
    return unitekModel->getHvBus();
}


/** 
 * @brief  store speed value that is sent to MC
 * @note   value is in unitek resolution
 * @param  speedCmdValue: value calculated from pedal press percentage 
 * @retval None
 */
void UnitekController::storeSpeedValueForUnitek(uint16_t speedCmdValue)
{
    unitekModel->setSpeedValueForUnitek(speedCmdValue);
}


/** 
 * @brief  store speed value that is recieved from MC
 * @note   value is RPM resolution (confirm)
 * @param  speedValue: value received from MC over CAN
 * @retval None
 */
void UnitekController::storeSpeedValueFromUnitek(uint16_t speedValue)
{
    unitekModel->setSpeedValueFromUnitek(speedValue);
}


/** 
 * @brief  store temperature of the motor
 * @note   value will be in unitek resolution
 * @param  motorTemp: temp value recieved from MC over can
 * @retval None
 */
void UnitekController::storeTemperatureMotor(uint16_t motorTemp)
{
    unitekModel->setTemperatureMotor(motorTemp);
}


/** 
 * @brief  stores temperature of the output stage
 * @note   value will be in unitek resolution
 * @param  outputTemp: temp value of output stage recieved from MC
 * @retval None
 */
void UnitekController::storeTempOutputStage(uint16_t outputTemp)
{
    unitekModel->setTemperatureOutputStage(outputTemp);
}


void UnitekController::storeTempInterior(uint16_t interiorTemp)
{
    unitekModel->setTemperatureInterior(interiorTemp);
}


/** 
 * @brief  checks the warning and error registers to see if shutdown is needed
 * @note   prior to using this function update the registers via CAN and store function
 * @retval true if shutdown is needed false otherwise
 */
bool UnitekController::checkErrorWarningForShutdown()
{
    //get latest values of error reg and warning reg
    ErrorReg_0x8F errorReg = unitekModel->getErrorReg_0x8F();
    WarningReg_0x8F warningReg = unitekModel->getWarningReg_0x8F();

    //checks for bad NDrive parameters
    if(errorReg.errorBits.BadParam==1)
    {
        return true;
    }

    //checks for ouput stage fault
    else if(errorReg.errorBits.PowerFault==1)
    {
        return true;
    }

    //checks for tansfer fault bus
    else if(errorReg.errorBits.BusTimeout==1)
    {
        return true;
    }

    //checks for too high motor temperature
    else if(errorReg.errorBits.MotorTemp==1)
    {
        return true;
    }

    //checks for too high MC temperature
    else if(errorReg.errorBits.DeviceTemp==1)
    {
        return true;
    }

    //checks for 1.8*max voltage
    else if(errorReg.errorBits.OverVoltage==1)
    {
        return true;
    }

    //checks for 300% over current
    else if(errorReg.errorBits.IPeak==1)
    {
        return true;
    }

    //checks for power overload
    else if(errorReg.errorBits.I2R==1)
    {
        return true;
    }

    //checks to ensre firware is compatible with hardware
    else if(errorReg.errorBits.HwFail==1)
    {
        return true;
    }

    //checks for current measuring fault
    else if(errorReg.errorBits.AdcInt==1)
    {
        return true;
    }

    //checks for 87% motor temp
    else if(warningReg.warningBits.MotorTemp==1)
    {
        return true;
    }

    //checks for 87% device temp
    else if(warningReg.warningBits.DeviceTemp==1)
    {
        return true;
    }

    //checks for 1.5*max voltage
    else if(warningReg.warningBits.OverVoltage==1)
    {
        return true;
    }

    //if all tests pass then return false and shutdown won't be needed
    else{
        return false;
    }
}
