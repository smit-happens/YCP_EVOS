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



class ImdController
{
public:
    ImdController();
    ~ImdController(void);

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    /**  
     * Drafting up possible functions
     * 
     * 
     */
private:
    Imd* imdModel;

};


#endif  //IMDCONTROLLER_HPP
