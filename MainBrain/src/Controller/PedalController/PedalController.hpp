/**  Pedal controller class
 *
 * #include "PedalController.hpp"
 * Created 1-17-17 By: Smitty
 *
 * A longer description.
 */

#ifndef PEDALCONTROLLER_HPP
#define PEDALCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/BrakePedal/BrakePedal.hpp"
#include "../../Model/GasPedal/GasPedal.hpp"


class PedalController
{
public:
    PedalController();
    ~PedalController(void);

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement

    /**  
     * Drafting up possible functions
     * 
     * 
     */
private:
    BrakePedal* brakeModel;
    GasPedal* gasModel;

};


#endif  //PEDALCONTROLLER_HPP
