/* 
 * File:   OS_Ext.h
 * Author: Benjamin
 *
 * Created on 2023. november 17., 21:49
 */

#ifndef OS_EXT_H
#define	OS_EXT_H

#ifdef	__cplusplus
extern "C" {
#endif


extern void OS_Init(void);
extern uint16 OS_GetTicks(void);
extern void OS_Delay(uint32 Delay);

#ifdef	__cplusplus
}
#endif

#endif	/* OS_EXT_H */

