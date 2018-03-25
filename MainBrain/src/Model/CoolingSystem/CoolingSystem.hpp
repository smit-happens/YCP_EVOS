/**  A one line description of the class.
 *
 * #include "CoolingSystem.hpp"
 * Created 12-20-17  By: Smitty
 *
 * A longer description.
 */

#ifndef COOLINGSYSTEM_HPP
#define COOLINGSYSTEM_HPP

#include "../BaseModel/BaseModel.hpp"

class CoolingSystem : public BaseModel
{
public:
    CoolingSystem(void);
    ~CoolingSystem(void);

    void update(void);

    uint16_t getInletValue(void);
    uint16_t getOutletValue(void);

    //TODO: add functions for operation of pump control

    bool isPumpOn(void) { return _pumpState; };

    void pumpOn(void);
    void pumpOff(void);

private:
    uint16_t _inletTemperature;
    uint16_t _outletTemperature;

    bool _pumpState = false;
};


#endif  //COOLINGSYSTEM_HPP