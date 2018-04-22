/**  OrionController manages all data processing for the Orion BMS
 *
 * #include "OrionController.hpp"
 * Created 2-2-18 By: Smitty
 *
 * A longer description.
 */

#ifndef ORIONCONTROLLER_HPP
#define ORIONCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Orion/Orion.hpp"


class OrionController : public BaseController
{
public:
    ~OrionController(void);

    static OrionController*   getInstance();

    void init(void);

    //private functions to parse the CAN messages
    void updateModelMessage_0x420(uint8_t* messageToParse);
    void updateModelMessage_0x421(uint8_t* messageToParse);


    //all of the public get functions
    //gets for values from message 0x420
    float getStateOfCharge(void);
    uint8_t getStateOfHealth(void);
    uint8_t getHighestCellTemp(void);
    uint8_t getAverageCellTemp(void);
    float getMaxOpenCellVoltage(void);
    float getMinOpenCellVoltage(void);
    
    //gets for values from message 0x421
    uint16_t getPackDischargeCurrentLimit(void);
    float getPackVoltage(void);
    float getPackCurrent(void);
    float getAverageOpenCellVoltage(void);

private:
    //Private contstructor so that it can't be called
    OrionController() {};
    //copy constructor is private
    OrionController(OrionController const&) {};

    //static instance pointer
    static OrionController* _pInstance;

    //private instance of model
    Orion* orionModel;

};


#endif  //ORIONCONTROLLER_HPP
