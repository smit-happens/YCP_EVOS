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
}

SdCard::~SdCard(void)
{
    //TODO: close card?
    if(fileOpen)
    {
        closeFile();
    }
}

bool SdCard::beginCard()
{
    if(!sdEx->begin()){
        Logger::getInstance()->log("SD_CARD", "Could not Initalize SD card",  MSG_ERR);
        sdEx->initErrorHalt();
        hasBegun = false;
        return false;
    } 
   Logger::getInstance()->log("SD_CARD", "SD card Initalized",  MSG_LOG);
    hasBegun = true;
    return true;
}

bool SdCard::openFile()
{
    //TODO: load in files from root dir and sift through them. Create a file 1 newer than last
    if(!logFile.open("test.csv", O_RDWR | O_CREAT)){
        Logger::getInstance()->log("SD_CARD", "Could not Open SD file",  MSG_ERR);
        fileOpen = false;
        return false;
    }
    Logger::getInstance()->log("SD_CARD", "SD file opened",  MSG_LOG);
    fileOpen = true;
    return true;
}

bool SdCard::writeMessage(const char* message)
{
    if(logFile.println(message)< 0) //if write successful
    {
        Logger::getInstance()->log("SD_CARD", "SD Write Error",  MSG_ERR);
        return false;
    }
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