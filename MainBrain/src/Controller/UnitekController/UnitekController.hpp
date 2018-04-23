/**  Operates the logic around controlling the Unitek motor controller
 *
 * #include "UnitekController.hpp"
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */


#ifndef UNITEKCONTROLLER_HPP
#define UNITEKCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Unitek/Unitek.hpp"


class UnitekController : public BaseController
{
public:
    ~UnitekController(void);

    static UnitekController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    int calculateSpeedValue(float rpm);
    float calculateRpm(int speedValue);
    uint16_t calculateSpeedSetPoint(float percent);
    uint16_t calculate90Charge(float batteryVoltage);
    uint16_t convertVoltageToNumeric(float batteryVoltage);
    void storeRpmSpeedValue(float RpmSpeed);
    void storeRpmLimit(uint16_t RpmLimit);
    void storeErrorReg(uint16_t errorReg);
    void storeWarningReg(uint16_t warningReg);
    void storeStateReg(uint16_t stateReg);
    void storeModeReg(uint16_t modeReg);
    void storeVoltageHvBus(uint8_t* messageToParse);
    uint16_t getHvBusNumeric(void);
    void storeSpeedValueForUnitek(uint16_t speedCmdValue);
    void storeSpeedValueFromUnitek(uint16_t speedValue);
    void storeTemperatureMotor(uint16_t motorTemp);
    void storeTempOutputStage(uint16_t ouputTemp);
    void storeTempInterior(uint16_t interiorTemp);
    bool checkErrorWarningForShutdown();
    void storeSpeedCalculationFactor(float newSpeedCalculationFactor);

    

private:
    //Private contstructor so that it can't be called
    UnitekController() {};
    //copy constructor is private
    UnitekController(UnitekController const&) {};

    //static instance pointer
    static UnitekController* _pInstance;

    //private instance of model
    Unitek* unitekModel;
};


#endif  //UNITEKCONTROLLER_HPP
