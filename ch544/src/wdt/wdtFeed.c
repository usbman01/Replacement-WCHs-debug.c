/*******************************************************************************
Function : void WDTFeed(uint8_t time)
           restart the Watchdog Timer with the given timeout
           timeout depends on fSys about 11ms per inc @ 6 MHz
Param:     uint8_t timeout    
Note:      0x00 means 0x100 -> timeout = 2.8s @6 MHz
Return:    none
*******************************************************************************/
#include "..\..\inc\ch554.h"
void WDTFeed(unsigned char time)
{
	 WDOG_COUNT = time; 
}