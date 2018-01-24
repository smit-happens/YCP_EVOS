
#ifndef DataComm_h
#define DataComm_h

#include "Arduino.h"
#include <SD.h>
#define END_OF_LINE 10

class DataComm
{
    private:
    
    String foldername;
    bool recordData;
    void importCalled();
    void instantData(int box);
    void sendData(String filename);

    public:

    String box1;
    String box2;
    String box3;
    String box4;
    DataComm();
    void checkForCommand();
    void makeNewDataFile();
    void logLine(float* input, int dataLength, int box); //input is the array of data you want to log, dataLength is the length of input, and filename should be the name of the file you want to log to
};

#endif
