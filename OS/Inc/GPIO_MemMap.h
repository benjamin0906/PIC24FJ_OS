/* 
 * File:   GPIO_MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 10., 19:55
 */

#ifndef GPIO_MEMMAP_H
#define	GPIO_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef union
    {
        uint16 U;
        int16  I;
        struct
        {
            uint16 PIN_15   :1;
            uint16 PIN_14   :1;
            uint16 PIN_13   :1;
            uint16 PIN_12   :1;
            uint16 PIN_11   :1;
            uint16 PIN_10   :1;
            uint16 PIN_9    :1;
            uint16 PIN_8    :1;
            uint16 PIN_7    :1;
            uint16 PIN_6    :1;
            uint16 PIN_5    :1;
            uint16 PIN_4    :1;
            uint16 PIN_3    :1;
            uint16 PIN_2    :1;
            uint16 PIN_1    :1;
            uint16 PIN_0    :1;
        } B;
    } dtGPIO_PinDef;

    typedef struct
    {
        dtGPIO_PinDef   DIR;
        dtGPIO_PinDef   IN;
        dtGPIO_PinDef   OUT;
        dtGPIO_PinDef   ODC;
        dtGPIO_PinDef   ANS;
    } dtGPIO_PortDef;
    
    typedef struct
    {
        dtGPIO_PortDef PortDesc[3];
    } dtGPIO_Ports;

#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_MEMMAP_H */

