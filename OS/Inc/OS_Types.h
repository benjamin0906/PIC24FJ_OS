/* 
 * File:   OS_Types.h
 * Author: Benjamin
 *
 * Created on 2023. november 14., 13:16
 */

#ifndef OS_TYPES_H
#define	OS_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "Std_Types.h"

typedef enum
{
    Task_Stopped,
    Task_Wait,
    Task_Running,
} dtTaskState;

typedef enum
{
    OS_Error_NoError,
    OS_Error_StackOverflow,
    OS_Error_OscillatorError,
    OS_Error_AddressError,
    OS_Error_MathError,
            
} dtOS_ErrorType;

typedef struct
{
    uint16 *StackPtr;
    uint16 *StackStartAddr;
    uint16 *StackEndAddr;
    void (*Runnable)(void);
    dtTaskState State;
#if OS_SCHEDULE_TYPE == OS_SCHEDULE_ROUND_ROBIN
    uint8 Quantum;
    uint16 Skip;
#endif
} dtTaskInfo;

#if OS_SCHEDULE_TYPE == OS_SCHEDULE_ROUND_ROBIN
#define TASK(TaskName, Stack) {.StackPtr = Stack, .StackStartAddr = Stack, .Runnable = &TaskName,  .StackEndAddr = Stack + sizeof(Stack)/sizeof(Stack[0]), .State = Task_Stopped, .Quantum = 0, .Skip = 0}
#else
#define TASK(TaskName, Period, Prio, Stack) {.StackPtr = Stack+sizeof(Stack)/sizeof(Stack[0]), .StackBasePtr = Stack, .Runnable = &TaskName,  .StackSize = sizeof(Stack)/sizeof(Stack[0]), .Priority = Prio, .RemainingTicks = 0}
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* OS_TYPES_H */

