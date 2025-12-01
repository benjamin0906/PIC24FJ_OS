#include "../Inc/OS_Types.h"
#include "../Inc/OS_Config.h"
#include "../../Config/OS_Taskconfig_Stub.h"
#include "../Inc/IC.h"
#include "../Inc/CORE.h"
#include "../Inc/TIM.h"
#include "../Inc/SC.h"

uint8 CurrentTaskId;
uint16 Os_Tick;
volatile dtOS_ErrorType Os_Error;

void OS_Init(void);
void Os_Schedule_RoundRobin(void);
uint16 OS_GetTicks(void);
void OS_Delay(uint16 Delay);
void OS_Error(dtOS_ErrorType Error);

void OS_Init(void)
{
    dtTIM_A_Cfg TIM1Cfg = {.CmpValue = 4000, .Instance =1, .Prescaler = 0, .TOn = 1,.IntHandler = 0};
    
    for(CurrentTaskId = 0; CurrentTaskId < TASK_NUMBER-1; CurrentTaskId++)
    {
        /* This part of the stack will be restored during returning from the PendSV exception by HW */
        *TaskList[CurrentTaskId].StackPtr++ = (uint16)((uint32)TaskList[CurrentTaskId].Runnable) & 0xFFFF;//PCL
        *TaskList[CurrentTaskId].StackPtr++ = (uint16)((uint32)TaskList[CurrentTaskId].Runnable) >> 16;//STATUS + PCH

        /* This part of the stack will be restured during the PendSV by SW */
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W0
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W1
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W2
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W3
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W4
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W5
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W6
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W7
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W8
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W9
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W10
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W11
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W12
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//W13
        *TaskList[CurrentTaskId].StackPtr++ = TaskList[CurrentTaskId].StackStartAddr;//W14
        *TaskList[CurrentTaskId].StackPtr++ = *((uint16*)0x0032);//DSRPAG
        *TaskList[CurrentTaskId].StackPtr++ = *((uint16*)0x0034);//DSWPAG
        *TaskList[CurrentTaskId].StackPtr++ = 0x00;//RCOUNT

        TaskList[CurrentTaskId].State = Task_Wait;
    }
    
    *TaskList[CurrentTaskId].StackPtr++ = (uint16)((uint32)TaskList[CurrentTaskId].Runnable) & 0xFFFF;//PCL
    *TaskList[CurrentTaskId].StackPtr++ = (uint16)((uint32)TaskList[CurrentTaskId].Runnable) >> 16;//STATUS + PCH

    TaskList[CurrentTaskId].Quantum = OS_QUANTUM;
    TaskList[CurrentTaskId].State = Task_Running;
    
    /* ---------- Setting up context switching TIMER ---------- */
    /* TIM IRQ enabling */
    IC_EnableIRQ(IC_T1IF);
    
    /* Calculating period value */
    TIM1Cfg.CmpValue = (SC_GetFreq(SC_Freq_Tim)/1000)*TICK_PERIOD_US;
    TIM1Cfg.CmpValue--;
    //TIM1Cfg.CmpValue = 4000000/2/1000000*TICK_PERIOD_US;
    
    /* Configuration of TIMER */
    TIM_A_Init(&TIM1Cfg);
    
    CORE_SET_STACKPTR_LIMIT(TaskList[CurrentTaskId].StackEndAddr);
    CORE_SET_STACKPTR(TaskList[CurrentTaskId].StackPtr);
    CORE_SET_FRAMEPTR(TaskList[CurrentTaskId].StackStartAddr);
    asm("RETFIE");
}

/**@brief Getting the ticks of the system
 *
 * This function returns the value of the tick
 * counter variable of the system tick
 *
 * @return value of system tick
 * */
uint16 OS_GetTicks(void)
{
    return Os_Tick;
}

/**@brief Delay function based on the system tick
 *
 * Until the system tick reaches the same value
 * that was given to the function the SW running
 * is blocked
 *
 * @param delay time in ticks
 * */
void OS_Delay(uint16 Delay)
{
    uint16 StartTick = Os_Tick;
    while((Os_Tick - StartTick) < Delay);
}



