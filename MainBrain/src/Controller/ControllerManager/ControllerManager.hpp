/**  Handles all the pointers of the controller singletons
 *
 * #include "ControllerManager.hpp"
 * Created 1-21-18  By: Smitty
 *
 * A longer description.
 */

#ifndef CONTROLLERMANAGER_HPP
#define CONTROLLERMANAGER_HPP

#include "../Controller.hpp"

class ControllerManager
{
public:
    //Getters for the controller pointers
    static CanController* getCanC(void);
    static UnitekController* getUnitekC(void);

    /** 
     * TODO: Initialize the pointers for the other controllers 
     * static PedalController* getPedalC(void);
     * 
     * 
     */

private:
    // Controller Pointer declarations for singletons
    static CanController* canC;
    static UnitekController* unitekC;

    /** 
     * TODO: Initialize the pointers for the other controllers 
     * static PedalController* pedalC;
     * 
     * 
     */
};

#endif  //CONTROLLERMANAGER_HPP