/**  DashControllerTest manages all the buttons and forms of user feedback/input to the EV
 *
 * #include "DashControllerTest.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef DASHCONTROLLER_HPP
#define DASHCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/Light/Light.hpp"
#include "../../Model/Button/Button.hpp"
#include "../../Model/Siren/Siren.hpp"


class DashControllerTest : public BaseControllerTest
{
public:
    ~DashControllerTest(void);

    static DashControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


private:
    //Private contstructor so that it can't be called
    DashControllerTest() {};
    //copy constructor is private
    DashControllerTest(DashControllerTest const&) {};

    //static instance pointer
    static DashControllerTest* _pInstance;

    //private instance of model
    /*
        //all the buttons need to be implemented
        Button* shutdownBtn;
    */ 
};


#endif  //DASHCONTROLLER_HPP
