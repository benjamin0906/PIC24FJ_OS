#include "../Inc/MemMap.h"
#include "../Inc/I2C.h"

typedef enum
{
    AckOk = 0,
    NoAck = 1,
} dtI2CSendStatus;

static inline void Trigger_Start(dtI2Cx *const Instance)
{
    Instance->CONL.B.SEN = 1;
    while(Instance->CONL.B.SEN != 0);
    while(Instance->STAT.B.S == 0);
    Instance->STAT.B.S = 0;
}

static inline void Trigger_ReStart(dtI2Cx *const Instance)
{
    Instance->CONL.B.RSEN = 1;
    while(Instance->CONL.B.RSEN != 0);
    while(Instance->STAT.B.S == 0);
    Instance->STAT.B.S = 0;
}

static inline void Trigger_Stop(dtI2Cx *const Instance)
{
    Instance->CONL.B.PEN = 1;
    while(Instance->CONL.B.PEN != 0);
    while(Instance->STAT.B.P == 0);
    Instance->STAT.B.P = 0;
}

static inline dtI2CSendStatus SetByteToSend(dtI2Cx *const Instance, uint8 data)
{
    Instance->TRN.B.Tx = data;
    while(Instance->STAT.B.TRSTAT != 0);
    return I2C->I2C1.STAT.B.ACKSTAT != 0 ? NoAck : AckOk;
}

void I2C_Init(dtI2C_Config Config);
dtI2CResut I2C_Transaction(dtI2CInstance Instance, dtI2cTransaction *const Transaction);

void I2C_Init(dtI2C_Config Config)
{
    dtI2Cx *Instance = &I2C->I2C1;
    dtI2CxCONL temp;
    temp.U = 0;
    if(Config.Instance != 0)
    {
        Instance = &I2C->I2C2;
    }
    
    Instance->CONL.U = 0;
    temp.B.A10M = Config.AddrMode;
    
    /* If standard, the slew rate control shall be disabled */
    temp.B.DISSLW = Config.Speed == 0;
    
    temp.B.SMEN = 0;
    temp.B.GCEN = 0;
    temp.B.I2CSIDL = 0;
    
    Instance->BRG.B.I2C1BRG = Config.BaudValue;
    temp.B.I2CEN = 1;
    Instance->CONL = temp;
    while(Instance->CONL.B.I2CEN == 0);
}

dtI2CResut I2C_Transaction(dtI2CInstance Instance, dtI2cTransaction *const Transaction)
{
    dtI2Cx *HwInstance = &I2C->I2C1;
    uint8 lSlaveAddress = Transaction->SlaveAddress<<1;
    uint8 lRegLength = Transaction->SubAddressLength;
    uint8 const *lRegAddr = Transaction->SubAddress;
    uint8 lLength = Transaction->DataLength;
    uint8 *lData = Transaction->Data;
    
    if(Instance == I2C_2)
    {
        HwInstance = &I2C->I2C2;
    }
    
    Trigger_Start(HwInstance);
    
    
    if(Transaction->Mode == I2c_RawRead)
    {
        lSlaveAddress |= 1;
    }
    
    /* Addressing slave */
    if(SetByteToSend(HwInstance, lSlaveAddress) == NoAck)
    {
        /* ACK was NOT received */
        return I2C_SlaveAddrError;
    }
    
    if((Transaction->Mode == I2c_RegWrite) || (Transaction->Mode == I2c_RegRead))
    {
        /* Sending register addresses */
        while(lRegLength > 0)
        {
            if(SetByteToSend(HwInstance, *lRegAddr) == NoAck)
            {
                /* ACK was NOT received */
                return I2C_RegAddrError;
            }
            lRegAddr++;
            lRegLength--;
        }
        if((Transaction->Mode == I2c_RegRead))
        {
            Trigger_ReStart(HwInstance);
            
            lSlaveAddress |= 1;
            if(SetByteToSend(HwInstance, lSlaveAddress) == NoAck)
            {
                /* ACK was NOT received */
                return I2C_SlaveAddrError;
            }
        }
    }
    
    if((Transaction->Mode == I2c_RegWrite) || (Transaction->Mode == I2c_RawWrite))
    {
        /* Sending data */
        while(lLength > 0)
        {
            if(SetByteToSend(HwInstance, *lData) == NoAck)
            {
                /* ACK was NOT received */
                return I2C_RegAddrError;
            }
            lData++;
            lLength--;
        }
    }
    else
    {
        while(lLength > 0)
        {
            lLength--;
            HwInstance->CONL.B.RCEN = 1;
            while(HwInstance->STAT.B.RBF == 0);
            *lData = HwInstance->RCV.B.Rx;
            lData++;

            if(lLength == 0)
            {
                HwInstance->CONL.B.ACKDT = 1;
            }
            else
            {
                HwInstance->CONL.B.ACKDT = 0;
            }
            HwInstance->CONL.B.ACKEN = 1;
            while(HwInstance->CONL.B.ACKEN != 0);
        }
    }
    Trigger_Stop(HwInstance);
    
    return I2C_Ok;
}