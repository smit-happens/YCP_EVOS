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
    bool writeMessage(const char* message);
    void closeFile();

    bool hasCardBegun();
    bool isFileOpen();
private:
    bool hasBegun;
    bool fileOpen;
    char mFileName[13];
    SdFatSdioEX* sdEx;
    SdFile logFile;

};


#endif  //SDCARD_HPP
