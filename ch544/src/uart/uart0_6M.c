#include "..\..\inc\ch554.h"
#include "..\..\inc\ch554_debug.h"
unsigned char InitUart0_6M(unsigned char kBaud)
{
   switch(kBaud)
   {
      case BAUD300:
           return Uart0LoSpeed(0xCC,0);
      case BAUD600:
           return Uart0LoSpeed(0xCC,1);
      case BAUD1200:
           return Uart0LoSpeed(0xE6,1);
//      case BAUD2400:
//           return Uart0LoSpeed(0xF9,1); // -7.5%
      case BAUD4800:
           return Uart0HiSpeed(0xB1,1); 
      case BAUD9600:
           return Uart0HiSpeed(0xD9,1); 
      case BAUD19200:
           return Uart0HiSpeed(0xEC,1);   // -2.4%
      case BAUD38400:
           return Uart0HiSpeed(0xF6,1);   // -2.4%
//      case BAUD57600:
//           return Uart0HiSpeed(0xF9,1); //- 7.5%
      case BAUD76800:
           return Uart0HiSpeed(0xFB,1);   // -2.4% !!
//      case BAUD115200:
//           return Uart0HiSpeed(0xFD,1); // -7.8%
   }
   return 0xFF;
}