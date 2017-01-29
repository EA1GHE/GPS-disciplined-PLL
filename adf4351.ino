/*ADF4350 to Arduino connections
Level shift required 3.3V - 5V
20kohm//11kohm

LE 7
DATA 11
CLK 13
MUXOUT n/c 
*/



#include <arduino.h>
#include <SPI.h>

//Value of next registers comes from ADF435x software by Anallog Devices
//unsigned long R[6] = {0x451EC0,0x800E1A9,0x4E42,0x4B3,0xBC803C,0xD80005}; //432.234MHz Ref=25MHz
//unsigned long R[6] = {0xD803A8,0x8008FA1,0x4E42,0x4B3,0xB40024,0x580005}; //432.234MHz Ref=8MH
unsigned long R[6] = {0x4805E8,0x8008FA1,0x16004E42,0x4B3,0xC8002C,0x580005}; //144.378MHz Ref=8MHz
//unsigned long R[6] = {0x2E1DD0,0x800E1A9,0x14004E42,0x4B3,0xCC80EC,0x580005}; //144.227MHz Ref=25MHz

const int LE = 7;

void setup(){
 
   SPI.begin();
   SPI.setBitOrder(MSBFIRST);
   SPI.setDataMode(SPI_MODE0); 
   pinMode(LE, OUTPUT);
   digitalWrite(LE, LOW);
   for (int j = 5; j >= 0; j--){
    delayMicroseconds(1);
    for (int i = 3; i >= 0; i--){  
      SPI.transfer( (R[j] >> 8 * i) & 0xFF );
    }
    digitalWrite(LE,HIGH);
    delayMicroseconds(1);
    digitalWrite(LE,LOW);
    delayMicroseconds(1);
   }
   
}
   
void loop(){  
}
