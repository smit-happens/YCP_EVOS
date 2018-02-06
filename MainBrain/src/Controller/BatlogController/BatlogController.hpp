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


class BatlogController
{
public:
    BatlogController();
    ~BatlogController(void);

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement


    /**  
     * Drafting up possible functions
     * 
     * 
     */
private:
    Batlog* batlogModel;

};


#endif  //BATLOGCONTROLLER_HPP
