/* 
 * File:   TIM_MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 13:04
 */

#ifndef TIM_MEMMAP_H
#define	TIM_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef union
    {
        uint16  U;
        int16   I;
        /*struct
        {
            uint16  TON     :1;
            uint16          :1;
            uint16  TSIDL   :1;
            uint16          :3;
            uint16  TECS    :2;
            uint16          :1;
            uint16  TGATE   :1;
            uint16  TCKPS   :2;
            uint16          :1;
            uint16  TSYNC   :1;
            uint16  TCS     :1;
            uint16          :1;
        } B;*/
        struct
        {
            uint16          :1;
            uint16  TCS     :1;
            uint16  TSYNC   :1;
            uint16          :1;
            uint16  TCKPS   :2;
            uint16  TGATE   :1;
            uint16          :1;
            uint16  TECS    :2;
            uint16          :3;
            uint16  TSIDL   :1;
            uint16          :1;
            
            uint16  TON     :1;
        } B;
    }dtTIM_CON;
    
    typedef union
    {
        uint16  TON     :1;
        uint16          :1;
        uint16  TSIDL   :1;
        uint16          :3;
        uint16  TECS    :2;
        uint16          :1;
        uint16  TGATE   :1;
        uint16  TCKPS   :2;
        uint16  T32     :1;
        uint16          :1;
        uint16  TCS     :1;
    } dtTIM_CON32;
    
    typedef struct
    {
        uint16      TMR;
        uint16      PR;
        dtTIM_CON   CON;
    }dtTIM_A;
    
    typedef struct
    {
        uint16      TMR_L;
        uint16      TMR_H_HLD;
        uint16      TMR_H;
        uint16      PR_L;
        uint16      PR_H;
        dtTIM_CON   CON;
        dtTIM_CON32 CON2;
    } dtTIM_B;
    
    typedef struct
    {
        dtTIM_A TIM1;
        dtTIM_B TIM23;
        dtTIM_B TIM45;
    }dtTIM;


#ifdef	__cplusplus
}
#endif

#endif	/* TIM_MEMMAP_H */

