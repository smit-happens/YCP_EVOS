/**  Handles any calculations or logical calculations involving the GLV batteries
 *
 * #include "BatlogControllerTest.hpp"
 * Created 2-6-18 By: Smitty
 *
 * A longer description.
 */

#ifndef BATLOGCONTROLLER_HPP
#define BATLOGCONTROLLER_HPP

#include "../BaseControllerTest/BaseControllerTest.hpp"
#include "../../Model/Batlog/Batlog.hpp"


class BatlogControllerTest : public BaseControllerTest
{
public:
    ~BatlogControllerTest(void);

    static BatlogControllerTest*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


private:
    //Private contstructor so that it can't be called
    BatlogControllerTest() {};
    //copy constructor is private
    BatlogControllerTest(BatlogControllerTest const&) {};

    //static instance pointer
    static BatlogControllerTest* _pInstance;

    //private instance of model
    Batlog* batlogModel;

};


#endif  //BATLOGCONTROLLER_HPP
