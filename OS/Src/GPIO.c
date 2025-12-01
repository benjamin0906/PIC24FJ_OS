#include "../Inc/MemMap.h"
#include "../Inc/GPIO.h"

void GPIO_SetDir(const dtGPIO_Pins Pin, const dtGPIO_Dir Dir);
void GPIO_Set(dtGPIO_Pins Pin, uint8 Value);

void GPIO_SetDir(const dtGPIO_Pins Pin, const dtGPIO_Dir Dir)
{
    uint16 Mask = (1 << (Pin & 0xF));
    if(Dir == GPIO_Analog)
    {
        Ports->PortDesc[Pin >> 4].ANS.U |= Mask;
    }
    else
    {
        Ports->PortDesc[Pin >> 4].ANS.U &= ~Mask;
        if(Dir == GPIO_Output)
        {
            Ports->PortDesc[Pin >> 4].DIR.U &= ~Mask;
        }
        else
        {
            Ports->PortDesc[Pin >> 4].DIR.U |= Mask;
        }
    }
}

void GPIO_Set(dtGPIO_Pins Pin, uint8 Value)
{
    uint16 Mask = (1 << (Pin & 0xF));
    if(Value == 0)
    {
        Ports->PortDesc[Pin >> 4].OUT.U &= ~Mask;
    }
    else
    {
        Ports->PortDesc[Pin >> 4].OUT.U |= Mask;
    }
}