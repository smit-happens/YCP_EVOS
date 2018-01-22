/**  Handles all the pointers of the singletons
 *
 * #include "Manager.hpp"
 * Created 1-21-18  By: Smitty
 *
 * A longer description.
 */

#ifndef MANAGER_HPP
#define MANAGER_HPP

#include "../Controller/Controller.hpp"

class Manager
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

#endif  //MANAGER_HPP