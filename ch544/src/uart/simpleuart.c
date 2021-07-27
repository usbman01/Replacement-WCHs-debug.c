#include "..\..\inc\ch554.h"
/* Initialize Uart0 using Timer1
   The simple form for initializing Uart0 for use with precalculated
   reload values 
   Params:
    - reload: reload value for baudrate
    - smod  : 0 normal baudrate else double baudrate   
*/
void Uart0SimpleInit(unsigned char reload,smod)
{
  if(smod) PCON |=  SMOD;
  else     PCON &= ~SMOD; 

  TMOD  = (TMOD &~ MASK_T1_MOD) | bT1_M1; /* auto reload 8 bit timer*/
  T2MOD = T2MOD | bTMR_CLK | bT1_CLK;     /* runing at fsys */         
  TH1   = reload;                         /* load the calculated reload value*/  
  TR1   = 1;                              /* Timer1 run */                          
  SCON  = 0x51;                           /* 8bit var baudrate */
}