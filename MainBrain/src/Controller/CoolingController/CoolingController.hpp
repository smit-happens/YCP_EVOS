/**  Cooling controller class
 *
 * #include "CoolingController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef COOLINGCONTROLLER_HPP
#define COOLINGCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/CoolingSystem/CoolingSystem.hpp"


class CoolingController : public BaseController
{
public:
    ~CoolingController(void);

    static CoolingController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    
private:
    //Private contstructor so that it can't be called
    CoolingController() {};
    //copy constructor is private
    CoolingController(CoolingController const&) {};

    //static instance pointer
    static CoolingController* _pInstance;

    //private instance of model
    CoolingSystem* coolingModel;
};


#endif  //COOLINGCONTROLLER_HPP
