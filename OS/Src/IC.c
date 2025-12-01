#include "../Inc/MemMap.h"
#include "../Inc/IC.h"

void IC_EnableIRQ(dtIC_Vector Vector);
void IC_DisableIRQ(dtIC_Vector Vector);
void IC_ClearIRQ(dtIC_Vector Vector);

void IC_EnableIRQ(dtIC_Vector Vector)
{
    uint16 *ICE = &IC->Enable.Reg0.U;
    ICE[Vector >> 4] |= 1 << (Vector & 0xF);
}

void IC_DisableIRQ(dtIC_Vector Vector)
{
    uint16 *ICE = &IC->Enable.Reg0.U;
    ICE[Vector >> 4] &= ~(1 << (Vector & 0xF));
}

void IC_ClearIRQ(dtIC_Vector Vector)
{
    uint16 * IFS = &IC->Status.Reg0.U;
    IFS[Vector >> 4] &= ~(1 << (Vector & 0xF));
}