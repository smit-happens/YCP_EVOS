/**  DashController manages all the buttons and forms of user feedback/input to the EV
 *
 * #include "DashController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef DASHCONTROLLER_HPP
#define DASHCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Light/Light.hpp"
#include "../../Model/Button/Button.hpp"
#include "../../Model/Siren/Siren.hpp"


class DashController : public BaseController
{
public:
    ~DashController(void);

    static DashController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


private:
    //Private contstructor so that it can't be called
    DashController() {};
    //copy constructor is private
    DashController(DashController const&) {};

    //static instance pointer
    static DashController* _pInstance;

    //private instance of model
    /*
        //all the buttons need to be implemented
        Button* shutdownBtn;
    */ 
};


#endif  //DASHCONTROLLER_HPP
