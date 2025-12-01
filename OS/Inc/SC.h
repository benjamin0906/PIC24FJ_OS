/* 
 * File:   SC.h
 * Author: Benjamin
 *
 * Created on 2023. november 19., 21:14
 */

#ifndef SC_H
#define	SC_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct
    {
        uint16 FrcDiv   :3;
        uint16 Doze     :3;
        uint16 :1;
    } dtSC_OscConfig;
    
    typedef enum
    {
        SC_Freq_Peri,
        SC_Freq_Cpu,
        SC_Freq_Tim,
    } dtSCFreq;


#ifdef	__cplusplus
}
#endif

#endif	/* SC_H */

