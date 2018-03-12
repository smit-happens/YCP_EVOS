/**  IMD controller class
 *
 * #include "ImdControllerTest.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef IMDCONTROLLER_HPP
#define IMDCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/Imd/Imd.hpp"



class ImdControllerTest : public BaseControllerTest
{
public:
    ~ImdControllerTest(void);

    static ImdControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    
private:
    //Private contstructor so that it can't be called
    ImdControllerTest() {};
    //copy constructor is private
    ImdControllerTest(ImdControllerTest const&) {};

    //static instance pointer
    static ImdControllerTest* _pInstance;

    //private instance of model
    Imd* imdModel;
};


#endif  //IMDCONTROLLER_HPP
