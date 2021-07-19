#include ".\..\inc\ch554.h"

unsigned int fSysSelect(unsigned char fSelector)
{
	 unsigned char sel;

	 sel  = (CLOCK_CFG & ~(MASK_SYS_CK_SEL | bROM_CLK_FAST)) | fSelector; 

   if (fSelector > 4 ) sel |= bROM_CLK_FAST; // set it for 16/24MHz
	
   SAFE_MOD  = 0x55;
	 SAFE_MOD  = 0xAA;	 
   CLOCK_CFG = sel;
   switch (fSelector)
   {
      case 0: return 187;
      case 1: return 750;
      case 2: return 3000;
      case 3: return 6000;
      case 4: return 12000;
      case 5: return 16000;
      case 6: return 24000;
      case 7: return 32000;
   }
   return 0xFFFF; //something is wrong                  	 
}