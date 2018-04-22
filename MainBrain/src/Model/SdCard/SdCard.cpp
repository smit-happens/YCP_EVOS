/**  Handles the hardware level functions of the SdFat library
 *
 * SdCard.cpp
 * Created 1-5-18  By: Smitty
 *
 * A longer description.
 */

#include "SdCard.hpp"


/** 
 * @brief  SdCard constructor
 */
SdCard::SdCard(void)
{
    sdEx = new SdFatSdioEX();
    writeCount = 0;
}


SdCard::~SdCard(void)
{
    if(fileOpen)
    {
        closeFile();
    }
}


bool SdCard::beginCard()
{
    if(!sdEx->begin()){
        sdEx->errorPrint();
        hasBegun = false;
        return false;
    } 
    hasBegun = true;
    return true;
}


bool SdCard::openFile()
{
    determineFileName();
    if(!logFile.open(fileName, O_RDWR | O_CREAT)){
        fileOpen = false;
        return false;
    }
    fileOpen = true;
    return true;
}


void SdCard::determineFileName(){
    uint8_t fileNum = 0; //which file we're on
    String fname = String(FILE_BASE_NAME + String(fileNum, DEC) + ".csv"); //construct filename string from filenum

    //TODO: experiment with saving this number to EEPROM to get rid of this loop
    // used to increment the file number until it finds a name we can use for a new file
    while (sdEx->exists(fname.c_str())) 
    {
        fileNum++; //increment the file number since this one exists already
        fname = FILE_BASE_NAME + String(fileNum, DEC) + ".csv";
    }

    strcpy(fileName, fname.c_str());
}


char* SdCard::getFileName(void)
{
    return fileName;
}


bool SdCard::writeMessage(const char* message, bool writeOut)
{
    if(logFile.println(message)< 0) //if write successful
    {
        // Logger::getInstance()->log("SD_CARD", "SD Write Error",  MSG_ERR);
        return false;
    }
    if(writeOut) 
    {
        // Logger::getInstance()->log("SD_CARD", "Writing special warn/error data out",  MSG_DEBUG);
        writeCount = 0;
        if (!logFile.sync() || logFile.getWriteError()) {
            sdEx->errorPrint();
            // Logger::getInstance()->log("SD_CARD", "SD Sync Write Error",  MSG_ERR);
        }

    }
    else if(writeCount >= WRITE_THRESH)
    {
        //Logger::getInstance()->log("SD_CARD", "Writing data out",  MSG_DEBUG);
        writeCount = 0;
        if (!logFile.sync() || logFile.getWriteError()) 
        {
            sdEx->errorPrint();
            // Logger::getInstance()->log("SD_CARD", "SD Sync Write Error",  MSG_ERR);
        }

    }
    writeCount++;
    return true;
}


void SdCard::closeFile()
{
    logFile.close();
    fileOpen = false;
}


bool SdCard::isFileOpen()
{
    return fileOpen;
}


bool SdCard::hasCardBegun()
{
    return hasBegun;
}
