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
#include "../../Model/SdCard/SdCard.hpp"
#include "../Logger/Logger.hpp"
#include "../Logger/LogListener.hpp"


/**  
 * Example of possible log file:
 * ╔════════════════════════════╦══════════════╦═══════════════╦═════════════════════════════════════════════════════════╦═════╗
 * ║ Millis since program start ║ Category     ║ Calling Class ║ Message                                                 ║ ... ║
 * ╠════════════════════════════╬══════════════╬═══════════════╬═════════════════════════════════════════════════════════╬═════╣
 * ║ 1145                       ║ Log          ║ Unitek        ║ No errors/warnings found                                ║     ║
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
    ~SdCardController(void) { delete sdCardModel; };

    static SdCardController*   getInstance();

    void init(void);
    void shutdown(void);
    bool isCardWorking();

    /** 
     * Drafting up possible functions
     * writeHeader()
     * newColumn()
     * newRow()
     * newCell()
     * 
     * millisSinceStart()
     */
    void onLogFiled(const char* key, const char* message,  msg_type type);


private:
    const uint8_t MSG_STR_BUF_LEN = 100;
    const char* DELIM = "|"; //NOTE this MUST be of length 1!!

    //Private contstructor so that it can't be called
    SdCardController() {};
    //copy constructor is private
    SdCardController(SdCardController const&) {};

    //static instance pointer
    static SdCardController* _pInstance;

    //private instance of model
    SdCard* sdCardModel;

    void setupLogFileHeader();
};

#endif  //SDCARDCONTROLLER_HPP
