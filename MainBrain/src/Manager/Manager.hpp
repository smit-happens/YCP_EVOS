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

//Calling the constructor of each controller (Has to be after class declaration)
//NOTE: Do NOT perform complex functions or anything harder than
//      memory allocation in constructor
UnitekController* Manager::unitekC = new UnitekController();
CanController* Manager::canC = new CanController();

/** 
 * TODO: Initialize the pointers for the other controllers 
 * PedalController* Manager::pedalC = new PedalController();
 * 
 * 
 */

#endif  //MANAGER_HPP