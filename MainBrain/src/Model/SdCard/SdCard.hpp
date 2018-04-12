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

//Might need additional methods to flesh out all the functionality



class SdCard
{
public:
    SdCard(void);

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
    bool writeMessage(char* message);
    void closeFile();
private:
    char mFileName[13];
    SdFatSdioEX* sdEx;
    SdFile logFile;

};


#endif  //SDCARD_HPP
