/**  Display controller class
 *
 * #include "GlcdController.hpp"
 * Created 1-5-17 By: Smitty
 *
 * A longer description.
 */

#ifndef GLCDCONTROLLER_HPP
#define GLCDCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Glcd/Glcd.hpp"



class GlcdController : public BaseController
{
public:
    ~GlcdController(void);

    static GlcdController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


private:
    //Private contstructor so that it can't be called
    GlcdController() {};
    //copy constructor is private
    GlcdController(GlcdController const&) {};

    //static instance pointer
    static GlcdController* _pInstance;

    //private instance of model
    Glcd* glcdModel;
};


#endif  //GLCDCONTROLLER_HPP
