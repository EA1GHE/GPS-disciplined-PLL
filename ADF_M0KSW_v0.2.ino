/*ADF4350 to Arduino connections
CE 6
LE 7
DATA 11
CLK 13
MUXOUT n/c 
*/



#include <arduino.h>
#include <SPI.h>

//unsigned long R[6] = {0x451EC0,0x800E1A9,0x4E42,0x4B3,0xBC803C,0xD80005}; //432.234MHz Ref=25MHz
unsigned long R[6] = {0xD803A8,0x8008FA1,0x4E42,0x4B3,0xB40024,0x580005}; //432.234MHz Ref=8MHz
// Frequency: 432.234
// Output power: -1dBm
// Aux output: disabled

const int LE = 7;
const int CE = 6;


void setup(){
 
   SPI.begin();
   SPI.setBitOrder(MSBFIRST);
   //SPI.setClockDivider(16); 
   SPI.setDataMode(SPI_MODE0); 
   
   pinMode(LE, OUTPUT);
   digitalWrite(LE, LOW); // CHECK!
   if (CE){
      pinMode(CE, OUTPUT); 
      digitalWrite(CE, HIGH);
    }
   
   Serial.begin(9600);
   
   delay(500);
   
}
   
void loop(){
    
  //if (CE)
   //digitalWrite(CE, LOW);
    
  for (int j = 5; j >= 0; j--){ 
    Serial.println(); //debug
    Serial.print("R"); //debug
    Serial.print(j); //DEBUG
    Serial.print(": 0x");
    Serial.println( R[j],HEX); //DEBUG
    
        
    //digitalWrite(LE,LOW);
    //Serial.println("LE LOW");//debug
    delayMicroseconds(1);
    
    for (int i = 3; i >= 0; i--)
    {  
      SPI.transfer( (R[j] >> 8 * i) & 0xFF );
      Serial.print((R[j] >> 8 * i) & 0xFF,HEX); //DEBUG!!!!!
      Serial.print(" ");
    }
    Serial.println();//debug
    digitalWrite(LE,HIGH);
    Serial.println("LE HIGH"); //debug
    delayMicroseconds(1);
    digitalWrite(LE,LOW);
    Serial.println("LE LOW");//debug
  
    delayMicroseconds(1);
      }

if (CE)
  digitalWrite(CE, HIGH);
  
  
  delay(20000);
 
 }

    

