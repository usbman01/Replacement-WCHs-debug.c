#include "..\..\inc\ch554.h"
void PWM1Alternate(unsigned char alternate)
{
	if (alternate) PIN_FUNC |=  bPWM1_PIN_X;
	else           PIN_FUNC &= ~bPWM1_PIN_X; 
}
