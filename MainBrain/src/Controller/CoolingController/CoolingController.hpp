/**  Cooling controller class
 *
 * #include "CoolingController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef COOLINGCONTROLLER_HPP
#define COOLINGCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/CoolingSystem/CoolingSystem.hpp"



class CoolingController
{
public:
    CoolingController();
    ~CoolingController(void);

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    /**  
     * Drafting up possible functions
     * 
     * 
     */
private:
    CoolingSystem* coolingModel;

};


#endif  //COOLINGCONTROLLER_HPP
