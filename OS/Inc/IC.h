/* 
 * File:   IC.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 16:09
 */

#ifndef IC_H
#define	IC_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum
    {
        IC_INT0IF       = 0x00,
        IC_IC1IF        = 0x01,
        IC_OC1IF        = 0x02,
        IC_T1IF         = 0x03,
        IC_DMA0IF       = 0x04,
        IC_IC2IF        = 0x05,
        IC_OC2IF        = 0x06,
        IC_T2IF         = 0x07,
        IC_T3IF         = 0x08,
        IC_SPI1IF       = 0x09,
        IC_SPI1TXIF     = 0x0A,
        IC_U1RXIF       = 0x0B,
        IC_U1TXIF       = 0x0C,
        IC_AD1IF        = 0x0D,
        IC_DMA1IF       = 0x0E,
        IC_SI2C1IF      = 0x10,
        IC_MI2C1IF      = 0x11,
        IC_CMIF         = 0x12,
        IC_CNIF         = 0x13,
        IC_INT1IF       = 0x14,
        IC_DMA2IF       = 0x18,
        IC_OC3IF        = 0x19,
        IC_OC4IF        = 0x1A,
        IC_T4IF         = 0x1B,
        IC_T5IF         = 0x1C,
        IC_INT2IF       = 0x1D,
        IC_U2RXIF       = 0x1E,
        IC_U2TXIF       = 0x1F,
        IC_SPI2IF       = 0x20,
        IC_SPI2TXIF     = 0x21,
        IC_CRYFREEIF    = 0x22,
        IC_CRYROLLIF    = 0x23,
        IC_DMA3IF       = 0x24,
        IC_IC3IF        = 0x25,
        IC_IC4IF        = 0x26,
        IC_IC5IF        = 0x27,
        IC_IC6IF        = 0x28,
        IC_OC5IF        = 0x29,
        IC_OC6IF        = 0x2A,
        IC_PMPIF        = 0x2D,
        IC_DMA4IF       = 0x2E,
        IC_SI2C2IF      = 0x31,
        IC_MI2C2IF      = 0x32,
        IC_INT3IF       = 0x35,
        IC_INT4IF       = 0x36,
        IC_CRYDNIF      = 0x37,
        IC_KEYSTRIF     = 0x38,
        IC_SPI1RXIF     = 0x3A,
        IC_SPI2RXIF     = 0x3B,
        IC_SPI3RXIF     = 0x3C,
        IC_DMA5IF       = 0x3D,
        IC_RTCIF        = 0x3E,
        IC_U1ERIF       = 0x41,
        IC_U2ERIF       = 0x42,
        IC_CRCIF        = 0x43,
        IC_HLVDIF       = 0x48,
        IC_CTMUIF       = 0x4D,
        IC_U3ERIF       = 0x51,
        IC_U3RXIF       = 0x52,
        IC_U3TXIF       = 0x53,
        IC_I2C1BCIF     = 0x54,
        IC_I2C2BCIF     = 0x55,
        IC_USB1IF       = 0x56,
        IC_U4ERIF       = 0x57,
        IC_U4RXIF       = 0x58,
        IC_U4TXIF       = 0x59,
        IC_SPI3IF       = 0x5A,
        IC_SPI3TXIF     = 0x5B,
        IC_FSTIF        = 0x6A,
        IC_JTAGIF       = 0x75,
    } dtIC_Vector;
    
    extern void IC_EnableIRQ(dtIC_Vector Vector);
    extern void IC_DisableIRQ(dtIC_Vector Vector);
    extern void IC_ClearIRQ(dtIC_Vector Vector);


#ifdef	__cplusplus
}
#endif

#endif	/* IC_H */

