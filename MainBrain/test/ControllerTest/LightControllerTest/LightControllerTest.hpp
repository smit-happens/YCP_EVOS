/**  LightControllerTest manages all the lights and light states
 *
 * #include "LightControllerTest.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef LightController_HPP
#define LightController_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/Light/Light.hpp"


class LightControllerTest : public BaseControllerTest
{
public:
    ~LightControllerTest(void);

    static LightControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void) {};


private:
    //Private contstructor so that it can't be called
    LightControllerTest() {};
    //copy constructor is private
    LightControllerTest(LightControllerTest const&) {};

    //static instance pointer
    static LightControllerTest* _pInstance;

    //private instance of model
    Light* light;

};


#endif  //LightController_HPP
