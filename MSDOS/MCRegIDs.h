/*************************************************
 * Public Constants
 *************************************************/
//NOTE: All registers are Read Only (RO) unless otherwise stated
//      Write only == SP
//      Read/Write == RW
//NOTE: MC == Unitek Bamocar-D3 Motor Contoller

#define REG_READ       0x3D  //Command to read a register (followed by reg to rd from)

//
#define REG_ERROR      0x8F  //[0:15] Error bits; [16:31] Warning bits
#define REG_DPORT      0xD8  //[0:15] State of all ports on the dig conn. on MC
#define REG_STATE      0x40  //[0:15] Various states of the MC

//Speed oriented registers
#define REG_SPEEDVAL   0x31  //(SP) [0:15] Speed (in RPM) from 0-100% of RPM limit (0x59)
#define REG_SPEEDLIM   0x59  //(RW) [0:15] Speed limit (in RPM) max will be 6000rpm
#define REG_SPEEDRN    0x30  //[0:15] Current speed value right now (RN)

//Digital input/output states
#define REG_DOUT1      0xE0  //[0:1]  State of digital output 1
#define REG_DOUT2      0xE1  //[0:1]  State of digital output 2
//TODO: test what bit position DOUT 2 and 3 are!!!!!!!!!!!!!!!!!!!!!!
//#define REG_DOUT3      0xE1  //[0:1]  State of digital output 3 
#define REG_DIN1       0xE6  //[0:1]  State of digital input 1
#define REG_DIN2       0xE7  //[0:1]  State of digital input 2

//Internal values of comparison values
#define REG_VAR1       0xD1  //(RW) [0:15] Reference Value 1
#define REG_VAR2       0xD2  //(RW) [0:15] Reference Value 2
#define REG_VAR3       0xD3  //(RW) [0:15] Reference Value 3
#define REG_VAR4       0xD4  //(RW) [0:15] Reference Value 4

//Tempuratures of MC and Motor
//TODO: need to figure out what's an "output stage"
#define REG_TEMPOUTMC  0x  //[0:15] Temperature of Output stage
#define REG_TEMPAIRMC  0x  //[0:15] Temperature of MC
#define REG_TEMPM      0x  //[0:15] Temperature of Motor


#define REG_TEMPM      0x  //[0:15] Temperature of Motor

