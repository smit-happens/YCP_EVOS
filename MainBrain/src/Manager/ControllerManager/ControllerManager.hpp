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
    //Getters for the controller pointers
    static BatlogController*    getBatlogC(void);
    static CanController*       getCanC(void);
    static CoolingController*   getCoolingC(void);
    static DashController*      getDashC(void);
    static GlcdController*      getGlcdC(void);
    static ImdController*       getImdC(void);
    static OrionController*     getOrionC(void);
    static PedalController*     getPedalC(void);
    static SdCardController*    getSdCardC(void);
    static UnitekController*    getUnitekC(void);


private:
    // Controller Pointer declarations for singletons
    static BatlogController*       batlogC;
    static CanController*       canC;
    static CoolingController*   coolingC;
    static DashController*      dashC;
    static GlcdController*      glcdC;
    static ImdController*       imdC;
    static OrionController*     orionC;
    static PedalController*     pedalC;
    static SdCardController*    sdCardC;
    static UnitekController*    unitekC;
};

#endif  //CONTROLLERMANAGER_HPP