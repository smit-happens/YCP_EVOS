/*A test datalogger, based on the included datalogger example*/

#include <SD.h>
#define END_OF_LINE 10

const int chipSelect = 4;
String filename;
bool recordData;
int led;
int battErrLed;
int mcErrLed;
int mcSafety;
int mcRotatingField;
int mcEnable;
String* data1;
String* data2;
bool useData1 = true;
bool pcConnected;

void setup() {
  // put your setup code here, to run once:
  //We wait for the USB serial port to open:
  //Serial.begin(9600,SERIAL_8E1);
  Serial.begin(9600);
  pcConnected = Serial;

  if(pcConnected)
  {
    //Serial.println("Connected!");
  }

  if(!SD.begin(chipSelect))
  {
    if(pcConnected)
    {
      Serial.println("ERROR CHIP SELECT");
    }
    return;
  }

  if(pcConnected)
  {
    //Serial.println("Reached point 1");
  }

  makeNewDataFile();

  if(pcConnected)
  {
    //Serial.println("Reached Point 2");
  }

  data1 = new String;
  data2 = new String;

  pinMode(8, INPUT);
  
  led = 30;
  battErrLed = 31;
  mcErrLed = 32;
  mcSafety = 33;
  mcRotatingField = 34;
  mcEnable = 35;
  pinMode(led, OUTPUT);
  pinMode(battErrLed, OUTPUT);
  pinMode(mcErrLed, OUTPUT);
  pinMode(mcSafety, OUTPUT);
  pinMode(mcRotatingField, OUTPUT);
  pinMode(mcEnable, OUTPUT);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);
  digitalWrite(led, LOW);
  digitalWrite(mcErrLed, LOW);
  digitalWrite(mcEnable, HIGH);
  digitalWrite(mcRotatingField, HIGH);
  digitalWrite(mcSafety, HIGH);
  
  while(digitalRead(20) == HIGH)
  {
    digitalWrite(led, LOW);
    digitalWrite(battErrLed, HIGH);
  }

  digitalWrite(mcSafety, LOW);
  delay(3000);
  digitalWrite(mcRotatingField, LOW);
  delay(3000);
  digitalWrite(mcEnable, LOW);
  
  while(digitalRead(21) == HIGH)
  {
    digitalWrite(led, LOW);
    digitalWrite(mcErrLed, HIGH);
  }
  attachInterrupt(digitalPinToInterrupt(20), battSafetyChanged, CHANGE);
  attachInterrupt(digitalPinToInterrupt(21), mcSafetyChanged, CHANGE);
  
  digitalWrite(led, HIGH);
  if(digitalRead(20) == HIGH)
  {
    battSafetyChanged();
  }
  else
  {
    digitalWrite(battErrLed, LOW);
  }
  if(digitalRead(21) == HIGH)
  {
    mcSafetyChanged();
  }
  else
  {
    digitalWrite(mcErrLed, LOW);
  }

  //Serial.println("Reached Point 3");
  //Serial.println("Filename: " + filename);
  //Serial.println("Entering main loop...")

  //set timer1 interrupt at 4Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 256 prescaler
  TCCR1B |= (1 << CS12);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  beginBatteryConnection();

  //Serial.println("Reached Point 4");
}

void loop() {
  
  // put your main code here, to run repeatedly:

  if((useData1 && data1->length() > 0) || (!useData1 && data2->length() > 0))
  {
    SdWriteData();
  }
  
  if(Serial.available())
  {
    String input = Serial.readStringUntil(END_OF_LINE);
    if(input == "EV CONTROLLER")
    {
      Serial.println("EV Controller");
    }
    else if(input == "MTEMP")
    {
      double value = 500*((double)analogRead(2)/1024.0);
      Serial.println(String(value));
    }
    else if(input == "BRAKE")
    {
      int value = digitalRead(8);
      Serial.println(String(value));
    }
    else if(input == "A")
    {
      double value = (((double)analogRead(1)*100.0)/1024.0);
      Serial.println(String(value));
    }
    else if(input.substring(0,input.length() - 1) == "SENSORS")
    {
      String data = "";
        for(int i = 0; i < 3; i++)
        {
          double value;
          if(i == 2)
          {
            //value = 500*((double)analogRead(analogPin)/1024.0);
            value = digitalRead(8);
          }
          else if(i == 1)
          {
            value = (((double)analogRead(1)*100.0)/1024.0);
          }
          else
          {
            value = value = 500*((double)analogRead(2)/1024.0);
          }
          data += String(value);
          data += ",";
        }
        
        Serial1.write('I');
        Serial1.print(input.substring(input.length() - 1, input.length()));
        char val = 'b';

        unsigned long start = millis();
        while(val != 'D')
        {
          if(Serial1.available())
          {
            start = millis();
            val = Serial1.read();
            if(val != 'D')
            {
              data += val;
            }
          }
          else
          {
            if (millis() - start > 500)
            {
                val = 'D';
                data += '?';
            }
          }
        }
        Serial.println(data);
    }
    else if(input == "IMPORT")
    {
      recordData = false;
      sendData();
    }
    else if(input=="NEWLOG")
    {
        newLog();
    }
    else if(input=="SAFETYRESET")
    {
        safetyReset();
    }
    else
    {
      //Serial.println("Unrecognized command");
      Serial.println("BAD");
    }
  }
}

  ISR(TIMER1_COMPA_vect){
    //interrupt that logs data on timer
    if(recordData)
  {
    String* data;

    if(useData1)
    {
      data = data1;
    }
    else
    {
      data = data2;
    }
    
    for(int i = 1; i < 4; i++)
    {
     double value;
     if(i == 2)
     {
       //value = 500*((double)analogRead(analogPin)/1024.0);
       value = digitalRead(8);
     }
     else if(i == 1)
     {
      value = (((double)analogRead(1)*100.0)/1024.0);
     }
     else
     {
      value = value = 500*((double)analogRead(2)/1024.0);
     }
      *data += String(value);
      *data += ",";
    }

   //timestamp
   *data += String(millis());
}
}

