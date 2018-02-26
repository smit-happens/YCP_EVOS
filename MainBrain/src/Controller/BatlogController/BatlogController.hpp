/**  Handles any calculations or logical calculations involving the GLV batteries
 *
 * #include "BatlogController.hpp"
 * Created 2-6-18 By: Smitty
 *
 * A longer description.
 */

#ifndef BATLOGCONTROLLER_HPP
#define BATLOGCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Batlog/Batlog.hpp"


class BatlogController : public BaseController
{
public:
    ~BatlogController(void);

    static BatlogController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


private:
    //Private contstructor so that it can't be called
    BatlogController() {};
    //copy constructor is private
    BatlogController(BatlogController const&) {};

    //static instance pointer
    static BatlogController* _pInstance;

    //private instance of model
    Batlog* batlogModel;

};


#endif  //BATLOGCONTROLLER_HPP
