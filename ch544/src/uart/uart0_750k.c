#include "..\..\inc\ch554.h"
#include "..\..\inc\ch554_debug.h"
unsigned char InitUart0_750k(unsigned char kBaud)
{
   switch(kBaud)
   {
      case BAUD300:
           return Uart0HiSpeed(0xB2,0);
      case BAUD600:
           return Uart0HiSpeed(0xB2,1);
      case BAUD1200:
           return Uart0HiSpeed(0xD9,1);
      case BAUD2400:
           return Uart0HiSpeed(0xF6,0);   // -2.4%
      case BAUD4800:
           return Uart0HiSpeed(0xF6,1);   // -2.4&
      case BAUD9600:
           return Uart0HiSpeed(0xFB,1);   // -2.4% 
   }
   return 0xFF;
}