void SdWriteData()
{
  String* data;
  if(useData1)
  {
    useData1 = false;
    data = data1;
  }
  else
  {
    useData1 = true;
    data = data2;
  }
  File dataFile = SD.open(filename, FILE_WRITE);

   if(dataFile)
   {
     dataFile.println(*data);
     dataFile.close();
     *data = "";
   }
   else
   {
    //Serial.println("Error opening file");
    Serial.println("ERROR OPENING FILE IN SD WRITE");
   }
  }

  void sendData()
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
          if(bytesPassed >= 200)
          {
            if(writeChar == '\n')
            {
              bytesPassed = 0;
              Serial.println("COMPLETION" + String((dataFile.position()*100)/dataFile.size()));
            }
          }
        }
         // close the file:
        dataFile.close();

          Serial.println("NEXT");
          importBattData();
        
        Serial.println("END");
      } 
      else 
      {
      // if the file didn't open, print an error:
      Serial.println("ERROR FILE DID NOT OPEN");
      }
  }

  void importBattData()
  {
    Serial1.write('S');
    bool importDone = false;
    
    while(!importDone)
    {
      if(Serial1.available())
      {
         char input = Serial1.read();
         if(input == 'D')
         {
          importDone = true;
         }
         else
         {
            Serial.print(input);
            if(input == '\n')
            {
                Serial1.write('N');
            }
         }
      }
    }
  }

 void beginBatteryConnection()
 {
   Serial1.begin(9600);
  while (!Serial1)
  {
    ; //waiting
  }
 }

 void makeNewDataFile()
 {
  filename = "Log";

  int fileint = 0;

  String extension = ".xlt";

  filename = filename + String(fileint) + extension;

  while(SD.exists(filename))
  {
    fileint++;
    filename = "Log" + String(fileint) + extension;
  }
  File dataFile = SD.open(filename, FILE_WRITE);

  if(dataFile)
  {
    dataFile.println("Accelerator,Brake(1,0),Motor Temp,Time (ms)");
    dataFile.close();
    recordData = true;
  }
  else
  {
    recordData = false;
    if(pcConnected)
    {
     Serial.println("ERROR CREATING FILE"); 
    }
  }
 }

 void newLog()
 {
    if(!recordData)
    {
        Serial.println("CREATING");
        makeNewDataFile();
        recordData = true;
        Serial.println("LOGGING");
    }
    else
    {
        Serial.println("FILE_RECORDING");
    }
 }

 void battSafetyChanged()
 {
    digitalWrite(led, LOW);
    digitalWrite(battErrLed, HIGH);
 }
 void mcSafetyChanged()
 {
    digitalWrite(led, LOW);
    digitalWrite(mcErrLed, HIGH);
 }

 void safetyReset()
 {
    bool unsafe = false;
    if(digitalRead(20) == 0)
    {
        digitalWrite(battErrLed, LOW);
    }
    else
    {
        unsafe = true;
    }
    if(digitalRead(21) == 0)
    {
        digitalWrite(mcErrLed, LOW);
    }
    else
    {
        unsafe = true;
    }
    if(unsafe)
    {
        Serial.println("NOT_SAFE");
    }
    else
    {
        digitalWrite(led, HIGH);
        Serial.println("RESET_COMPLETE");
    }
 }

