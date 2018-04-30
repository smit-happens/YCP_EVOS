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



class SdCard
{
public:
    SdCard(void);
    virtual ~SdCard();

    bool beginCard();
    bool openFile();
    bool writeMessage(const char* message, bool writeOut = false);
    void closeFile();

    bool hasCardBegun();
    bool isFileOpen();

    char* getFileName(void);

private:
    uint32_t writeCount; //buffered write counter.
    const uint32_t WRITE_THRESH = 2; //how many buffered writes before we sync the card. 
    const char* FILE_BASE_NAME = "EVOS_LOG";
    char fileName[30];
    bool hasBegun = false;
    bool fileOpen = false;
    SdFatSdioEX* sdEx;
    SdFile logFile;

    void determineFileName(void);

};


#endif  //SDCARD_HPP
