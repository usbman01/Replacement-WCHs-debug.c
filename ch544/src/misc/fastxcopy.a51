;void fastxcpy8 (unsigned char xdata *dest, //r6r7
;                unsigned char xdata *src,  //r4r5 
;                unsigned char  size)       //r3    
sfr XBUS_AUX = 0xA2; 

?PR?_fastxcpy8?FASTXCOPY  SEGMENT CODE

	PUBLIC	_fastxcpy8
    $REGUSE _fastxcpy8(R7,A,DPTR)

    RSEG   ?PR?_fastxcpy8?FASTXCOPY
_fastxcpy8: 
       MOV  XBUS_AUX,#0x01; select DPTR1, no auto inc     
       MOV  DPH,R6 
       MOV  DPL,R7     ;destination
          
       DEC  XBUS_AUX   ;select DPTR0
       MOV  DPH, R4
       MOV  DPL, R5    ;source

       mov  A,R3
       MOV  R7,A   
       JZ   ?C001      ;nothing todo 

?C000: MOVX A,@DPTR    ;read source
       INC  DPTR       ;no autoinc its not irq save
       DB   0A5H       ;MOVX @DPTR1,A & INC DPTR1
       DJNZ R7,?C000
?C001: RET

END