/**  Display controller class
 *
 * #include "GlcdControllerTest.hpp"
 * Created 1-5-17 By: Smitty
 *
 * A longer description.
 */

#ifndef GLCDCONTROLLER_HPP
#define GLCDCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/Glcd/Glcd.hpp"



class GlcdControllerTest : public BaseControllerTest
{
public:
    ~GlcdControllerTest(void);

    static GlcdControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


private:
    //Private contstructor so that it can't be called
    GlcdControllerTest() {};
    //copy constructor is private
    GlcdControllerTest(GlcdControllerTest const&) {};

    //static instance pointer
    static GlcdControllerTest* _pInstance;

    //private instance of model
    Glcd* glcdModel;
};


#endif  //GLCDCONTROLLER_HPP
