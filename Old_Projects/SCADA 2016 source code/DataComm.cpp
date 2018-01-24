#include "Arduino.h"
#include "DataComm.h"
#include <SD.h>
#define END_OF_LINE 10

String foldername;
bool recordData;
String box1;
String box2;
String box3;
String box4;
bool sendInstantData;
int sendDataBox;

DataComm::DataComm()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  int chipSelect = 4;
  sendInstantData = false;
  sendDataBox = 1;

  //Serial.println("Connected");

  if(!SD.begin(chipSelect))
  {
    return;
  }
  makeNewDataFile();
}

void DataComm::checkForCommand ()
{
  if(Serial.available())
  {
    char input;
    input = Serial.read();
    if(input == 'S')
    {
      importCalled();
    }
    else if (input == 'I')
    {
      while(!Serial.available());
      {
        ;
      }
      input = Serial.read();
      instantData(atoi(&input));
    }
  }
}

void DataComm::importCalled()
{
  sendData(box1);
  Serial.write("NEXT");
  sendData(box2);
  Serial.write("NEXT");
  sendData(box3);
  Serial.write("NEXT");
  sendData(box4);
  Serial.write("DONE");
  Serial.write('D');
}

void DataComm::instantData(int box)
{
  sendInstantData = true;
  sendDataBox = box;
}

 void DataComm::makeNewDataFile()
 {
  foldername = "Log";

  int folderint = 0;

  foldername = foldername + String(folderint);

  while(SD.exists(foldername))
  {
    folderint++;
    foldername = "Log" + String(folderint);
  }
  SD.mkdir(foldername);
  box1 = foldername+"/battLog1";
  box2 = foldername+"/battLog2";
  box3 = foldername+"/battLog3";
  box4 = foldername+"/battLog4";
  
  File battLog1 = SD.open(box1, FILE_WRITE);
  File battLog2 = SD.open(box2, FILE_WRITE);
  File battLog3 = SD.open(box3, FILE_WRITE);
  File battLog4 = SD.open(box4, FILE_WRITE);

  recordData = true;

  if(battLog1)
  {
    battLog1.println("Batt1");
    battLog1.close();
  }
  else
  {
    recordData = false;
  }
  if(battLog2)
  {
    battLog2.println("Batt2");
    battLog2.close();
  }
  else
  {
    recordData = false;
  }
  if(battLog3)
  {
    battLog3.println("Batt3");
    battLog3.close();
  }
  else
  {
    recordData = false;
  }
  if(battLog4)
  {
    battLog4.println("Batt4");
    battLog4.close();
  }
  else
  {
    recordData = false;
  }
 }

 void DataComm::logLine(float* input, int dataLength, int box) //input is the array of data you want to log, dataLength is the length of input, and filename should be the name of the file you want to log to
 {
   String filename;
   switch(box)
   {
    case 1: filename = box1; break;
    case 2: filename = box2; break;
    case 3: filename = box3; break;
    case 4: filename = box4; break;
   }
   File dataFile = SD.open(filename, FILE_WRITE);
   
   if(dataFile)
   {
     for(int i = 0; i < dataLength; i++)
     {
         if(i < dataLength - 1)
         {
            dataFile.print(String(input[i]) + ", ");
            if(sendInstantData && sendDataBox == box)
            {
                Serial.print(String(input[i]) + ", ");
            }
         }
         else
         {
            dataFile.println(String(input[i]));
            if(sendInstantData && sendDataBox == box)
            {
                Serial.write('D');
                sendInstantData = false;
            }
         }
     }
     dataFile.close();
   }
 }

void DataComm::sendData(String filename)
{
  File dataFile = SD.open(filename, FILE_READ);
  
  if (dataFile) {
    // read from the file until there's nothing else in it:
    char writeChar;
    int bytesPassed = 0;
    //skip the first line, it's for human readablility
    bool searching = true;

    while(searching)
    {
     writeChar = dataFile.read();
      if(writeChar == '\n')
        {
          searching = false;
        }
    }
    //send the data over
    while (dataFile.available()) {
        writeChar = dataFile.read();
        Serial.write(writeChar);
        bytesPassed++;
        char response;
        if(writeChar == '\n')
        {
            if(bytesPassed >= 200)
            {
                bytesPassed = 0;
                Serial.println("COMPLETION" + String((dataFile.position()*100)/dataFile.size()));
                bool done = false;

                while(!done)
                {
                    while(!Serial.available())
                    {
                        ;
                    }
                    response = Serial.read();
                    if(response == 'N')
                    {
                        done = true;
                    }
                }
            }

            bool done = false;
            while(!done)
            {
                while(!Serial.available())
                {
                    ;
                }
                response = Serial.read();
                if(response == 'N')
                {
                    done = true;
                }
            }
        }
    }
     // close the file:
    dataFile.close();
  }
}

