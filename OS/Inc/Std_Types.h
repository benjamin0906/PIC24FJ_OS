/* 
 * File:   Std_Types.h
 * Author: Benjamin
 *
 * Created on 2023. november 10., 19:59
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef unsigned char       uint8;
    typedef unsigned short      uint16;
    typedef unsigned long       uint32;
    typedef unsigned long long  uint64;
    
    typedef signed char         int8;
    typedef signed short        int16;
    typedef signed long         int32;
    typedef signed long long    int64;

#define STD_ON 1
#define STD_OFF 0

#ifdef	__cplusplus
}
#endif

#endif	/* STD_TYPES_H */

