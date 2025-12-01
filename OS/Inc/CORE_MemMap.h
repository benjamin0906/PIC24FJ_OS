/* 
 * File:   CORE_MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. november 17., 16:41
 */

#ifndef CORE_MEMMAP_H
#define	CORE_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct
    {
        uint16 W0;//0x0000
        uint16 W1;//0x0002
        uint16 W2;//0x0004
        uint16 W3;//0x0006
        uint16 W4;//0x0008
        uint16 W5;//0x000A
        uint16 W6;//0x000C
        uint16 W7;//0x000E
        uint16 W8;//0x0010
        uint16 W9;//0x0012
        uint16 W10;//0x0014
        uint16 W11;//0x0016
        uint16 W12;//0x0018
        uint16 W13;//0x001A
        uint16 W14;//0x001C
        uint16 W15;//0x001E
        uint16 SPLIM;
        uint16 :16;//0x0022
        uint16 :16;//0x0024
        uint16 :16;//0x0026
        uint16 :16;//0x0028
        uint16 :16;//0x002A
        uint16 :16;//0x002C
        uint16 PCL;
        uint16 PCH;
        uint16 DSRPAG;
        uint16 DSWPAG;
        uint16 RCOUNT;
        uint16 :16;//0x0038
        uint16 :16;//0x003A
        uint16 :16;//0x003C
        uint16 :16;//0x003E
        uint16 :16;//0x0040
        uint16 SR;//0x0042
        uint16 CORCON;//0x0044
        
    } dtCORE;


#ifdef	__cplusplus
}
#endif

#endif	/* CORE_MEMMAP_H */

