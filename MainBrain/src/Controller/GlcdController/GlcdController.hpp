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
#include "../Logger/LogListener.hpp"
#include "../Logger/Logger.hpp"



class GlcdController : public BaseController, public LogListener
{
public:
    ~GlcdController(void);

    static GlcdController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    void justBarelyLogo(void);


private:
    //Private contstructor so that it can't be called
    GlcdController() {};
    //copy constructor is private
    GlcdController(GlcdController const&) {};

    //static instance pointer
    static GlcdController* _pInstance;

    //private instance of model
    Glcd* glcdModel;

    void onLogFiled(const char* key, const char* message,  msg_type type);
};


#endif  //GLCDCONTROLLER_HPP
