//Created by Smitty :D
//7-28-17

#include <FlexCAN.h>
#include <TimerOne.h>

const char *menuMain =
  "\nWelcome to EVOS!\n"
  "Select an option to continue\n"
  "0: Show main menu\n"
  "1: Send a CAN message\n"
  "2: Blink an LED\n";

const char *menuCAN =
  "\nSelect an option to continue\n"
  "0: Back to main menu\n"
  "1: Read a value from MC\n"
  "2: Set a value in the MC\n";

char rx_byte;
bool ledState = HIGH;
bool blinking = false;

//CAN stuffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff

static CAN_message_t msgON;

static uint8_t hex[17] = "0123456789abcdef";

class CANClass : public CANListener 
{
public:
   void printFrame(CAN_message_t &frame, int mailbox);
   //overrides the parent version so we can actually do something
   void gotFrame(CAN_message_t &frame, int mailbox); 

   void testFunc(void);
};


void CANClass::printFrame(CAN_message_t &frame, int mailbox)
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


void CANClass::gotFrame(CAN_message_t &frame, int mailbox)
{
    printFrame(frame, mailbox);
}


void CANClass::testFunc()
{
  Serial.println(F("YCP EV YAY! :("));
}


CANClass CANMessage;

//End CAN stufffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff


//TODO: put CAN option stuff here (call from) case 1
void case1()
{
  bool caseCAN = true;
  
  //discard anything more than one char long
  while (Serial.available() > 0) 
    Serial.read();
  
  Serial.print(F(menuCAN));
  Serial.print("\n");
  while(caseCAN)
  {
    if (Serial.available() > 0) 
    {
      rx_byte = Serial.read();
  
      //discard anything more than one char long
      while (Serial.available() > 0) 
        Serial.read();
      
      Serial.print("You typed: ");
      Serial.println(rx_byte);
      
      switch(rx_byte)
      {
        case '0':
          Serial.print(F("Main Menu\n"));
          caseCAN = false;
        break;
        
        case '1':
          Serial.print(F("Case 1\n"));
          
        break;
        
        case '2':
          Serial.print(F("Case 2\n"));
          
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
void setup() 
{ 
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }

  //status LED on pin 13
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ledState); 

  Can0.begin(500000);  
  Can1.begin(500000);

  Can1.attachObj(&CANMessage);
  CANMessage.attachGeneralHandler();
  
  Serial.println(F(menuMain));

  msgON.ext = 0;
  msgON.id = 0x201;
  msgON.len = 3;
  msgON.buf[0] = 0xd1;
  msgON.buf[1] = 2;
  msgON.buf[2] = 100;

  Can0.write(msgON);

  CANMessage.testFunc();
  
}


//Main menu for the program
void loop() {
if (Serial.available() > 0) 
  {
    rx_byte = Serial.read();

    //discard anything more than one char long
    while (Serial.available() > 0) 
      Serial.read();
    
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
