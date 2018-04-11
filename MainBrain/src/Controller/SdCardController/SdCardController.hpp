/**  Only has knowledge about creating/editing csv files
 *
 * #include "SdCardController.hpp"
 * Created 10-02-17 By: Smitty
 *
 * A longer description.
 */

#ifndef SDCARDCONTROLLER_HPP
#define SDCARDCONTROLLER_HPP

#include "../BaseController/BaseController.hpp"
#include "../../Model/Constants/Constants.hpp"
#include "../../Model/SdCard/SdCard.hpp"
#include "../Logger/Logger.hpp"
#include "../Logger/LogListener.hpp"


/**  
 * Example of possible log file:
 * ╔════════════════════════════╦══════════════╦═══════════════╦═════════════════════════════════════════════════════════╦═════╗
 * ║ Millis since program start ║ Category     ║ Calling Class ║ Message                                                 ║ ... ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ 1145                       ║ Notification ║ Unitek        ║ No errors/warnings found                                ║     ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ 1650                       ║ Warning      ║ Orion         ║ Average cell temperature of 45°C close to limit of 60°C ║     ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ 1776                       ║ Error        ║ CoolingSystem ║ Pump is not turned on!                                  ║     ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ ...                        ║ ...          ║ ...           ║ ...                                                     ║     ║
 * ╚════════════════════════════╩══════════════╩═══════════════╩═════════════════════════════════════════════════════════╩═════╝
 */

//class LogListener;

class SdCardController  : public BaseController, public LogListener
{
public:
    ~SdCardController(void);

    static SdCardController*   getInstance();

    void init(void);
    void poll(void);
    void shutdown(void);    //TODO: implement
    

    /** 
     * Drafting up possible functions
     * writeHeader()
     * newColumn()
     * newRow()
     * newCell()
     * 
     * millisSinceStart()
     */


private:
    //Private contstructor so that it can't be called
    SdCardController() {};
    //copy constructor is private
    SdCardController(SdCardController const&) {};

    //static instance pointer
    static SdCardController* _pInstance;

    //private instance of model
    SdCard* sdCardModel;

    void onLogFiled(char* key, char* message,  msg_type type);

};

#endif  //SDCARDCONTROLLER_HPP
