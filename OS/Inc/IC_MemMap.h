/* 
 * File:   IC_MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 15:28
 */

#ifndef IC_MEMMAP_H
#define	IC_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16 NSTDIS   :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16 MATHERR  :1;
            uint16 ADDRERR  :1;
            uint16 STKERR   :1;
            uint16 OSCFAIL  :1;
            uint16          :1;
        } B;
    }dtIC_INTCON1;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16 ALTIVT   :1;
            uint16 DSI      :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16  :1;
            uint16 INT4EP   :1;
            uint16 INT3EP   :1;
            uint16 INT2EP   :1;
            uint16 INT1EP   :1;
            uint16 INT0EP   :1;
        } B;
    }dtIC_INTCON2;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 :1;
            uint16 DMA1IF   :1;
            uint16 AD1IF    :1;
            uint16 U1TXIF   :1;
            uint16 U1RXIF   :1;
            uint16 SPI1TXIF :1;
            uint16 SPI1IF   :1;
            uint16 T3IF     :1;
            uint16 T2IF     :1;
            uint16 OC2IF    :1;
            uint16 IC2IF    :1;
            uint16 DMA0IF   :1;
            uint16 T1IF     :1;
            uint16 OC1IF    :1;
            uint16 IC1IF    :1;
            uint16 INT0IF   :1;
        } B;
    } dtIC_IntFlagDesc0;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 U2TXIF   :1;
            uint16 U2RXIF   :1;
            uint16 INT2IF   :1;
            uint16 T5IF     :1;
            uint16 T4IF     :1;
            uint16 OC4IF    :1;
            uint16 OC3IF    :1;
            uint16 DMA2IF   :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 INT1IF   :1;
            uint16 CNIF     :1;
            uint16 CMIF     :1;
            uint16 MI2C1IF  :1;
            uint16 SI2C1IF  :1;
        } B;
    } dtIC_IntFlagDesc1;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 :1;
            uint16 DMA4IF   :1;
            uint16 PMPIF    :1;
            uint16 :1;
            uint16 :1;
            uint16 OC6IF    :1;
            uint16 OC5IF    :1;
            uint16 IC6IF    :1;
            uint16 IC5IF    :1;
            uint16 IC4IF    :1;
            uint16 IC3IF    :1;
            uint16 DMA3IF   :1;
            uint16 CRYROLLIF:1;
            uint16 CRYFREEIF:1;
            uint16 SPI2TXIF :1;
            uint16 SPI2IF   :1;
        } B;
    } dtIC_IntFlagDesc2;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 :1;
            uint16 RTCIF    :1;
            uint16 DMA5IF   :1;
            uint16 SPI3RXIF :1;
            uint16 SPI2RXIF :1;
            uint16 SPI1RXIF :1;
            uint16 :1;
            uint16 KEYSTRIF :1;
            uint16 CRYDNIF  :1;
            uint16 INT4IF   :1;
            uint16 INT3IF   :1;
            uint16 :1;
            uint16 :1;
            uint16 MI2C2IF  :1;
            uint16 SI2C2IF  :1;
            uint16 :1;
        } B;
    } dtIC_IntFlagDesc3;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 :1;
            uint16 :1;
            uint16 CTMUIF   :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 HLVDIF   :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 CRCIF    :1;
            uint16 U2ERIF   :1;
            uint16 U1ERIF   :1;
            uint16 :1;
        } B;
    } dtIC_IntFlagDesc4;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 SPI3TXIF :1;
            uint16 SPI3IF   :1;
            uint16 U4TXIF   :1;
            uint16 U4RXIF   :1;
            uint16 U4ERIF   :1;
            uint16 USB1IF   :1;
            uint16 I2C2BCIF :1;
            uint16 I2C1BCIF :1;
            uint16 U3TXIF   :1;
            uint16 U3RXIF   :1;
            uint16 U3ERIF   :1;
            uint16 :1;
        } B;
    } dtIC_IntFlagDesc5;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 FSTIF    :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
        } B;
    } dtIC_IntFlagDesc6;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 JTAGIF   :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
            uint16 :1;
        } B;
    } dtIC_IntFlagDesc7;
    
    typedef struct
    {
        dtIC_IntFlagDesc0   Reg0;
        dtIC_IntFlagDesc1   Reg1;
        dtIC_IntFlagDesc2   Reg2;
        dtIC_IntFlagDesc3   Reg3;
        dtIC_IntFlagDesc4   Reg4;
        dtIC_IntFlagDesc5   Reg5;
        dtIC_IntFlagDesc6   Reg6;
        dtIC_IntFlagDesc7   Reg7;
    } dtIC_IntFlagDesc;
    
    typedef union
    {
        uint16  U;
        int16   I;
        struct
        {
            uint16 CPUIRQ   :1;
            uint16 :1;
            uint16 VHOLD    :1;
            uint16 :1;
            uint16 ILR3     :1;
            uint16 ILR2     :1;
            uint16 ILR1     :1;
            uint16 ILR0     :1;
            uint16 VECNUM7  :1;
            uint16 VECNUM6  :1;
            uint16 VECNUM5  :1;
            uint16 VECNUM4  :1;
            uint16 VECNUM3  :1;
            uint16 VECNUM2  :1;
            uint16 VECNUM1  :1;
            uint16 VECNUM0  :1;
        } B;
    } dtID_INTTREG;

    typedef struct
    {
        dtIC_INTCON1        INTCON1;
        dtIC_INTCON2        INTCON2;
        dtIC_IntFlagDesc    Status;
        dtIC_IntFlagDesc    Enable;
        uint16              IPC[30];
        dtID_INTTREG        INTTREG;
    } dtIC;

#ifdef	__cplusplus
}
#endif

#endif	/* IC_MEMMAP_H */

