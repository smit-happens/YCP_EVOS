/**
 * Testing for CAN communication with the BMS
 * 
 * main.cpp
 * Created 2/20/2018 by: Shawn
 * 
 * 
 **/

#include <Arduino.h>
#include "FlexCAN.h"



void setup() {
  pinMode(PIN_A0, OUTPUT);  //SCADA Nominal
  pinMode(PIN_A1, OUTPUT);  //precharge
  pinMode(PIN_A2, OUTPUT);  //90% charge from teensy (shouldn't be needed)
  pinMode(PIN_A3, OUTPUT);  //SCADA Drive
  pinMode(PIN_A9, INPUT);   //start and stop push button
  pinMode(PIN_A8, INPUT); //90% charge signal from MC
  pinMode(PIN_A14, INPUT);  //pot input

  
  Serial.begin(9600);

  Can0.begin(500000);  
  

}

void loop() 
{
    Serial.println("Polling the BMS");

    CAN_message_t maxCellPoll;
    maxCellPoll.ext=0;        // 
    maxCellPoll.id=0x7E3;    // this is the ID of the max cell count register
    maxCellPoll.len=0x04;        // the register is 1 byte long
    maxCellPoll.buf[0]=0x22;  //sets the mode for the CAN message
    maxCellPoll.buf[1]=0xF0;
    maxCellPoll.buf[2]=0x06;

    Can0.write(maxCellPoll);
    delay(1000);

    CAN_message_t maxCellResponse; 
    Can0.read(maxCellResponse);
    
   

    //BMS transmit to request address is 0x7E3
    //BMS transmit to get response from BMS is 0x7EB
    Serial.print("ID:");
    Serial.println(maxCellResponse.id, HEX);
    Serial.print("len:");
    Serial.println(maxCellResponse.len, HEX);

    for(int i = 0; i < 8; i++)
    {
        Serial.print("buf[");
        Serial.print(i);
        Serial.print("]");
         Serial.println(maxCellResponse.buf[i], HEX);
    }
}