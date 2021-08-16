#ifndef CH554_DEBUG_H_
#define CH554_DEBUG_H_
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
/*
unsigned int fSysSelectXtal (unsigned char fSelector, // not yet implemented 
                             unsigned int  fXtal );   // xtal in kHz
*/
/*** delay  ***/
void mDelaymS(unsigned char ms);  /* note: only 8 bit param */
void mDelayuS(unsigned char us);  /* note: only 8 bit param */

/*** PortSetup  ***/
void PWM1Alternate (unsigned char alternate); /* switch functions to alternate pins*/
void PWM2Alternate (unsigned char alternate);
void UART0Alternate(unsigned char alternate);
void UART1Alternate(unsigned char alternate);

/*** Uart       ***/  
#define BAUD300    0x00
#define BAUD600    0x01
#define BAUD1200   0x02 
#define BAUD2400   0x03 
#define BAUD4800   0x04
#define BAUD9600   0x05
#define BAUD19200  0x06 
#define BAUD38400  0x07 
#define BAUD57600  0x08
#define BAUD76800  0x09
#define BAUD115200 0x0A

unsigned char Uart0HiSpeed  (unsigned char reload,unsigned char smod);
unsigned char Uart0LoSpeed  (unsigned char reload,unsigned char smod);
unsigned char InitUart0_24M (unsigned char kBaud);
unsigned char InitUart0_16M (unsigned char kBaud);
unsigned char InitUart0_12M (unsigned char kBaud);
unsigned char InitUart0_6M  (unsigned char kBaud);
unsigned char InitUart0_3M  (unsigned char kBaud);
unsigned char InitUart0_750k(unsigned char kBaud);
unsigned char InitUart0(unsigned char kBaud); /* return 0xFF if the bautrate can't be reached*/
/*** misc       ***/
#ifndef __SDCC_mcs51                          /* not available under SDCC */
unsigned long htonl (unsigned long l);        /* helper for converting MSB first to LSB first*/
unsigned int  htonw (unsigned int w);
#endif

#ifdef __SDCC_mcs51                           /* map the memspecifier for  SDCC */
  #define xdata  __xdata
  #define code   __code
#endif
void fastxcpy8 (unsigned char xdata *dest,    /* copy from source in xdata to dest in xdata */
                unsigned char xdata *src,     /* similar to memcpy limited to max 255bytes  */
                unsigned char size);

void fastccpy8 (unsigned char xdata *dest,    /* copy from source in code to dest in xdata */
                unsigned char code  *src,     /* similar to memcpy limited to max 255bytes */ 
                unsigned char size);
/*** usb ***/

#endif