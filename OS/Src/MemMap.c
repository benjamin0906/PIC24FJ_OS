#include "../Inc/MemMap.h"

dtCORE        * const Core  = (dtCORE*)         0x0000;
dtGPIO_Ports  * const Ports = (dtGPIO_Ports*)   0x0180;
dtTIM         * const TIMs  = (dtTIM*)          0x024C;
dtIC          * const IC    = (dtIC*)           0x0080;
dtSC          * const SC    = (dtSC*)           0x0108;
dtI2C         * const I2C   = (dtI2C*)          0x02DA;