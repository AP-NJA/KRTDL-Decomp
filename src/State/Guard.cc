#include "Guard.hh"

void initializeGuardFlashCycle(Guard * param_1)
{
    param_1->x8_guardStateFlashCycle = 0;
}

void updateGuardState(Guard * param_1) 
{
    u32 temp_r0;

    if (param_1->x4_enableGuardState != false) 
    {
        temp_r0 = param_1->x8_guardStateFlashCycle + 1;
        param_1->x8_guardStateFlashCycle = temp_r0;
        
        if (temp_r0 >= 20) 
        {
            param_1->x8_guardStateFlashCycle = 12;
        }
    }
    
    param_1->x5_enableGuardStateFlash = param_1->x4_enableGuardState;
}

void playerGuardingCheck(Guard * param_1, u32 param_2) 
{
    param_1->x4_enableGuardState = param_2;
    if (param_1->x5_enableGuardStateFlash != false)
    {
        return;
    }
    
    if (param_2 != 0)
    {
        return;
    }

    initializeGuardFlashCycle(param_1);
    return;
}
