; uint16_t htonw(uint16_t val)
?PR?_htonw?htonw SEGMENT CODE 
	PUBLIC	_htonw
    $REGUSE _htonw(R6,R7)
    RSEG    ?PR?_htonw?htonw
_htonw:        
    xch     a,R7   ;R7<>R6
    xch     a,R6
    xch     a,R7  
    ret
end