void Os_Schedule_RoundRobin(void)
{
    static uint8 TaskIndex;

    /* Moving the currently running task to WAIT state */
    TaskList[CurrentTaskId].State = Task_Wait;

    /* Looking for the next task to switch to until the end of the task list */
    while((TaskIndex < TASK_NUMBER) && (TaskList[TaskIndex].State != Task_Wait))
    {
        TaskIndex++;
    }

    /* Looking for the next task to switch to from the beginning of the task list
     * if the indexing arrived to the end of the task list */
    if(TaskIndex >= TASK_NUMBER)
    {
        TaskIndex = 0;
        while((TaskIndex < TASK_NUMBER) && (TaskList[TaskIndex].State != Task_Wait))
        {
            TaskIndex++;
        }
    }

    /* Changing the current task ID */
    CurrentTaskId = TaskIndex;

    /* Incrementing the index used by the search so that in the next turn
     * the first task under examination will be the next task and not the
     * old one */
    TaskIndex++;

    /* Set the quantum of the current task to the initial value */
    TaskList[CurrentTaskId].Quantum = OS_QUANTUM;

    /* Setting the current task to RUN state */
    TaskList[CurrentTaskId].State = Task_Running;
}

void OS_Error(dtOS_ErrorType Error)
{
    Os_Error = Error;
}

#if OS_TIMER == TIMER_1
void __attribute__((interrupt(auto_psv))) __attribute__((naked)) _T1Interrupt(void)
#elif OS_TIMER == TIMER_2
void __attribute__((interrupt(auto_psv))) _T2Interrupt(void)
#elif OS_TIMER == TIMER_3
void __attribute__((interrupt(auto_psv))) _T3Interrupt(void)
#elif OS_TIMER == TIMER_4
void __attribute__((interrupt(auto_psv))) _T4Interrupt(void)
#elif OS_TIMER == TIMER_5
void __attribute__((interrupt(auto_psv))) _T5Interrupt(void)
#else
#error "OS_TIMER is not properly set"
#endif
{
    //IC_ClearIRQ(IC_T1IF);
    /* Storing CPU state to the stack */
    asm("PUSH W0");
    asm("PUSH W1");
    asm("PUSH W2");
    asm("PUSH W3");
    asm("PUSH W4");
    asm("PUSH W5");
    asm("PUSH W6");
    asm("PUSH W7");
    asm("PUSH W8");
    asm("PUSH W9");
    asm("PUSH W10");
    asm("PUSH W11");
    asm("PUSH W12");
    asm("PUSH W13");
    asm("PUSH W14");
    asm("PUSH DSRPAG");
    asm("PUSH DSWPAG");
    asm("PUSH RCOUNT");
    
    IC_ClearIRQ(IC_T1IF);
    
    /*  */
    Os_Tick++;
    
    /* Context changing */
    TaskList[CurrentTaskId].StackPtr = CORE_GET_STACKPTR();
    Os_Schedule_RoundRobin();
    CORE_SET_STACKPTR_LIMIT(TaskList[CurrentTaskId].StackEndAddr);
    CORE_SET_STACKPTR(TaskList[CurrentTaskId].StackPtr);
    
    /* Restoring CPU state from the stack */
    asm("POP RCOUNT");
    asm("POP DSWPAG");
    asm("POP DSRPAG");
    asm("POP W14");
    asm("POP W13");
    asm("POP W12");
    asm("POP W11");
    asm("POP W10");
    asm("POP W9");
    asm("POP W8");
    asm("POP W7");
    asm("POP W6");
    asm("POP W5");
    asm("POP W4");
    asm("POP W3");
    asm("POP W2");
    asm("POP W1");
    asm("POP W0");
}

void __attribute__((interrupt(auto_psv))) _OscillatorFail(void)
{
    OS_Error(OS_Error_OscillatorError);
}

void __attribute__((interrupt(auto_psv))) _AddressError(void)
{
    OS_Error(OS_Error_AddressError);
}

void __attribute__((interrupt(auto_psv))) _StackError(void)
{
    OS_Error(OS_Error_StackOverflow);
}

void __attribute__((interrupt(auto_psv))) _MathError(void)
{
    OS_Error(OS_Error_MathError);
}