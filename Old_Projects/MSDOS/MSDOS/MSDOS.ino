#include <Arduino.h>

//Created by Smitty :D
//7-28-17

#include <FlexCAN.h>
#include <TimerOne.h>
#include "MCRegIDs.h"

const char *menuMain =
  "\nWelcome to EVOS!\n"
  "Select an option to continue\n"
  "0: Show main menu\n"
  "1: Send a CAN message\n"
  "2: Blink an LED\n";

const char *menuCAN =
  "\nSelect a CAN option\n"
  "0: Back to main menu\n"
  "1: Set a value in the MC\n"
  "2: Read a value from MC\n"
  "3: Configure MC register for polling *TODO*\n";

const char *readMCRegMenu =
  "\nSelect a register to read from\n"
  "0: Back to CAN menu\n"
  "1: ERROR/warnings\n"
  "2: Various internal states\n"
  "3: Digital PORT\n"
  "4: RUN status\n"
  "5: BTB relay status\n"
  "6: Internal GO status\n"
  "7: High Voltage line value\n"
  "8: RPM limit\n"
  "9: Current speed amount\n"
  "A: Temperature of the motor\n"
  "B: Temperature inside the MC\n";

const char *setMCRegMenu =
  "\nSelect a register to set\n"
  "0: Back to CAN menu\n"
  "1: Speed value in RPM\n"
  "2: RPM limit\n"
  "3: Comparison value 1\n"
  "4: Comparison value 2\n"
  "5: Comparison value 3\n"
  "6: Comparison value 4\n"
  "7: Temperature limit for the motor\n";

char rx_byte;
bool ledState = HIGH;
bool blinking = false;


//CAN stuffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff

class CANClass : public CANListener
{
public:
   void printFrame(CAN_message_t &frame, int mailbox);
   //overrides the parent version so we can actually do something
   void gotFrame(CAN_message_t &frame, int mailbox);

   void testFunc(void);
   CAN_message_t setupMCMessage(uint8_t regID, uint8_t buf1, uint8_t buf2 = 0x00, bool polling = false);

};


void CANClass::printFrame(CAN_message_t &frame, int mailbox)
{
   Serial.print("This just in!\n");
   Serial.print("ID: 0x");
   Serial.print(frame.id, HEX);

   //Print regID from buf[0]
   Serial.print(" RegID: 0x");
   Serial.print(frame.buf[0], HEX);

   //Print value from register in reverse byte order
   Serial.print(" Data: 0x");
   Serial.print(frame.buf[2], HEX);
   Serial.print(frame.buf[1], HEX);

   Serial.write('\n');
}


void CANClass::gotFrame(CAN_message_t &frame, int mailbox)
{
    printFrame(frame, mailbox);
}


void CANClass::testFunc()
{
  Serial.println(F("YCP EV is making me go crazy! "));
}


//helper function cause I use this too much
void clearSerialBuf()
{
  //discard anything within the buffer
  while (Serial.available() > 0)
    Serial.read();
}


CAN_message_t setupMCMessage(uint8_t regID, uint8_t buf1 = 0x00, uint8_t buf2 = 0x00, bool stopPolling = false)
{
  CAN_message_t tx;

  tx.ext = 0;
  tx.id = 0x201;
  tx.len = 3;

  if(regID == REG_READ)
  {
    //performing a read operation set buf[0] to READ command
    tx.buf[0] = REG_READ;
    tx.buf[1] = buf1;

    //default is 0 but can represent time (in ms) for polling
    tx.buf[2] = buf2;

    //deactivates polling
    if(stopPolling)
    {
      tx.buf[2] = REG_HALTPOLL;
    }
  }
  else
  {
    //performing write opration
    tx.buf[0] = regID;

    //storing the value in byte flipped order
    tx.buf[2] = buf1;
    tx.buf[1] = buf2;
  }

  return tx;
}


CANClass CANMessage;

//End CAN stufffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff


//confirmation message from user
bool confirmPopUp(CAN_message_t message)
{
  bool feedback = false;
  bool waitingOnUser = true;

  clearSerialBuf();

  Serial.print(F("\nAre you sure you want to send: \n"));
  Serial.print("ID: 0x");
  Serial.print(message.id, HEX);

  //Print regID from buf[0]
  Serial.print(" RegID: 0x");
  Serial.print(message.buf[0], HEX);

  //Print value from register in reverse byte order
  Serial.print(" Data: 0x");
  Serial.print(message.buf[2], HEX);
  Serial.print(message.buf[1], HEX);

  Serial.print(F("\ny/n? "));


  while(waitingOnUser)
  {
    if (Serial.available() > 0)
    {
      rx_byte = Serial.read();

      //discard anything more than one char long
      clearSerialBuf();

      switch(rx_byte)
      {
        case '0':
        case 'N':
        case 'n':
          feedback = false;
          //No long waiting on user
          waitingOnUser = false;
        break;

        case '1':
        case 'Y':
        case 'y':
          feedback = true;
          //No long waiting on user
          waitingOnUser = false;
        break;

        default:
          Serial.print(F("Invalid syntax\n"));
          Serial.print(F("\ny/n? "));
        break;
      }
    }
  }
  Serial.println(rx_byte);

  return feedback;
}


