/* 
 * File:   CORE.h
 * Author: Benjamin
 *
 * Created on 2023. november 17., 16:37
 */

#ifndef CORE_H
#define	CORE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "MemMap.h"
    
#define CORE_SET_STACKPTR_LIMIT(SpLim)\
do\
{\
    Core->SPLIM = SpLim;\
}\
while(0);
    
#define CORE_SET_STACKPTR(Sp)\
do\
{\
    Core->W15 = Sp;\
}\
while(0);
    
#define CORE_GET_STACKPTR() Core->W15;

#define CORE_SET_FRAMEPTR(FrPtr)\
do\
{\
    Core->W14 = FrPtr;\
}\
while(0);


#ifdef	__cplusplus
}
#endif

#endif	/* CORE_H */

