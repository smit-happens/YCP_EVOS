/**  Operates the logic around controlling the Unitek motor controller
 *
 * #include "UnitekControllerTest.hpp"
 * Created 12-23-17  By: Smitty
 *
 * A longer description.
 */


#ifndef UNITEKCONTROLLER_HPP
#define UNITEKCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/Unitek/Unitek.hpp"


class UnitekControllerTest : public BaseControllerTest
{
public:
    ~UnitekControllerTest(void);

    static UnitekControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    int calculateSpeedValue(float rpm);
    float calculateRpm(int speedValue);

private:
    //Private contstructor so that it can't be called
    UnitekControllerTest() {};
    //copy constructor is private
    UnitekControllerTest(UnitekControllerTest const&) {};

    //static instance pointer
    static UnitekControllerTest* _pInstance;

    //private instance of model
    Unitek* unitekModel;
};


#endif  //UNITEKCONTROLLER_HPP