//for validation on user input for setting correct values of registers
uint16_t setValInput()
{
  bool waitingOnUser = true;

  uint8_t rx_byte;
  char userInput[6];
  uint8_t index = 0;

  uint16_t registerVal = 0x0000;

  //make sure the buffer is clear before reading in any values
  clearSerialBuf();

  Serial.print(F("\nEnter the value you want to send (in base 10)\n"));
  Serial.print(F("Type 'D' when done\n"));
  while(waitingOnUser)
  {
    if (Serial.available() > 0)
    {
      rx_byte = Serial.read();

      //input validation
      switch(rx_byte)
      {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
          if(index<6)
          {
            userInput[index] = rx_byte;
            index++;
          }
          else
          {
             Serial.print(F("Number is too large! Try again\n"));
             //make sure there aren't any remaining characters in the buffer
             clearSerialBuf();
             index = 0;
          }
        break;

        case 'd':
        case 'D':
          //the user has completed their number
          waitingOnUser = false;
          //just incase
          clearSerialBuf();
        break;

        default:
          Serial.print(F("ENTER A NUMBER DOOFUS\n"));
        break;
      }

    }//end if(serial.available())
  }

  //convert user string into integer values
  registerVal = atoi(userInput);

  return registerVal;
}


//Mostly working (need to check for certain but seems okay now)
//function for setting a register value in the MC
void setMCReg()
{
  bool caseSetMCReg = true;
  bool defaultCase;
  uint8_t regID;
  uint16_t value = 0;


  //discard anything more than one char long from prev call
  clearSerialBuf();

  Serial.print(F(setMCRegMenu));
  Serial.print("\n");
  while(caseSetMCReg)
  {
    if (Serial.available() > 0)
    {
      rx_byte = Serial.read();

      //discard anything more than one char long
      clearSerialBuf();

      //assume the user doesn't trigger the default condition
      defaultCase = false;

      switch(rx_byte)
      {
        case '0':
          Serial.print(F("CAN Menu\n"));
          caseSetMCReg = false;
        break;

        case '1':
          Serial.print(F("REG_SPEEDVAL\n"));
          regID = REG_SPEEDVAL;
        break;

        case '2':
          Serial.print(F("REG_SPEEDLIM\n"));
          regID = REG_SPEEDLIM;
        break;

        case '3':
          Serial.print(F("REG_VAR1\n"));
          regID = REG_VAR1;
        break;

        case '4':
          Serial.print(F("REG_VAR2\n"));
          regID = REG_VAR2;
        break;

        case '5':
          Serial.print(F("REG_VAR3\n"));
          regID = REG_VAR3;
        break;

        case '6':
          Serial.print(F("REG_VAR4\n"));
          regID = REG_VAR4;
        break;

        case '7':
          Serial.print(F("REG_MTEMPLIM\n"));
          regID = REG_MTEMPLIM;
        break;

        default:
          Serial.print(F("Invalid syntax\n"));
          Serial.print(F(setMCRegMenu));
          defaultCase = true;
        break;
      }

      if(caseSetMCReg && !defaultCase)
      {
        value = setValInput();

        Serial.println(value);

        CAN_message_t txMessage = setupMCMessage(regID, (uint8_t)(value >> 8), (uint8_t)value);

        //send message if the user confirms they want to send it
        if(confirmPopUp(txMessage))
          Can1.write(txMessage);

        Serial.print(F(setMCRegMenu));
      }

      Serial.print("\n");
    }
  }
}


