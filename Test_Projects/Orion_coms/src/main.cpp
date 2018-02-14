#include <Arduino.h>
#include "FlexCAN.h"

int main(void){
    Serial.begin(9600);
    Can0.begin(500000);

    CAN_message_t testMessage;
    CAN_message_t testResponse;

    testMessage.id = 0x7E3;
    testMessage.ext = 8;  
    testMessage.len = 3;
    testMessage.buf[0] = 0x22;
    testMessage.buf[1] = 0xF0;
    testMessage.buf[2] = 0x0D; 

    Can0.write(testMessage);

    Serial.println("sent message: ");
    Serial.print(testMessage.id);
    Serial.print(testMessage.ext);
    Serial.print(testMessage.len);
    Serial.print(testMessage.buf[0]);
    Serial.print(testMessage.buf[1]);
    Serial.print(testMessage.buf[2]);
    Serial.println("\n");

    delay(2000);

    Can0.read(testResponse);

    Serial.println("recieved ");
    Serial.print(testResponse.id);
    Serial.print(testResponse.ext);
    Serial.print(testResponse.len);
    Serial.print(testResponse.buf[0]);
    Serial.print(testResponse.buf[1]);
    Serial.print(testResponse.buf[2]);
    Serial.println("\n");

    return 0;
}