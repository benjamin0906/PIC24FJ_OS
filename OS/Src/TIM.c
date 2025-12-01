#include "../Inc/MemMap.h"
#include "../Inc/TIM.h"
#include "../Inc/TIM_MemMap.h"
#include "../Inc/IC.h"

void TIM_A_Init(dtTIM_A_Cfg *Config);

void (*IntHandlers[5])(void);

void TIM_A_Init(dtTIM_A_Cfg *Config)
{
    dtTIM_A tempCfg;
    tempCfg.PR = Config->CmpValue;
    tempCfg.TMR = 0;
    tempCfg.CON.U = 0;
    tempCfg.CON.B.TCKPS = Config->Prescaler;
    tempCfg.CON.B.TON = Config->TOn;
    
    if(Config->IntHandler != 0)
    {
        IntHandlers[Config->Instance-1] = Config->IntHandler;
    }
    
    if(Config->Instance == 1)
    {
        TIMs->TIM1 = tempCfg;
    }
}

#if defined(OS)
#include "OS_Config.h"
#if OS_TIMER != TIMER_1
void __attribute__((interrupt(auto_psv))) _T1Interrupt(void)
{
    IntHandlers[0]();
    IC_ClearIRQ(IC_T1IF);
}
#endif
#endif