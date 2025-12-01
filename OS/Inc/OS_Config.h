/* 
 * File:   OS_Config.h
 * Author: Benjamin
 *
 * Created on 2023. november 14., 13:26
 */

#ifndef OS_CONFIG_H
#define	OS_CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "../../Config/OS_Config_Stub.h"
#include "OS_Tasklist.h"
    
#define TIMER_1 1
#define TIMER_2 2
#define TIMER_3 3
#define TIMER_4 4
#define TIMER_5 5

#define OS_SCHEDULE_TYPE OS_SCHEDULE_ROUND_ROBIN
#if OS_SCHEDULE_TYPE == OS_SCHEDULE_ROUND_ROBIN
#define OS_QUANTUM 10
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* OS_CONFIG_H */

