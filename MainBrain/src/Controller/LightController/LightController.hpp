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
    enum LightId 
    {
        LIGHT_RTD,
        LIGHT_ERR_BMS,
        LIGHT_ERR_PEDAL,
        LIGHT_ERR_IMD,
        LIGHT_REVERSE,
        LIGHT_WAYNE,
        LIGHT_ENERGIZE,
        LIGHT_BRAKE,
        NUM_LIGHTS
    };

    ~LightController(void);

    static LightController*   getInstance();

    void init(void);
    void shutdown(void) {};

    //applies to all the lights in the car
    void turnAllOn(void);
    void turnAllOff(void);

    //Turning off all but the errors
    void turnNonErrorOff(void);

    //turning on/off specific lights
    void turnOn(LightId light);
    void turnOff(LightId light);

    void test(void);

private:
    //Private contstructor so that it can't be called
    LightController() {};
    //copy constructor is private
    LightController(LightController const&) {};

    //static instance pointer
    static LightController* _pInstance;

    //private instance of model
    Light* lights[LightId::NUM_LIGHTS];

};


#endif  //LightController_HPP
