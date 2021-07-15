#include ".\..\inc\ch554.h"
void UART1Alternate(unsigned char alternate)
{
	if (alternate) PIN_FUNC |=  bUART1_PIN_X;
	else           PIN_FUNC &= ~bUART1_PIN_X; 
}
