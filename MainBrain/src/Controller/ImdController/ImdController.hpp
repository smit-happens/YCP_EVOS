/**  IMD controller class
 *
 * #include "ImdController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef IMDCONTROLLER_HPP
#define IMDCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Imd/Imd.hpp"



class ImdController : public BaseController
{
public:
    ~ImdController(void);

    static ImdController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    
private:
    //Private contstructor so that it can't be called
    ImdController() {};
    //copy constructor is private
    ImdController(ImdController const&) {};

    //static instance pointer
    static ImdController* _pInstance;

    //private instance of model
    Imd* imdModel;
};


#endif  //IMDCONTROLLER_HPP
