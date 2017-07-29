//Created by Smitty :D
//7-28-17

#include <TimerOne.h>

const char *menu =
  "\nWelcome to EVOS!\n"
  "Select an option to continue\n"
  "0: Menu\n"
  "1: Send a CAN message\n"
  "2: Blink an LED\n\n";

char rx_byte;
bool ledState = HIGH;
bool ledBlink = false;

void blinkLED(void)
{
  if (ledState == LOW)
    ledState = HIGH;
  else 
    ledState = LOW;
    
  digitalWrite(LED_BUILTIN, ledState);
}

void setup() 
{
  //status LED on pin 13
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, ledState); 
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect
  }
  
  Serial.print(F(menu));
  
}

void loop() {
  if (Serial.available() > 0) 
  {
    rx_byte = Serial.read();
    
    Serial.print("You typed: ");
    Serial.println(rx_byte);
    
    switch(rx_byte)
    {
      case '0':
        Serial.print(F("Case 0\n"));
        Serial.print(F(menu));
      break;
      
      case '1':
        Serial.print(F("Case 1\n"));
        
        
      break;
      
      case '2':
        Serial.print(F("Case 2: LED\n"));
        if(!ledBlink) 
        {
          Timer1.initialize(150000);
          // blinkLED to run every 0.15 seconds
          Timer1.attachInterrupt(blinkLED); 
          ledBlink = true;
        }
        else
        {
          Timer1.stop();
          if(ledState)
          {
            ledState = !ledState;
            digitalWrite(LED_BUILTIN, ledState);
          }
          ledBlink = false;
        }
          
      break;
      
      default:
        Serial.print(F("Invalid syntax\n"));
      break; 
    }

    Serial.print("\n");
    
    //discard anything more than one char long
    while (Serial.available() > 0) 
      Serial.read();
  }
}
