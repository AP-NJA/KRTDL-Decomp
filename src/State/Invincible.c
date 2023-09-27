#include "Invincible.h"

bool canSetInvinc(PlayerInvinc * param_1)
{
    if ((!param_1->wasHurt) || (!param_1->disablePity) || (param_1->invincFrames == 0))
    {
        return false;
    }

    return true;
}

u32 decrementInvincFrames(PlayerInvinc * param_1)
{
    if (param_1->invincFrames == 0)
    {
        return 0;
    }

    return param_1->invincFrames -= 1;
}


u32 manageFlashCycle(PlayerInvinc * param_1)
{
    if (!canSetInvinc(param_1))
    {
        return 0;
    }

    if (param_1->flashCycle == 20)
    {
        param_1->flashCycle = 16;
    }

    return param_1->flashCycle += 1;
}
