/* 
 * File:   MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 13:02
 */

#ifndef MEMMAP_H
#define	MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "CORE_MemMap.h"
#include "GPIO_MemMap.h"
#include "TIM_MemMap.h"
#include "IC_MemMap.h"
#include "SC_MemMap.h"
#include "I2C_MemMap.h"
#include "PMD_MemMap.h"
    
extern dtCORE       * const Core;
extern dtGPIO_Ports * const Ports;
extern dtTIM        * const TIMs;
extern dtIC         * const IC;
extern dtSC         * const SC;
extern dtI2C        * const I2C;
extern dtPMD        * const PMD;

#ifdef	__cplusplus
}
#endif

#endif	/* MEMMAP_H */

