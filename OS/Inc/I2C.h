/* 
 * File:   I2C.h
 * Author: Benjamin
 *
 * Created on 2023. december 16., 20:17
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct
    {
        uint16 Instance  :1; //I2C1: 0, I2C2: 1
        uint16 Mode      :1; //Master: 0, Slave: 1
        uint16 AddrMode  :1; //7-bit: 0, 10-bit: 1
        uint16 Speed     :1; //0: standard, 1: high-speed
        uint16 BaudValue :12;
    } dtI2C_Config;
    
    typedef enum
    {
        I2C_Ok      = 0,
        I2C_SlaveAddrError = 1,
        I2C_RegAddrError   = 2,
    } dtI2CResut;
    
    typedef enum
    {
        I2C_1,
        I2C_2,
    } dtI2CInstance;
    
    typedef enum
    {
        I2c_RawWrite,
        I2c_RegWrite,
        I2c_RawRead,
        I2c_RegRead,
    } dtI2cTransactionMode;
    
    typedef struct
    {
        dtI2cTransactionMode    Mode;
        uint8 const             SlaveAddress;
        uint8 const *const      SubAddress;
        uint8 const             SubAddressLength;
        uint8 *const            Data;
        uint8 const             DataLength;
    } dtI2cTransaction;


    extern void I2C_Init(dtI2C_Config Config);
    extern dtI2CResut I2C_Transaction(dtI2CInstance Instance, dtI2cTransaction *const Transaction);
    
#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

