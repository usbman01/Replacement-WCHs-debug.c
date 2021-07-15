#include ".\..\inc\ch554.h"
void PWM2Alternate(unsigned char alternate)
{
	if (alternate) PIN_FUNC |=  bPWM2_PIN_X;
	else           PIN_FUNC &= ~bPWM2_PIN_X; 
}