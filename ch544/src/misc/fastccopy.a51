;void fastccpy8 (unsigned char xdata *dest, //r6r7
;                unsigned char code  *src,  //r4r5 
;                unsigned char  size)       //r3    
sfr XBUS_AUX = 0xA2; 

?PR?_fastccpy8?FASTCCOPY  SEGMENT CODE

	PUBLIC	_fastccpy8
    $REGUSE _fastccpy8(R7,A,DPTR)

    RSEG   ?PR?_fastccpy8?FASTCCOPY
_fastccpy8:
       PUSH XBUS_AUX
       MOV  XBUS_AUX,#0x01; select DPTR1, no auto inc
       PUSH DPH
       PUSH DPL
       MOV  DPH,R6 
       MOV  DPL,R7     ;destination
          
       DEC  XBUS_AUX   ;select DPTR0
       MOV  DPH, R4
       MOV  DPL, R5    ;source

       mov  A,R3
       MOV  R7,A   
       JZ   ?C001      ;nothing todo 

?C000: CLR  A
       MOVC A,@A+DPTR  ;read source
       INC  DPTR       ;no autoinc its not irq save
       DB   0A5H       ;MOVX @DPTR1,A & INC DPTR1
       DJNZ R7,?C000
?C001: INC  XBUS_AUX
       POP  DPL
       POP  DPH
       POP  XBUS_AUX
       RET

END
