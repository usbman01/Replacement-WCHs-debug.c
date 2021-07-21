sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\clock\clksetup.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\wdt\wdtchange.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\wdt\wdtfeed.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\wdt\wdtstart.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\wdt\wdtstop.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\delay\delayms.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\delay\delayus.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\port\pwm1_alt.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\port\pwm2_alt.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\port\uart0_alt.c
sdcc -c --opt-code-size -o..\obj\sdcc\ ..\src\port\uart1_alt.c

sdas8051 -losg ..\obj\sdcc\fastxcopy.rel ..\src\misc\fastxcopy.asm
sdas8051 -losg ..\obj\sdcc\fastccopy.rel ..\src\misc\fastccopy.asm

sdar -rc ..\obj\sdcc\ch554_debug_SDCC.LIB ..\obj\sdcc\clksetup.rel ..\obj\sdcc\wdtchange.rel ..\obj\sdcc\wdtfeed.rel ..\obj\sdcc\wdtstart.rel ..\obj\sdcc\wdtstop.rel ..\obj\sdcc\delayms.rel ..\obj\sdcc\delayus.rel ..\obj\sdcc\pwm1_alt.rel ..\obj\sdcc\pwm2_alt.rel ..\obj\sdcc\uart0_alt.rel ..\obj\sdcc\uart1_alt.rel ..\obj\sdcc\fastxcopy.rel ..\obj\sdcc\fastccopy.rel

copy /Y ..\obj\sdcc\ch554_debug_SDCC.LIB ..\ch554_debug_SDCC.LIB
