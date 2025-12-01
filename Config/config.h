/* 
 * File:   config.h
 * Author: Benjamin
 *
 * Created on 2023. november 27., 15:12
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

/* Helper macros */
#define DO_PRAGMA(x) _Pragma(#x)
#define CONFIG_PRAGMA(x) DO_PRAGMA(config x)
#define SET_CONFIG(Bitfield, value) CONFIG_PRAGMA(Bitfield = value)
    
#define PLL_DIV PLL8X
    
#ifndef CONFIG_IS_SET
#define CONFIG_IS_SET
SET_CONFIG(PLLSS, PLL_FRC) 
SET_CONFIG(PLLDIV, PLL_DIV)
SET_CONFIG(POSCMD, NONE)
SET_CONFIG(FNOSC , FRCPLL)
SET_CONFIG(FCKSM , CSECME)
SET_CONFIG(JTAGEN, OFF)
SET_CONFIG(FWDTEN, OFF)
SET_CONFIG(WINDIS, OFF)
SET_CONFIG(OSCIOFCN, ON)
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

