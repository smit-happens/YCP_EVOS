/**
 * Blink
 *
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"
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

void loop() {
  Serial.println("Push start/stop button to begin pre-charge");
  while(digitalRead(PIN_A9)==0){
    //Do nothing, just poll
    //once push button is pressed precharge will start
  }
  
  digitalWrite(PIN_A0, HIGH); //send SCADA Nominal high

  Serial.println("SCADA Nominal is High "); // Ask what SCADA Nominal should be

  delay(1000);
  
  digitalWrite(PIN_A1, HIGH); //send precharge high
  
  Serial.println("Pre-Charge is High"); // Ask what Pre-Charge should be

  delay(1000);
  Serial.println("Waiting for signal from MC...");

  //wait for 90% charge signal to come back as being high
  while(digitalRead(PIN_A8)==0){
    //wait for 90% charge signal to come back as high
  }
  Serial.println("Charge signal from MC recieved");


  digitalWrite(PIN_A3, HIGH); //send SCADA Drive high
    
  Serial.println("SCADA Drive is High"); // Ask what SCADA Drive should be

  delay(1000);

  Serial.println("Motor can be be spun. Push the start/stop button when ready to power down.");

  //while loop to control motor
  CAN_message_t speedWrite;
  while(digitalRead(PIN_A9)==0){
    Serial.println("Within Loop");
    float potValue=analogRead(PIN_A14); //read numeric value of pot
    //Serial.println(potValue);
    float rpmPercent=(potValue-1)/(float)1022; //create RPM percentage based off of potValue
    float rpmSetPoint=(float)32767*rpmPercent; //determine rpm setpoint based off percent of numeric value 32767
    uint16_t CANrpmSetPoint=(int)rpmSetPoint;  //change float value(used for potential polling) into an int value for MC

    //start CAN writing
    //Serial.println((uint8_t)(CANrpmSetPoint >> 8));
    //Serial.println((uint8_t)(CANrpmSetPoint));

    
    speedWrite.ext=0;
    speedWrite.id=0x201;
    speedWrite.len=3;
    speedWrite.buf[0]=0x31;
    speedWrite.buf[1]=(uint8_t)CANrpmSetPoint;
    speedWrite.buf[2]=(uint8_t)(CANrpmSetPoint >> 8);

    // Serial.print(speedWrite.buf[1]);
    // Serial.print("   ");
    // Serial.println(speedWrite.buf[2]);

    Can0.write(speedWrite); 

  }
  //SET RPM TO 0
  CAN_message_t speedZero;

  speedZero.ext=0;
  speedZero.id=0x201;
  speedZero.len=3;
  speedZero.buf[0]=0x31;
  speedZero.buf[1]=0;
  speedZero.buf[2]=0;

  Can0.write(speedZero);

  //shut down 
  Serial.println("Stop button pressed. Shutting Down.");
  
  //set scada nominal low
  digitalWrite(PIN_A0, LOW);
  Serial.println("SCADA Nominal is now off.");
  delay(1000);

  //set precharge low
  digitalWrite(PIN_A1, LOW);
  Serial.println("Pre-Charge is now off.");
  delay(1000);

  //set Scada drive off
  digitalWrite(PIN_A3, LOW);
  Serial.println("SCADA Drive is now off.");
  delay(1000);

  
  
}

