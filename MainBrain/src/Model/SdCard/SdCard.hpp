/**  Handles the hardware level functions of the SdFat library
 *
 * #include "SdCard.hpp"
 * Created 1-5-18  By: Smitty
 *
 * A longer description.
 */


#ifndef SDCARD_HPP
#define SDCARD_HPP

#include "SdFat.h"
#include "../Constants/Port.hpp"
#include "../Constants/Constants.hpp"

//Might need additional methods to flesh out all the functionality



class SdCard
{
public:
    SdCard(void);
    virtual ~SdCard();
    /** 
     * Drafting up possible functions
     * 
     * newFile()
     * newFolder()
     * mount()
     * openFile()
     * 
     * 
     */

    bool beginCard();
    bool openFile();
    bool writeMessage(const char* message, bool writeOut = false);
    void closeFile();

    bool hasCardBegun();
    bool isFileOpen();
private:
    uint32_t writeCount; //buffered write counter.
    const uint32_t WRITE_THRESH = 2; //how many buffered writes before we sync the card. 
    const char* FILE_BASE_NAME = "EVOS_LOG";
    bool hasBegun;
    bool fileOpen;
    void determineFileName(char*);
    char mFileName[13];
    SdFatSdioEX* sdEx;
    SdFile logFile;

};


#endif  //SDCARD_HPP
