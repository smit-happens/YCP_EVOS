/**  Cooling controller class
 *
 * #include "CoolingControllerTest.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef COOLINGCONTROLLER_HPP
#define COOLINGCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/CoolingSystem/CoolingSystem.hpp"


class CoolingControllerTest : public BaseControllerTest
{
public:
    ~CoolingControllerTest(void);

    static CoolingControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    //TODO: implement these
    float getRadiatorTempIn(void);
    float getRadiatorTempOut(void);
    
private:
    //Private contstructor so that it can't be called
    CoolingControllerTest() {};
    //copy constructor is private
    CoolingControllerTest(CoolingControllerTest const&) {};

    //static instance pointer
    static CoolingControllerTest* _pInstance;

    //private instance of model
    CoolingSystem* coolingModel;
};


#endif  //COOLINGCONTROLLER_HPP
