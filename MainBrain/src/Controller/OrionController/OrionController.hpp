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
    void poll(void);

    void shutdown(void);    //TODO: implement
    float getPackVoltage(void);


private:
    //Private contstructor so that it can't be called
    OrionController() {};
    //copy constructor is private
    OrionController(OrionController const&) {};

    //static instance pointer
    static OrionController* _pInstance;

    //private instance of model
    Orion* orionModel;

    //private functions to parse the CAN messages
    void parseAndUpdateModelMessage_0x420(Orion::CanData_0x420 messageToParse);
    void parseAndUpdateModelMessage_0x421(Orion::CanData_0x421 messageToParse);

};


#endif  //ORIONCONTROLLER_HPP
