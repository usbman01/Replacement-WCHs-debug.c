#include "..\..\inc\ch554.h"
#include "..\..\inc\ch554_debug.h"
unsigned char InitUart0_16M(unsigned char kBaud)
{
   switch(kBaud)
   {
      case BAUD300:
           return Uart0LoSpeed(0x75,0);
      case BAUD600:
           return Uart0LoSpeed(0x75,1);
      case BAUD1200:
           return Uart0LoSpeed(0xBB,1);
      case BAUD2400:
           return Uart0LoSpeed(0xDD,1);
      case BAUD4800:
           return Uart0HiSpeed(0x98,0); 
      case BAUD9600:
           return Uart0HiSpeed(0x98,1); 
      case BAUD19200:
           return Uart0HiSpeed(0xCC,1);
      case BAUD38400:
           return Uart0HiSpeed(0xE6,1);
      case BAUD57600:
           return Uart0HiSpeed(0xEF,1); //error 2.08% 
      case BAUD76800:
           return Uart0HiSpeed(0xF3,1); 
   }
   return 0xFF;
}