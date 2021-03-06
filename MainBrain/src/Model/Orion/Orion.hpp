/**  A one line description of the class.
 *
 * #include "Orion.hpp"
 * Created 10-24-17  By: Smitty
 *
 * A longer description.
 */

#ifndef ORION_HPP
#define ORION_HPP

#include "../BaseModel/BaseModel.hpp"
#include "../Constants/RegistersOrion.hpp"

class Orion : public BaseModel
{
public:
    Orion(void);
    ~Orion(void);

    void update(void);

    //all of the public get functions
    //gets for values from message 0x420
    uint8_t getStateOfCharge_Byte(void);
    uint8_t getStateOfHealth_Byte(void);
    uint8_t getHighestCellTemp_Byte(void);
    uint8_t getAverageCellTemp_Byte(void);
    uint8_t getMaxOpenCellVoltage_Byte1(void);
    uint8_t getMaxOpenCellVoltage_Byte2(void);
    uint8_t getMinOpenCellVoltage_Byte1(void);
    uint8_t getMinOpenCellVoltage_Byte2(void);
    
    //gets for values from message 0x421
    uint8_t getPackDischargeCurrentLimit_Byte1(void);
    uint8_t getPackDischargeCurrentLimit_Byte2(void);
    uint8_t getPackSummedVoltage_Byte1(void);
    uint8_t getPackSummedVoltage_Byte2(void);
    uint8_t getPackCurrent_Byte1(void);
    uint8_t getPackCurrent_Byte2(void);
    uint8_t getAverageOpenCellVoltage_Byte1(void);
    uint8_t getAverageOpenCellVoltage_Byte2(void);

    //all of the public set functions
    //gets for values from message 0x420
    void setStateOfCharge_Byte(uint8_t newStateOfCharge_Byte);
    void setStateOfHealth_Byte(uint8_t newStateOfHealth_Byte);
    void setHighestCellTemp_Byte(uint8_t newHighestCellTemp_Byte);
    void setAverageCellTemp_Byte(uint8_t newAverageCellTemp_Byte);
    void setMaxOpenCellVoltage_Byte1(uint8_t newMaxOpenCellVoltage_Byte1);
    void setMaxOpenCellVoltage_Byte2(uint8_t newMaxOpenCellVoltage_Byte2);
    void setMinOpenCellVoltage_Byte1(uint8_t newMinOpenCellVoltage_Byte1);
    void setMinOpenCellVoltage_Byte2(uint8_t newMinOpenCellVoltage_Byte2);
    
    //gets for values from message 0x421
    void setPackDischargeCurrentLimit_Byte1(uint8_t newPackDischargeCurrentLimit_Byte1);
    void setPackDischargeCurrentLimit_Byte2(uint8_t newPackDischargeCurrentLimit_Byte2);
    void setPackSummedVoltage_Byte1(uint8_t newPackOpenVoltage_Byte1);
    void setPackSummedVoltage_Byte2(uint8_t newPackOpenVoltage_Byte2);
    void setPackCurrent_Byte1(uint8_t newPackCurrent_Byte1);
    void setPackCurrent_Byte2(uint8_t newPackCurrent_Byte2);
    void setAverageOpenCellVoltage_Byte1(uint8_t newAverageOpenCellVoltage_Byte1);
    void setAverageOpenCellVoltage_Byte2(uint8_t newAverageOpenCellVoltage_Byte2);

    //This struct represents the structure of the data present in the CAN message from the BMS with the ID 0x420
    //some of the parameters take more than one byte to represent, therefore they are represented with 2 uint8_t's for byte 1 and 2 of their data
    //Some of the parameters need further modification to represent the readable data, this is marked next to the parameter only on the first byte for the cases where there are multiple
    typedef struct 
    {
        uint8_t stateOfCharge_Byte; //Divide this value by 2 for the actual state of charge (if stateOfCharge_Byte = 100 then the actual SOC is 50%)
        uint8_t stateOfHealth_Byte; //this value requires no modification, it represents the state of health as a percentage
        uint8_t highestCellTemp_Byte; //this value requires no modification, it represents the temperature of the hottest cell in Celcius
        uint8_t averageCellTemp_Byte; //this value requires no modification, it represents the average temperature of the pack in Celcius
        uint8_t maxOpenCellVoltage_Byte1; //This value takes 2 bytes to represent and to get the actual voltage the value needs to be divided by 10,000 (ten-thousand), it represents the max open cell voltage of the pack in volts
        uint8_t maxOpenCellVoltage_Byte2;
        uint8_t minOpenCellVoltage_Byte1; //This value takes 2 bytes to represent and to get the actual voltage the value needs to be divided by 10,000 (ten-thousand), it represents the minimum open cell voltage of the pack in volts
        uint8_t minOpenCellVoltage_Byte2;
    } CanData_0x420;

    //This struct represents the structure of the data present in the CAN message from the BMS with the ID 0x421
    //some of the parameters take more than one byte to represent, therefore they are represented with 2 uint8_t's for byte 1 and 2 of their data
    //Some of the parameters need further modification to represent the readable data, this is marked next to the parameter only on the first byte for the cases where there are multiple
    typedef struct 
    {
        uint8_t packDischargeCurrentLimit_Byte1; //This value takes 2 bytes to represent and requires no modification, it is the discharge current limit represented in amps 
        uint8_t packDischargeCurrentLimit_Byte2; 
        uint8_t packSummedVoltage_Byte1; //This value takes 2 bytes to represent and requires dividing the value by 100 (one-hundred) to get the open voltage of the entire pack in volts
        uint8_t packSummedVoltage_Byte2;
        uint8_t packCurrent_Byte1; //This value takes 2 bytes to represent and requires dividing the value by 10 (ten) to get the current output at the time of the message in amps
        uint8_t packCurrent_Byte2;
        uint8_t averageOpenCellVoltage_Byte1; //This value takes 2 bytes to represent and requires dividing the value by 10,000 (ten-thousand) to get the average open cell voltage of the cells in volts
        uint8_t averageOpenCellVoltage_Byte2;
    } CanData_0x421;


private:
    //private structs used for storing the values for the pack information
    //struct filled with values from CAN message with id 0x420
    CanData_0x420 *data_0x420;
    //struct filled with values from CAN message with id 0x421
    CanData_0x421 *data_0x421;

};


#endif  //ORION_HPP
