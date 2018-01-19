#include <Arduino.h>

#include <FlexCAN.h>

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

static CAN_message_t msgON;
static CAN_message_t msgOFF;
static CAN_message_t msgRD;
//static CAN_message_t msgEVT;

static uint8_t hex[17] = "0123456789abcdef";

class ExampleClass : public CANListener 
{
public:
   void printFrame(CAN_message_t &frame, int mailbox);
   //overrides the parent version so we can actually do something
   void gotFrame(CAN_message_t &frame, int mailbox); 
};

void ExampleClass::printFrame(CAN_message_t &frame, int mailbox)
{
   Serial.print("ID: ");
   Serial.print(frame.id, HEX);
   Serial.print(" Data: ");
   for (int c = 0; c < frame.len; c++) 
   {
      Serial.print(frame.buf[c], HEX);
      Serial.write(' ');
   }
   Serial.write('\r');
   Serial.write('\n');
}

void ExampleClass::gotFrame(CAN_message_t &frame, int mailbox)
{
    printFrame(frame, mailbox);
}

ExampleClass exampleClass;

// -------------------------------------------------------------
void setup(void)
{
//  Serial.begin(9600);
  delay(1000);  //wait for serial monitor to open
  Serial.println(F("Hello Teensy 3.6 dual CAN Test With Objects."));

  //status LED on pin 13
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); 

  Can0.begin(500000);  
  Can1.begin(500000);

  Can1.attachObj(&exampleClass);
  exampleClass.attachGeneralHandler();

  msgON.ext = 0;
  msgON.id = 0x201;
  msgON.len = 3;
  msgON.buf[0] = 0xd1;
  msgON.buf[1] = 2;
  msgON.buf[2] = 100;
//the MC receives this as 0x64 0x02 0xD1
//need to send values to store in registers in reverse-byte format
//this means I have to send it with the value bytes swapped
//EX: 0x02 0x64 -> 0x64 0x02

  msgOFF.ext = 0;
  msgOFF.id = 0x201;
  msgOFF.len = 3;
  msgOFF.buf[0] = 0xd1;
  msgOFF.buf[1] = 0;
  msgOFF.buf[2] = 0;

//  msgRD.ext = 0;        //no can extended IDs
//  msgRD.id = 0x201;     //id of MC
//  msgRD.len = 3;        //length of message (in bytes)
//  msgRD.buf[0] = 0x3d;  //Read command
//  msgRD.buf[1] = 0x59;  //Register to read from (RPM limit in this case)
//  msgRD.buf[2] = 0;     //blank

  //NOTE: MC sends information in reverse byte order with RegID first
  //      EX: 59 70 17 0 => 0x1770 (6000)
  //ID of MC is 0x181 when it tx's

  //Constant sending test
  msgRD.ext = 0;        //no can extended IDs
  msgRD.id = 0x201;     //id of MC
  msgRD.len = 3;        //length of message (in bytes)
  msgRD.buf[0] = 0x3d;  //Read command
  msgRD.buf[1] = 0xd8;  //Register to poll (mode bit)
  msgRD.buf[2] = 0x64;  //Amount of time b/t value tranfsers (100ms)
//  //msgRD.buf[2] = 0xff;  //Value to stop the transmission of data

  //Event based reading test
//  msgEVT.ext = 0;        //no can extended IDs
//  msgEVT.id = 0x201;     //id of MC
//  msgEVT.len = 3;        //length of message (in bytes)
//  msgEVT.buf[0] = 0x51;  //Event command
//  msgEVT.buf[1] = 0x10;  //
//  msgEVT.buf[2] = 0;     //blank
  
  

  Serial.println(F("Type any character to start"));
  while (!Serial.available()) {
    
  }
  Serial.println(F("Starting test"));
  Can0.write(msgON);
  

//  Serial.println(F("Type any character to send a message"));
//  while (!Serial.available()) {
//    
//  }
//  Serial.println(F("Sending message"));
//  Can0.write(msgEVT);

}


// -------------------------------------------------------------
void loop(void)
{
//  Serial.println(F("Type 'a' character to start"));
//  while (Serial.read() != 'a') {
//    
//  }
//  Serial.println(F("Starting test"));
//  timeStart = micros();
//  Can0.write(msgRD);
//  delay(100);
  
//  Can0.write(msgON);
//  delay(500);
//  Can0.write(msgOFF);
//  delay(500);
}
