#include "..\..\inc\ch554.h"
#include "..\..\inc\ch554_debug.h"
unsigned char InitUart0_24M(unsigned char kBaud)
{
   switch(kBaud)
   {
      case BAUD300:
           return Uart0LoSpeed(0x30,0);
      case BAUD600:
           return Uart0LoSpeed(0x30,1);
      case BAUD1200:
           return Uart0LoSpeed(0x98,1);
      case BAUD2400:
           return Uart0LoSpeed(0xCC,1);
      case BAUD4800:
           return Uart0HiSpeed(0x64,0); 
      case BAUD9600:
           return Uart0HiSpeed(0x64,1); 
      case BAUD19200:
           return Uart0HiSpeed(0xB2,1);
      case BAUD38400:
           return Uart0HiSpeed(0xD9,1);
      case BAUD57600:
           return Uart0HiSpeed(0xE6,1); 
      case BAUD76800:
           return Uart0HiSpeed(0xEC,1); //error is -2.3% !!
      case BAUD115200:
           return Uart0HiSpeed(0xF3,1);
   }
   return 0xFF;
}