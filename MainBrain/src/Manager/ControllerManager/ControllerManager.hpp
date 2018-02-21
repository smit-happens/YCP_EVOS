/**  Handles all the pointers of the controller singletons
 *
 * #include "ControllerManager.hpp"
 * Created 1-21-18  By: Smitty
 *
 * A longer description.
 */

#ifndef CONTROLLERMANAGER_HPP
#define CONTROLLERMANAGER_HPP

#include "../../Controller/Controller.hpp"


class ControllerManager
{
public:
    //ONLY CALL THIS FROM MAIN, NOWHERE ELSE EVER
    void initControllers(void);

    static ControllerManager*   getInstance();

    //Getters for the controller pointers
    BatlogController*    getBatlogC(void);
    CanController*       getCanC(void);
    CoolingController*   getCoolingC(void);
    DashController*      getDashC(void);
    GlcdController*      getGlcdC(void);
    ImdController*       getImdC(void);
    OrionController*     getOrionC(void);
    PedalController*     getPedalC(void);
    SdCardController*    getSdCardC(void);
    UnitekController*    getUnitekC(void);


private:
    // Controller Pointer declarations for singletons
    BatlogController*    batlogC;
    CanController*       canC;
    CoolingController*   coolingC;
    DashController*      dashC;
    GlcdController*      glcdC;
    ImdController*       imdC;
    OrionController*     orionC;
    PedalController*     pedalC;
    SdCardController*    sdCardC;
    UnitekController*    unitekC;

    //Private contstructor so that it can't be called
    ControllerManager() {};

    //copy constructor is private
    ControllerManager(ControllerManager const&) {};
    //assignment operator (should be) private
    // ControllerManager& operator=(ControllerManager const&) {};
    //static instance pointer
    static ControllerManager* _pInstance;

};

#endif  //CONTROLLERMANAGER_HPP