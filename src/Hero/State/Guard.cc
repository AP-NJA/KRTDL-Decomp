#include "Guard.hh"

// 801C2E60
void resetGuardFlashCycle(Guard * param_1)
{
    param_1->guardFlashCycle = 0;
}

// 804E4D9C
void guardDataConstructor(Guard * param_1, Hero * param_2)
{
    param_1->heroData = param_2;
    param_1->enableGuardState = 0;
    param_1->enableGuardFlash = 0;
    param_1->guardFlashCycle = 0;
}

// 804E4DB4
void updateGuardState(Guard * param_1)
{
    u32 temp_r0;

    if (param_1->enableGuardState != 0)
    {
        temp_r0 = param_1->guardFlashCycle + 1;
        param_1->guardFlashCycle = temp_r0;

        if (temp_r0 >= 20)
        {
            param_1->guardFlashCycle = 12;
        }
    }

    param_1->enableGuardFlash = param_1->enableGuardState;
}

// 804E4DE8
void playerGuardingCheck(Guard * param_1, u8 guardingFlag)
{
    param_1->enableGuardState = guardingFlag;
    if ((param_1->enableGuardFlash == 0) && (guardingFlag == 1))
    {
        resetGuardFlashCycle(param_1);
    }
}
