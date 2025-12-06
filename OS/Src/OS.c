#include "../Inc/OS_Types.h"
#include "../Inc/OS_Config.h"
#include "../../Config/OS_Taskconfig_Stub.h"
#include "../Inc/IC.h"
#include "../Inc/CORE.h"
#include "../Inc/TIM.h"
#include "../Inc/SC.h"

typedef union uStackToRunnable
{
    void (**func)(void);
    uint16 *stack;
} dtStackToRunnable;

uint16 Background_Stack[32];
uint8 CurrentTaskId;
uint16 Os_Tick;
volatile dtOS_ErrorType Os_Error;
dtTaskInfo Background_Task_Descriptor;
dtTaskInfo *CurrentDescriptor;

void OS_Init(void);
dtTaskInfo* Os_Schedule_RoundRobin(void);
uint16 OS_GetTicks(void);
void OS_Delay(uint16 Delay);
void OS_Error(dtOS_ErrorType Error);
void Background_Task(void);
static void TaskInit(dtTaskInfo *task);

void OS_Init(void)
{
    dtTIM_A_Cfg TIM1Cfg = {.CmpValue = 4000, .Instance =1, .Prescaler = 0, .TOn = 1,.IntHandler = 0};
    dtStackToRunnable wrapper;
    dtTaskInfo tTask = TASK(Background_Task, Background_Stack);
    Background_Task_Descriptor = tTask;
    
    TaskInit(&Background_Task_Descriptor);
    
    for(CurrentTaskId = 0; CurrentTaskId < TASK_NUMBER-1; CurrentTaskId++)
    {
        TaskInit(&TaskList[CurrentTaskId]);

        TaskList[CurrentTaskId].State = Task_Wait;
    }
    wrapper.stack = (TaskList[CurrentTaskId].StackPtr++); //wrapping runnable address
    *wrapper.func = TaskList[CurrentTaskId].Runnable; //to the pcl section, in xc16 function pointers are always 16 bit wide
    *(TaskList[CurrentTaskId].StackPtr++) = 0;//STATUS + PCH

    TaskList[CurrentTaskId].Quantum = OS_QUANTUM;
    TaskList[CurrentTaskId].State = Task_Running;
    
    CurrentDescriptor = &TaskList[CurrentTaskId];
    
    /* ---------- Setting up context switching TIMER ---------- */
    /* TIM IRQ enabling */
    IC_EnableIRQ(IC_T1IF);
    
    /* Calculating period value */
    //TIM1Cfg.CmpValue = (SC_GetFreq(SC_Freq_Tim)/1000)*TICK_PERIOD_US;
    TIM1Cfg.CmpValue = (SC_GetFreq(SC_Freq_Lpcr)/TICK_FREQUENCY);
    TIM1Cfg.CmpValue--;
    TIM1Cfg.ClkSel = 3;
    
    /* Configuration of TIMER */
    TIM_A_Init(&TIM1Cfg);
    
    CORE_SET_STACKPTR_LIMIT(TaskList[CurrentTaskId].StackEndAddr);
    CORE_SET_STACKPTR(TaskList[CurrentTaskId].StackPtr);
    CORE_SET_FRAMEPTR(TaskList[CurrentTaskId].StackStartAddr);
    asm("RETFIE");
}

static void TaskInit(dtTaskInfo *task)
{
    dtStackToRunnable wrapper;
    
    /* This part of the stack will be restored during returning from the PendSV exception by HW */
    wrapper.stack = (task->StackPtr++); //wrapping runnable address
    *wrapper.func = task->Runnable; //to the pcl section, in xc16 function pointers are always 16 bit wide
    *(task->StackPtr++) = 0;//STATUS + PCH

    /* This part of the stack will be restured during the PendSV by SW */
    *(task->StackPtr++) = 0x00;//W0
    *(task->StackPtr++) = 0x00;//W1
    *(task->StackPtr++) = 0x00;//W2
    *(task->StackPtr++) = 0x00;//W3
    *(task->StackPtr++) = 0x00;//W4
    *(task->StackPtr++) = 0x00;//W5
    *(task->StackPtr++) = 0x00;//W6
    *(task->StackPtr++) = 0x00;//W7
    *(task->StackPtr++) = 0x00;//W8
    *(task->StackPtr++) = 0x00;//W9
    *(task->StackPtr++) = 0x00;//W10
    *(task->StackPtr++) = 0x00;//W11
    *(task->StackPtr++) = 0x00;//W12
    *(task->StackPtr++) = 0x00;//W13
    *(task->StackPtr++) = (uint16)task->StackStartAddr;//W14
    *(task->StackPtr++) = *((uint16*)0x0032);//DSRPAG
    *(task->StackPtr++) = *((uint16*)0x0034);//DSWPAG
    *(task->StackPtr++) = 0x00;//RCOUNT
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
    /*uint16 StartTick = Os_Tick;
    while((Os_Tick - StartTick) < Delay);*/
    volatile uint16 remaining = 0;
    CurrentDescriptor->Skip = Delay;
    do
    {
        remaining = CurrentDescriptor->Skip;
    }
    while(remaining != 0);
}

void Background_Task(void)
{
    while(1)
    {
        asm("PWRSAV #0");
    }
}

dtTaskInfo* Os_Schedule_RoundRobin(void)
{
    uint8 task_counter = 0;
    dtTaskInfo *ret = 0;
    
    if(TaskList[CurrentTaskId].Skip != 0)
    {
        TaskList[CurrentTaskId].Skip--;
    }
    CurrentTaskId++;
    if(CurrentTaskId >= TASK_NUMBER)
    {
        CurrentTaskId = 0;
    }
    
    while((task_counter < TASK_NUMBER) && (TaskList[CurrentTaskId].Skip != 0))
    {
        TaskList[CurrentTaskId].Skip--;
        CurrentTaskId++;
        task_counter++;
        if(CurrentTaskId >= TASK_NUMBER)
        {
            CurrentTaskId = 0;
        }
    }
    if(task_counter >= TASK_NUMBER)
    {
        ret = &Background_Task_Descriptor;
    }
    else
    {
        ret = &TaskList[CurrentTaskId];
    }
    return ret;
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
    CurrentDescriptor->StackPtr = (uint16*)CORE_GET_STACKPTR();
    CurrentDescriptor = Os_Schedule_RoundRobin();
    CORE_SET_STACKPTR_LIMIT(CurrentDescriptor->StackEndAddr);
    CORE_SET_STACKPTR(CurrentDescriptor->StackPtr);
    
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