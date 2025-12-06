#include "../Inc/MemMap.h"
//#include "config.h"
#include "../Inc/SC.h"

uint32 SC_GetFreq(dtSCFreq Freq);

uint32 SC_GetFreq(dtSCFreq Freq)
{
    uint32 returnFreq = 8000000u;
    switch(SC->OSCCON.B.COSC)
    {
        case 0x7:
            /* FRC with postscaler as clock source */
            returnFreq >>= SC->CLKDIV.B.RCDIV;
            break;
        case 0x5:
            /* LPRC as clock source */
            break;
        case 0x4:
            /* SOSC as clock source */
            
            break;
        case 0x3:
            /* Primary with PLL s clock source */
        case 0x1:
            /* FRC with postscaler and PLL as clock source */
            returnFreq = 32000000u;
            break;
        case 0x0:
            /* FRC as clock source */
            /* nothing to do since no postscaler is used */
            break;
    }
    switch(Freq)
    {
        case SC_Freq_Peri:
            break;
        case SC_Freq_Cpu:
            returnFreq >>= SC->CLKDIV.B.DOZE;
            break;
        case SC_Freq_Tim:
            returnFreq >>= 1;
            break;
        case SC_Freq_Lpcr:
            returnFreq = 31250;
    }
    return returnFreq;
}

void SC_SetRetentionMode(uint8 state)
{
    SC->RCON.B.RETEN = state != 0;
}
