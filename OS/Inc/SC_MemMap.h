/* 
 * File:   SC_MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 19., 18:57
 */

#ifndef SC_MEMMAP_H
#define	SC_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16 TRAPR    :1;
            uint16 IOPUWR   :1;
            uint16          :1;
            uint16 RETEN    :1;
            uint16          :1;
            uint16 DPSLP    :1;
            uint16 CM       :1;
            uint16 VREGS    :1;
            uint16 EXTR     :1;
            uint16 SWR      :1;
            uint16 SWDTEN   :1;
            uint16 WDTO     :1;
            uint16 SLEEP    :1;
            uint16 IDLE     :1;
            uint16 BOR      :1;
            uint16 POR      :1;
        } B;
    } dtRCON;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16          :1;
            uint16 COSC     :3;
            uint16          :1;
            uint16 NOSC     :3;
            uint16 CLKLOCK  :1;
            uint16 IOLOCK   :1;
            uint16 LOCK     :1;
            uint16          :1;
            uint16 CF       :1;
            uint16 POSCEN   :1;
            uint16 SOSCEN   :1;
            uint16 OSWEN    :1;
        } B;
    } dtOSCCON;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            
            uint16 ROI      :1;
            uint16 DOZE     :3;
            uint16 DOZEN    :1;
            uint16 RCDIV    :3;
            uint16 CPDIV    :2;
            uint16 PLLEN    :1;
            uint16          :5;
        } B;
    } dtCLKDIV;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16 STEN     :1;
            uint16          :1;
            uint16 STSIDL   :1;
            uint16 STSRC    :1;
            uint16 STLOCK   :1;
            uint16 STLPOL   :1;
            uint16 STOR     :1;
            uint16 STORPOL  :1;
            uint16          :2;
            uint16 TUN      :6;
        } B;
    } dtOSCTUN;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16 ROEN     :1;
            uint16          :1;
            uint16 ROSIDL   :1;
            uint16 ROOUT    :1;
            uint16 ROSLP    :1;
            uint16          :1;
            uint16 ROSWEN   :1;
            uint16 ROACTIVE :1;
            uint16          :4;
            uint16 ROSEL    :4;
        } B;
    } dtREFOCONL;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16          :1;
            uint16 RODIV    :15;
        } B;
    } dtREFOCONH;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16 ROTRIM   :9;
            uint16          :7;
        } B;
    } dtREFOTRIML;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16 HLVDEN   :1;
            uint16          :1;
            uint16 LSIDL    :1;
            uint16          :5;
            uint16 VDIR     :1;
            uint16 BGVST    :1;
            uint16 IRVST    :1;
            uint16          :1;
            uint16 HLVDL    :4;
        } B;
    } dtHLVDCON;
    
    typedef union
    {
        uint16 U;
        int16 I;
        struct
        {
            uint16          :12;
            uint16 VDDBOR   :1;
            uint16 VDDPOR   :1;
            uint16 VBPOR    :1;
            uint16 VBAT     :1;
        } B;
    } dtRCON2;
    
    typedef struct
    {
        dtOSCCON    OSCCON;
        dtCLKDIV    CLKDIV;
        uint16      :16;
        dtOSCTUN    OSCTUN;
        dtRCON      RCON;
        dtRCON2     RCON2;
        dtHLVDCON   HLVDCON;
        uint16      DSCON;
        uint16      DSWAKE;
        uint16      DSGPR0;
        uint16      DSGPR1;
        
        
        
        
        /*dtREFOCONL  REFOCONL;
        dtREFOCONH  REFOCONH;
        dtREFOTRIML REFOTRIML;*/
    } dtSC;


#ifdef	__cplusplus
}
#endif

#endif	/* SC_MEMMAP_H */

