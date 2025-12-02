/* 
 * File:   PMD.h
 * Author: Benjamin
 *
 * Created on 02 December 2025, 21:50
 */

#ifndef PMD_H
#define	PMD_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum ePmd_Peripheral
    {
        Pmd_ADC1 = 0,
                Pmd_SPI1 = 3,
                Pmd_SPI2,
                Pmd_U1,
                Pmd_U2,
                Pmd_I2C1,
                Pmd_T1 = 11,
                Pmd_T2,
                Pmd_T3,
                Pmd_T4,
                Pmd_T5,
                Pmd_OC1,
                Pmd_OC2,
                Pmd_OC3,
                Pmd_OC4,
                Pmd_OC5,
                Pmd_OC6,
                Pmd_IC1 = 24,
                Pmd_IC2,
                Pmd_IC3,
                Pmd_IC4,
                Pmd_IC5,
                Pmd_IC6,
                Pmd_I2C2 = 33,
                Pmd_U3 = 35,
                Pmd_CRC = 39,
                Pmd_PMP,
                Pmd_RTCC,
                Pmd_CMP,
                Pmd_DSM,
                Pmd_USB1 = 48,
                Pmd_HLVD,
                Pmd_CTMU,
                Pmd_REFO,
                Pmd_U4 = 53,
                Pmd_UPWM,
                Pmd_SPI3 = 80,
                Pmd_DMA0 = 100,
                Pmd_DMA1,
                Pmd_CRY = 112
    } dtPmd_Peripheral;

    extern void PMD_Set(dtPmd_Peripheral peripheral);
    extern void PMD_Clear(dtPmd_Peripheral peripheral);
    
#ifdef	__cplusplus
}
#endif

#endif	/* PMD_H */

