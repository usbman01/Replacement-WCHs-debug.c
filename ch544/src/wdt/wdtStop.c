/*******************************************************************************
Function : void WDTStop(void)
           deactivate the Watchdog
Param:     none 
Return:    none
*******************************************************************************/
#include "..\..\inc\ch554.h"
void WDTStop(void)
{
	SAFE_MOD    = 0x55;
	SAFE_MOD    = 0xAA; 
	GLOBAL_CFG &= ~bWDOG_EN;
}