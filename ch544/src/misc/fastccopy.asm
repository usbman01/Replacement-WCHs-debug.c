;*** SDCC asm version
;    translate with:
;    sdas8051 -losg fastccopy.asm    
;***
.module fastccopy

.globl _fastccpy8
.globl _fastccpy8_PARM_2
.globl _fastccpy8_PARM_3
.area RSEG    (ABS,DATA)
XBUS_AUX	=	0x00a2

.area OSEG
_fastccpy8_PARM_2:
       .ds 2           ;storage dest
_fastccpy8_PARM_3:
       .ds 1           ;storage len

.area CSEG    (CODE)
_fastccpy8: 
       MOV  R6,DPH     ;save dptr0 (dest param)
       MOV  R7,DPL
         
       MOV  XBUS_AUX,#0x01; select DPTR1, no auto inc     
       MOV  DPTR,#_fastxcpy8_PARM_2 ;(src param)
          
       DEC  XBUS_AUX   ;select DPTR0
       MOV  DPH,R6 
       MOV  DPL,R7     
 
       mov  A,_fastxcpy8_PARM_3
       MOV  R7,A   
       JZ   0001$      ;nothing todo 

0000$: CLR  A
       MOVC A,@A+DPTR    ;read source
       INC  DPTR       ;no autoinc its not irq save
       .db  0xA5       ;MOVX @DPTR1,A & INC DPTR1
       DJNZ R7,0000$
0001$: RET
