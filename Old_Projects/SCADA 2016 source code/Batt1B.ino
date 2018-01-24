
#define END_OF_LINE 10
#include "DataComm.h"
#define inputsize 25

float input[inputsize];
DataComm* comm;
unsigned long lastlog;

void setup() {
  // put your setup code here, to run once:
  comm = new DataComm();
  
  for (int i = 0;  i < inputsize; i++)
  {
    if(i < inputsize/2)
    {
      input[i] = 29.88;
    }
    else
    {
      input[i] = 3.4;
    }
  }
  lastlog = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  comm->checkForCommand();
  
  if(millis() - lastlog > 250)
  {
    input[inputsize - 1] = millis();
    for(int i = 1; i <= 4; i++)
    {
        comm->logLine(input, inputsize, i);
    }
    lastlog = millis();
  }
}
