#include "..\..\inc\ch554.h"
#include "..\..\inc\ch554_debug.h"


unsigned char InitUart0(unsigned char kBaud)
{
  switch(CLOCK_CFG & MASK_SYS_CK_SEL)
  {
     case 1:  return InitUart0_750k(kBaud);
     case 2:  return InitUart0_3M(kBaud);
     case 3:  return InitUart0_6M(kBaud); 
     case 4:  return InitUart0_12M(kBaud);
     case 5:  return InitUart0_16M(kBaud);
     case 6:  return InitUart0_24M(kBaud);
  }
  return 0xFF;
}

/*
void	mInitSTDIO( )
{
	volatile uint32_t x;
	volatile uint8_t  x2;
	
	SM0 = 0;
	SM1 = 1;
	SM2 = 0; //??0????1
	//??Timer1????????
	RCLK = 0; //UART0????
	TCLK = 0; //UART0????
	PCON |= SMOD;
	x = 10 * FREQ_SYS / UART0_BAUD / 16; //??????,??x??????
	x2 = x % 10;
	x /= 10;
	if ( x2 >= 5 ) x ++; //????
	
	TMOD = TMOD & ~ bT1_GATE & ~ bT1_CT & ~ MASK_T1_MOD | bT1_M1; //0X20,Timer1??8????????
	T2MOD = T2MOD | bTMR_CLK | bT1_CLK; //Timer1????
	TH1 = 0-x; //12MHz??,buad/12?????????
	TR1 = 1; //?????1
	TI = 1;
	REN = 1; //??0????
}
*/