/**  OrionControllerTest manages all data processing for the Orion BMS
 *
 * #include "OrionControllerTest.hpp"
 * Created 2-2-18 By: Smitty
 *
 * A longer description.
 */

#ifndef ORIONCONTROLLER_HPP
#define ORIONCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/Orion/Orion.hpp"


class OrionControllerTest : public BaseControllerTest
{
public:
    ~OrionControllerTest(void);

    static OrionControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


private:
    //Private contstructor so that it can't be called
    OrionControllerTest() {};
    //copy constructor is private
    OrionControllerTest(OrionControllerTest const&) {};

    //static instance pointer
    static OrionControllerTest* _pInstance;

    //private instance of model
    Orion* orionModel;

};


#endif  //ORIONCONTROLLER_HPP
