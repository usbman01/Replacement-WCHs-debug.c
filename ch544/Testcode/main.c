#include "..\inc\ch554.h"

extern void fastxcpy8 (unsigned char XDATA *dest, 
                       unsigned char XDATA *src, 
                       unsigned char size);
unsigned int fSysSelect(unsigned char fSelector);
void mDelaymS(unsigned char ms);

unsigned char XDATA inbuf [100];
unsigned char XDATA outbuf[100];

void main(void)
{
   fSysSelect(0x06);
   while(1)
   {
	    fastxcpy8(inbuf,outbuf,64);
      mDelaymS(250);
	 }
}       
 