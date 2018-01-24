/**  Handles all the pointers of the model singletons
 *
 * #include "ModelManager.hpp"
 * Created 1-23-18  By: Smitty
 *
 * A longer description.
 */

#ifndef MODELMANAGER_HPP
#define MODELMANAGER_HPP

#include "../Model.hpp"

class ModelManager
{
public:
    //Getters for the controller pointers
    static Can* getCanM(void);
    static Unitek* getUnitekM(void);

    /** 
     * TODO: Initialize the pointers for the other controllers 
     * static PedalController* getPedalC(void);
     * 
     * 
     */

private:
    // Controller Pointer declarations for singletons
    static Can* canM;
    static Unitek* unitekM;

    /** 
     * TODO: Initialize the pointers for the other controllers 
     * static PedalController* pedalC;
     * 
     * 
     */
};

#endif  //MODELMANAGER_HPP