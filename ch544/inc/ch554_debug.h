#ifndef CH554_DEBUG_H_
#define CH554_DEBUG_H_
#include "compiler.h"   // because of CODE and XDATA macros
/*** watchdog  ***/
void WDTStart  (void);               /* start the watchdog with max timeout */
void WDTStop   (void);               /* stop the watchdog */  
void WDTChange (unsigned char on);   /* start or stop the watchdog */
void WDTFeed   (unsigned char time); /* set a new timeout value for the watchdog */
                                     /* timeout is about 11ms per inc @ 6MHz */
/*** Clocks  ***/
#define FSYS_SELECT_24M     0x06     /* 0x07 omited because 36MHz is not allowed */
#define FSYS_SELECT_16M     0x05
#define FSYS_SELECT_12M     0x04
#define FSYS_SELECT_6M      0x03
#define FSYS_SELECT_3M      0x02
#define FSYS_SELECT_750K    0x01
#define FSYS_SELECT_187K    0x00
unsigned int fSysSelect(unsigned char fSelector); /* return selected fSys in kHz */
//unsigned int fSysSelectXtal (unsigned char fSelector, /* not yet implemented */
//                             unsigned  int fXtal );
/*** delay  ***/
void mDelaymS(unsigned char ms);  /* note: only 8 bit param */
void mDelayuS(unsigned char us);  /* note: only 8 bit param */

/*** PortSetup  ***/
void PWM1Alternate (unsigned char alternate); /* switch functions to alternate pins*/
void PWM2Alternate (unsigned char alternate);
void UART0Alternate(unsigned char alternate);
void UART1Alternate(unsigned char alternate);

/*** Uart       ***/  
// todo 
/*** misc       ***/
unsigned long htonl (unsigned long l); /* helper for converting MSB first to LSB first*/
unsigned int  htonw (unsigned int w);

void fastxcpy8 (unsigned char XDATA *dest, /* copy from source in xdata to dest in xdata */
                unsigned char XDATA *src,  /* similar to memcpy limited to msx 255bytes  */
                unsigned char size);

void fastccpy8 (unsigned char XDATA *dest, /* copy from source in code to dest in xdata */
                unsigned char CODE *src,   /* similar to memcpy limited to msx 255bytes */ 
                unsigned char size);
/*** usb ***/

#endif