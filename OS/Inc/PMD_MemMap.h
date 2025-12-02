/* 
 * File:   PMD_MemMap.h
 * Author: Benjamin
 *
 * Created on 02 December 2025, 21:47
 */

#ifndef PMD_MEMMAP_H
#define	PMD_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "Std_Types.h"

typedef struct sPMD
{
    uint16 PMD[8];
} dtPMD;


#ifdef	__cplusplus
}
#endif

#endif	/* PMD_MEMMAP_H */

