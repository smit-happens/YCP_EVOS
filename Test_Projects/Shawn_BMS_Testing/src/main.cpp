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

  //this is the CAN speed of the Orion BMS
  Can1.begin(250000);  


  pinMode(LED_BUILTIN, OUTPUT);         //indicator light
  digitalWriteFast(LED_BUILTIN, HIGH);

}

void loop() 
{
    Serial.println("Polling the BMS");


    //this was an attempt to send a specific message to the BMS, maybe it will be useful later
    // CAN_message_t maxCellPoll;
    // maxCellPoll.ext=0;        
    // maxCellPoll.id=0x7E3;    // this is the ID of the BMS
    // maxCellPoll.len=0x02;    // the register is 1 byte long
    // maxCellPoll.buf[0]=0xF0; //this is the first half of the PID for the max cell count register
    // maxCellPoll.buf[1]=0x06; //this is the second half of the PID for the max cell count registe
    // Can1.write(maxCellPoll);


    delay(1000);

    //this is the message that is populated with the CAN message from the network
    CAN_message_t messageFromNetwork; 

    Serial.print("\nCurrent available messages: ");
    Serial.println(Can1.available());

    //TODO: find out how to read specific CAN messages rather than just anything on the bus
    // int response = Can1.read(messageFromNetwork);
    //if the response from the read function is 0, then there was no message receieved 
    if(Can1.available() == 0)
    {
        Serial.println("There was no message in the buffer");
    }
   
    else 
    {
        Can1.read(messageFromNetwork);

        //the id for the custom messages is 0x420 and 0x421
        //they contain different information about the pack from the BMS
        if(messageFromNetwork.id == 0x420 || messageFromNetwork.id == 0x421)
        {
            //print out the id and length
            Serial.print("ID:");
            Serial.println(messageFromNetwork.id, HEX);
            Serial.print("len:");
            Serial.println(messageFromNetwork.len, HEX);

            //print out the buffer
            for(int i = 0; i < 8; i++)
            {
                Serial.print("buf[");
                Serial.print(i);
                Serial.print("]");
                Serial.println(messageFromNetwork.buf[i], HEX);
            }
        }
    }

}