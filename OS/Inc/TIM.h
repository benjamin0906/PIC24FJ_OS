/* 
 * File:   TIM.h
 * Author: Benjamin
 *
 * Created on 2023. november 11., 16:37
 */

#ifndef TIM_H
#define	TIM_H

#ifdef	__cplusplus
extern "C" {
#endif

    /*
     * -- Prescaler: 3->256; 2->64; 1->8; 0->1 
     */
    typedef struct
    {
        void (*IntHandler)(void);
        uint16 CmpValue;
        uint16 Instance     :1;
        uint16 Prescaler    :2;
        uint16 TOn          :1;
    } dtTIM_A_Cfg;
    
    extern void TIM_A_Init(dtTIM_A_Cfg *Config);


#ifdef	__cplusplus
}
#endif

#endif	/* TIM_H */

