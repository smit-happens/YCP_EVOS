/**  LightController manages all the lights and light states
 *
 * #include "LightController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef LIGHTCONTROLLER_HPP
#define LIGHTCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Light/Light.hpp"


class LightController : public BaseController
{
public:
    ~LightController(void);

    static LightController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void) {};


private:
    //Private contstructor so that it can't be called
    LightController() {};
    //copy constructor is private
    LightController(LightController const&) {};

    //static instance pointer
    static LightController* _pInstance;

    //private instance of model
    Light* light;

};


#endif  //LightController_HPP
