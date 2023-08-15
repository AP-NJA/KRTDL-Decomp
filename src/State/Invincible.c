#include "Invincible.h"

u8 canSetInvinc(PlayerInvinc * param_1)
{
    if ((param_1->wasHurt != 0) || (param_1->disablePity != 0) || (param_1->invincFrames != 0))
    {
        return 1;
    }

    return 0;
}

void decrementFrames(PlayerInvinc * param_1)
{
    if (param_1->invincFrames == 0)
    {
        return;
    }

    param_1->invincFrames -= 1;
}


void manageFlashCycle(PlayerInvinc * param_1)
{
    if (canSetInvinc(param_1) == 0)
    {
        return;
    }

    decrementFrames(param_1);

    param_1->flashCycle += 1;

    if (param_1->flashCycle == 20)
    {
        param_1->flashCycle = 16;
    }
}
