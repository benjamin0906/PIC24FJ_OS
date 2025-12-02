#include "../Inc/MemMap.h"
#include "../Inc/PMD.h"

void PMD_Set(dtPmd_Peripheral peripheral)
{
    uint8 register_index = peripheral >> 4;
    uint16 bit_mask = 1 << (peripheral - (register_index << 4));
    PMD->PMD[register_index] |= bit_mask;
}

void PMD_Clear(dtPmd_Peripheral peripheral)
{
    uint8 register_index = peripheral >> 4;
    uint16 bit_mask = ~(1 << (peripheral - (register_index << 4)));
    PMD->PMD[register_index]  &= bit_mask;
}