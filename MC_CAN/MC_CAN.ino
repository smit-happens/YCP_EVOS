/*
 * Object Oriented CAN example for Teensy 3.6 with Dual CAN buses 
 * By Collin Kidder. Based upon the work of Pawelsky and Teachop
 * 
 * Both buses are set to 500k to show things with a faster bus.
 * The reception of frames in this example is done via callbacks
 * to an object rather than polling. Frames are delivered as they come in.
 */

#include <FlexCAN.h>

#ifndef __MK66FX1M0__
  #error "Teensy 3.6 with dual CAN bus is required to run this example"
#endif

static CAN_message_t msgON;
static CAN_message_t msgOFF;
static CAN_message_t msgRD;

static uint8_t hex[17] = "0123456789abcdef";

class ExampleClass : public CANListener 
{
public:
   void printFrame(CAN_message_t &frame, int mailbox);
   void gotFrame(CAN_message_t &frame, int mailbox); //overrides the parent version so we can actually do something
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
  delay(1000);
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
  msgON.buf[1] = 100;
  msgON.buf[2] = 100;

  msgOFF.ext = 0;
  msgOFF.id = 0x201;
  msgOFF.len = 3;
  msgOFF.buf[0] = 0xd1;
  msgOFF.buf[1] = 0;
  msgOFF.buf[2] = 0;

  msgRD.ext = 0;        //no can extended IDs
  msgRD.id = 0x201;     //id of MC
  msgRD.len = 3;        //length of message (in bytes)
  msgRD.buf[0] = 0x3d;  //Read command
  msgRD.buf[1] = 0x59;  //Register to read from
  msgRD.buf[2] = 0;     //blank

  //NOTE: MC sends information in reverse byte order with RegID first
  //      EX: 59 70 17 0 => 0x1770 (6000)
  //ID of MC is 0x181 when it tx's

  

  Serial.println(F("Type any character to start"));
  while (!Serial.available()) {
    
  }
  Serial.println(F("Starting test"));
  Can0.write(msgRD);

}


// -------------------------------------------------------------
void loop(void)
{
//  Can0.write(msgON);
//  delay(500);
//  Can0.write(msgOFF);
//  delay(500);
}
