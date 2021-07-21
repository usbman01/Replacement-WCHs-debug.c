/*******************************************************************************
Function : void WDTChange(uint8_t on)
           switch the Watchdog ON or OFF 
Param:     0 -> OFF, other values ON 
Note:      timout will always set to maximum
Return:    none
*******************************************************************************/
#include "..\..\inc\ch554.h"
void WDTChange(unsigned char on)
{
	WDOG_COUNT = 0; 
	SAFE_MOD   = 0x55;
	SAFE_MOD   = 0xAA;
	if(on)  GLOBAL_CFG |=  bWDOG_EN;
	else    GLOBAL_CFG &= ~bWDOG_EN;
}