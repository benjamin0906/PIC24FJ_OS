/* 
 * File:   I2C_MemMap.h
 * Author: Benjamin
 *
 * Created on 2023. december 15., 22:09
 */

#ifndef I2C_MEMMAP_H
#define	I2C_MEMMAP_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 Rx   :8;
        uint16      :8;
    } B;
} dtI2CxRCV;

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 Tx   :8;
        uint16      :8;
    } B;
} dtI2CxTRN;

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 I2C1BRG  :12;
        uint16          :4;
    } B;
} dtI2CxBRG;

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 SEN      :1;
        uint16 RSEN     :1;
        uint16 PEN      :1;
        uint16 RCEN     :1;
        uint16 ACKEN    :1;
        uint16 ACKDT    :1;
        uint16 STREN    :1;
        uint16 GCEN     :1;
        uint16 SMEN     :1;
        uint16 DISSLW   :1;
        uint16 A10M     :1;
        uint16 STRICT   :1;
        uint16 SCLREL   :1;
        uint16 I2CSIDL  :1;
        uint16          :1;
        uint16 I2CEN    :1;
    } B;
} dtI2CxCONL;

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 DHEN     :1;
        uint16 AHEN     :1;
        uint16 SBCDE    :1;
        uint16 SDAHT    :1;
        uint16 BOEN     :1;
        uint16 SCIE     :1;
        uint16 PCIE     :1;
        uint16          :9;
    } B;
} dtI2CxCONH;

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 TBF      :1;
        uint16 RBF      :1;
        uint16 R_W      :1;
        uint16 S        :1;
        uint16 P        :1;
        uint16 D_A      :1;
        uint16 I2COV    :1;
        uint16 IWCOL    :1;
        uint16 ADD10    :1;
        uint16 GCSTAT   :1;
        uint16 BCL      :1;
        uint16          :2;
        uint16 ACKTIM   :1;
        uint16 TRSTAT   :1;
        uint16 ACKSTAT  :1;
    } B;
} dtI2CxSTAT;

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 Add  :10;
        uint16      :6;
    } B;
} dtI2CxADD;

typedef union
{
    uint16 U;
    int16 I;
    struct
    {
        uint16 AddrMask :10;
        uint16          :6;
    } B;
} dtI2CxMSK;

typedef struct
{
    dtI2CxRCV RCV;
    dtI2CxTRN TRN;
    dtI2CxBRG BRG;
    dtI2CxCONL CONL;
    dtI2CxCONH CONH;
    dtI2CxSTAT STAT;
    dtI2CxADD ADD;
    dtI2CxMSK MSK;
} dtI2Cx;

typedef struct
{
    dtI2Cx I2C1;
    dtI2Cx I2C2;
} dtI2C;

#ifdef	__cplusplus
}
#endif

#endif	/* I2C_MEMMAP_H */

