#include "..\..\inc\ch554.h"
void UART0Alternate(unsigned char alternate)
{
	if (alternate) PIN_FUNC |=  bUART0_PIN_X;
	else           PIN_FUNC &= ~bUART0_PIN_X; 
}
