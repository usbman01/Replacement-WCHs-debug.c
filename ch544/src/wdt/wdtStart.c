/*******************************************************************************
Function : void WDTStart(void)
           activate the Watchdog with the maximum timeout
Param:     none 
Return:    none
*******************************************************************************/
#include "..\..\inc\ch554.h"
void WDTStart(void)
{
	WDOG_COUNT  = 0;
	SAFE_MOD    = 0x55;
	SAFE_MOD    = 0xAA;
	GLOBAL_CFG |= bWDOG_EN;
}
