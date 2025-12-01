/* 
 * File:   GPIO.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 12:30
 */

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum
    {
        GPIO_PA0    = 0x00,
        GPIO_PA1    = 0x01,
        GPIO_PA2    = 0x02,
        GPIO_PA3    = 0x03,
        GPIO_PA7    = 0x07,
        GPIO_PA8    = 0x08,
        GPIO_PA9    = 0x09,
        GPIO_PA10   = 0x0A,
        GPIO_PB0    = 0x10,
        GPIO_PB1    = 0x11,
        GPIO_PB2    = 0x12,
        GPIO_PB3    = 0x13,
        GPIO_PB5    = 0x15,
        GPIO_PB6    = 0x16,
        GPIO_PB7    = 0x17,
        GPIO_PB8    = 0x18,
        GPIO_PB9    = 0x19,
        GPIO_PB10   = 0x1A,
        GPIO_PB11   = 0x1B,
        GPIO_PB13   = 0x1D,
        GPIO_PB14   = 0x1E,
        GPIO_PB15   = 0x1F,
        GPIO_PC0    = 0x20,
        GPIO_PC1    = 0x21,
        GPIO_PC2    = 0x22,
        GPIO_PC3    = 0x23,
        GPIO_PC4    = 0x24,
        GPIO_PC5    = 0x25,
        GPIO_PC6    = 0x26,
        GPIO_PC7    = 0x27,
        GPIO_PC8    = 0x28,
        GPIO_PC9    = 0x29,
    } dtGPIO_Pins;
    
    typedef enum
    {
        GPIO_Input  = 1,
        GPIO_Output = 0,
        GPIO_Analog = 2,
    } dtGPIO_Dir;
    
    extern void GPIO_SetDir(const dtGPIO_Pins Pin, const dtGPIO_Dir Dir);
    extern void GPIO_Set(dtGPIO_Pins Pin, uint8 Value);


#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

