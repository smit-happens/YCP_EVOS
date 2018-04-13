/**  Handles the hardware level functions of the SdFat library
 *
 * SdCard.cpp
 * Created 1-5-18  By: Smitty
 *
 * A longer description.
 */

#include "SdCard.hpp"
#include "../../Controller/Logger/Logger.hpp"



//FIXME: rip out all the demo code and put into functions

/** 
 * @brief  SdCard constructor
 */
SdCard::SdCard(void)
{
    sdEx = new SdFatSdioEX();
    hasBegun = false;
    fileOpen = false;
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
        Logger::getInstance()->log("SD_CARD", "Could not Initalize SD card",  MSG_ERR);
        //sdEx->initErrorHalt();
        sdEx->errorPrint();
        hasBegun = false;
        return false;
    } 
   Logger::getInstance()->log("SD_CARD", "SD card Initalized",  MSG_LOG);
    hasBegun = true;
    return true;
}

bool SdCard::openFile()
{
    char fileName[30];
    determineFileName(fileName);
    Logger::getInstance()->log("SD_CARD", fileName, MSG_LOG);
    if(!logFile.open(fileName, O_RDWR | O_CREAT)){
        Logger::getInstance()->log("SD_CARD", "Could not Open SD file",  MSG_ERR);
        fileOpen = false;
        return false;
    }
    Logger::getInstance()->log("SD_CARD", "SD file opened",  MSG_LOG);
    fileOpen = true;
    return true;
}

void SdCard::determineFileName(char* buf){
    uint8_t fileNum = 0; //which file we're on
    String fname = String(FILE_BASE_NAME + String(fileNum, DEC) + ".csv"); //construct filename string from filenum
    Logger::getInstance()->log("SD_CARD", fname.c_str(), MSG_LOG); 
    // used to increment the file number until it finds a name we can use for a new file
    while (sdEx->exists(fname.c_str())) {
        fileNum++; //increment the file number since this one exists already
        fname = FILE_BASE_NAME + String(fileNum, DEC) + ".csv";
    }
    
    strcpy(buf, fname.c_str());
}




bool SdCard::writeMessage(const char* message, bool writeOut)
{
    if(logFile.println(message)< 0) //if write successful
    {
        Logger::getInstance()->log("SD_CARD", "SD Write Error",  MSG_ERR);
        return false;
    }
    if(writeOut) {
        Logger::getInstance()->log("SD_CARD", "Writing special warn/error data out",  MSG_DEBUG);
        writeCount = 0;
        if (!logFile.sync() || logFile.getWriteError()) {
            sdEx->errorPrint();
            Logger::getInstance()->log("SD_CARD", "SD Sync Write Error",  MSG_ERR);
        }

    }
    else if(writeCount >= WRITE_THRESH){
        //Logger::getInstance()->log("SD_CARD", "Writing data out",  MSG_DEBUG);
        writeCount = 0;
        if (!logFile.sync() || logFile.getWriteError()) {
            sdEx->errorPrint();
            Logger::getInstance()->log("SD_CARD", "SD Sync Write Error",  MSG_ERR);
        }

    }
    writeCount++;
    return true;
}

void SdCard::closeFile()
{
    logFile.close();
    fileOpen = false;
    Logger::getInstance()->log("SD_CARD", "SD card file closed.", MSG_LOG);
}

bool SdCard::isFileOpen()
{
    return fileOpen;
}

bool SdCard::hasCardBegun()
{
    return hasBegun;
}


// // Log file base name
// #define FILE_BASE_NAME "Smitty"

// //file system object
// SdFatSdioEX sdEx;

// //log file
// SdFile myFile;

// // Time in micros for next data record.
// uint32_t logTime;


// //------------------------------------------------------------------------------
// // Write data header.
// void writeHeader() {
//     myFile.print(F("micros"));
//     for (uint8_t i = 0; i < 4; i++) {
//         myFile.print(F(",adc"));
//         myFile.print(i, DEC);
//     }
//     myFile.println();
// }


// //------------------------------------------------------------------------------
// // Log a data record.
// void logData() {
//     uint16_t data[4];

//     // Read all channels to avoid SD write latency between readings.
//     for (uint8_t i = 0; i < 4; i++) {
//         data[i] = analogRead(i);
//     }
//     // Write data to file.  Start with log time in micros.
//     myFile.print(logTime);

//     // Write data to CSV record.
//     for (uint8_t i = 0; i < 4; i++) {
//         myFile.write(',');
//         myFile.print(data[i]);
//     }
//     myFile.println();
// }


// void setup() {
//     const uint8_t BASE_NAME_SIZE = sizeof(FILE_BASE_NAME) - 1;
//     char fileName[13] = FILE_BASE_NAME "00.csv";

//     Serial.print("Initializing SD card...");
//     if (!sdEx.begin()) {
//         Serial.println("initialization failed!");
//         sdEx.initErrorHalt();
//     }
//     Serial.println("initialization done.");


//     // used to increment the file number
//     while (sdEx.exists(fileName)) {
//         if (fileName[BASE_NAME_SIZE + 1] != '9')
//         fileName[BASE_NAME_SIZE + 1]++;
//         else if (fileName[BASE_NAME_SIZE] != '9')
//         {
//         fileName[BASE_NAME_SIZE + 1] = '0';
//         fileName[BASE_NAME_SIZE]++;
//         } 
//     }

//     if (!myFile.open(fileName, O_CREAT | O_WRITE | O_EXCL)) {
//     }

//     // Data header.
//     writeHeader();
// }


// void loop() {
//     logData();

//     // Force data to SD and update the directory entry to avoid data loss.
//     if (!myFile.sync() || myFile.getWriteError()) {
//         // error("write error");
//     }

//     // Close file
//     myFile.close();
//     Serial.println(F("Done"));
// }