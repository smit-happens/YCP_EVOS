/**  OrionController manages all data processing for the Orion BMS
 *
 * #include "OrionController.hpp"
 * Created 2-2-18 By: Smitty
 *
 * A longer description.
 */

#ifndef ORIONCONTROLLER_HPP
#define ORIONCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Orion/Orion.hpp"


class OrionController
{
public:
    OrionController();
    ~OrionController(void);

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


    /**  
     * Drafting up possible functions
     * 
     * 
     */
private:
    Orion* orionModel;

};


#endif  //ORIONCONTROLLER_HPP