//user interaction for reading registers over CAN
void readMCReg()
{
  bool caseReadMCReg = true;
  bool defaultCase;

  //register that the user chooses to read
  uint8_t regID;

  //discard anything more than one char long from prev call
  clearSerialBuf();

  Serial.print(F(readMCRegMenu));
  Serial.print("\n");
  while(caseReadMCReg)
  {
    if (Serial.available() > 0)
    {
      rx_byte = Serial.read();

      //discard anything more than one char long
      clearSerialBuf();

      defaultCase = false;

      switch(rx_byte)
      {
        case '0':
          Serial.print(F("CAN Menu\n"));
          caseReadMCReg = false;
        break;

        case '1':
          Serial.print(F("REG_ERROR\n"));
          regID = REG_ERROR;
        break;

        case '2':
          Serial.print(F("REG_STATE\n"));
          regID = REG_STATE;
        break;

        case '3':
          Serial.print(F("REG_DPORT\n"));
          regID = REG_DPORT;
        break;

        case '4':
          Serial.print(F("REG_RUN\n"));
          regID = REG_RUN;
        break;

        case '5':
          Serial.print(F("REG_BTB\n"));
          regID = REG_BTB;
        break;

        case '6':
          Serial.print(F("REG_GO\n"));
          regID = REG_GO;
        break;

        case '7':
          Serial.print(F("REG_HVBUS\n"));
          regID = REG_HVBUS;
        break;

        case '8':
          Serial.print(F("REG_SPEEDLIM\n"));
          regID = REG_SPEEDLIM;
        break;

        case '9':
          Serial.print(F("REG_SPEEDRN\n"));
          regID = REG_SPEEDRN;
        break;

        case 'a':
        case 'A':
          Serial.print(F("REG_TEMPM\n"));
          regID = REG_TEMPM;
        break;

        case 'b':
        case 'B':
          Serial.print(F("REG_TEMPAIRMC\n"));
          regID = REG_TEMPAIRMC;
        break;

        default:
          Serial.print(F("Invalid syntax\n"));
          Serial.print(F(readMCRegMenu));
          defaultCase = true;
        break;
      }

      if(caseReadMCReg && !defaultCase)
      {
        CAN_message_t txMessage = setupMCMessage(REG_READ, regID);
        Can1.write(txMessage);

        Serial.print(F(readMCRegMenu));
      }

      Serial.print("\n");
    }
  }
}


//CAN option stuff here called from case 1
void case1()
{
  bool caseCAN = true;

  //discard anything more than one char long
  clearSerialBuf();

  //printing the options of CAN to the user
  Serial.print(F(menuCAN));
  Serial.print("\n");
  while(caseCAN)
  {
    if (Serial.available() > 0)
    {
      rx_byte = Serial.read();

      //discard anything more than one char long
      clearSerialBuf();

      switch(rx_byte)
      {
        case '0':
          Serial.print(F("Main Menu\n"));
          caseCAN = false;
        break;

        case '1':
          Serial.print(F("Case 1: set a val\n"));
          setMCReg();
          Serial.print(F(menuCAN));
        break;

        case '2':
          Serial.print(F("Case 2: read a val\n"));
          readMCReg();
          Serial.print(F(menuCAN));
        break;

        case '3':
          Serial.print(F("Case 3: config polling from MC (TODO)\n"));
          Serial.print(F("Not implemented at all lol\n"));
          //configMCPolling();
          Serial.print(F(menuCAN));
        break;

        default:
          Serial.print(F("Invalid syntax\n"));
          Serial.print(F(menuCAN));
        break;
      }
      Serial.print("\n");
    }
  }
}


//blinking an LED using a Timer
void case2()
{
  if(!blinking)
  {
    Timer1.initialize(150000);
    // blinkLED to run every 0.15 seconds
    Timer1.attachInterrupt(blinkLED);
    blinking = true;
  }
  else
  {
    Timer1.stop();
    if(!ledState)
    {
      ledState = !ledState;
      digitalWrite(LED_BUILTIN, ledState);
    }
    blinking = false;
  }
}


//Called from interrupt attached to Timer1
void blinkLED(void)
{
  if (ledState == LOW)
    ledState = HIGH;
  else
    ledState = LOW;

  digitalWrite(LED_BUILTIN, ledState);
}


//setup code executed before anything else
int main(void)
{
  delay(1000);  // wait for serial port to connect
  Serial.begin(9600);

  //status LED on pin 13
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ledState);

  Can1.begin(500000);

  Can1.attachObj(&CANMessage);
  CANMessage.attachGeneralHandler();

  Serial.println(F(menuMain));

  while(1)
    loop();

  return 1;
}


//Main menu for the program
void loop() {

  //Menu system for anything typed into the serial terminal
  if (Serial.available() > 0)
  {
    rx_byte = Serial.read();

    //discard anything more than one char long
    clearSerialBuf();

    Serial.print("You typed: ");
    Serial.println(rx_byte);

    switch(rx_byte)
    {
      case '0':
        Serial.print(F("Case 0\n"));
        Serial.print(F(menuMain));
      break;

      case '1':
        Serial.print(F("Case CAN\n"));
        case1();
        Serial.print(F(menuMain));
      break;

      case '2':
        Serial.print(F("Case 2: LED\n"));
        case2();
      break;

      default:
        Serial.print(F("Invalid syntax\n"));
        Serial.print(F(menuMain));
      break;
    }

    Serial.print("\n");
  }
}
