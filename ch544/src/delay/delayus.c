#include "..\..\inc\ch554.h"

//24 MHz
void mdelay24_us(unsigned char us)
{
  while (us)  // total = 12~13 Fsys cycles, 1uS @Fsys=12MHz
  {
    ++ SAFE_MOD; 
	  ++ SAFE_MOD;
	  ++ SAFE_MOD;
	  ++ SAFE_MOD;
	  ++ SAFE_MOD;
	  ++ SAFE_MOD;
	  ++ SAFE_MOD;
	  -- us;
  }
}
//16MHz
void mdelay16_us(unsigned char us)
{
  while (us) 
  {
    ++ SAFE_MOD; 
	  ++ SAFE_MOD;
	  ++ SAFE_MOD;
	  -- us;
  }
}
//12MHz
void mdelay12_us(unsigned char us)
{
  while (us) 
  {
    ++ SAFE_MOD; 
	  -- us;
  }
}
//6Mhz
void mdelay6_us(unsigned char us)
{
	us >>=2; 
  while (us) 
  {
    ++ SAFE_MOD; 
	  -- us;
  }
}

void mdelay3_us(unsigned char us)
{
	us >>=4; 
  while (us) 
  {
    ++ SAFE_MOD; 
	  -- us;
  }
}
/*
void mdelay750_us(unsigned char us)
{
	us >>=8; 
  while (us) 
  {
    ++ SAFE_MOD; 
	  -- us;
  }
}
*/

void mDelayuS(unsigned char us)
{
   switch(CLOCK_CFG &  MASK_SYS_CK_SEL)
   {
      case 2:
           mdelay3_us(us);  return;
      case 3:
           mdelay6_us(us);  return;
      case 4:
           mdelay12_us(us); return;   
      case 5:
           mdelay16_us(us); return; 
      case 6: 
           mdelay24_us(us);       
   }
}
