#include "Intangible.hh"

// 8034F8D8
void intangibleDataConstructor(Intangible * param_1)
{
    param_1->intangibleFrames = 0;
    param_1->flashCycle = 0;
    param_1->wasHurt = 0;
    param_1->disablePity = 0;
}

// 8034F8F0
void updateFlashCycle(Intangible * param_1)
{
    u32 temp_r0;

    if (canSetIntangible(param_1) != 0)
    {
        decrementIntangibleFrames(param_1);
        temp_r0 = param_1->flashCycle + 1;
        param_1->flashCycle = temp_r0;

        if (temp_r0 == 20)
        {
            param_1->flashCycle = 16;
        }
    }
}

// 8034F948
u32 canSetIntangible(Intangible * param_1)
{
    u32 result = 0;

    if ((param_1->disablePity != 0) || (param_1->wasHurt != 0) || (param_1->intangibleFrames != 0))
    {
        result = 1;
    }

    return result;
}

// 8034F97C
void initializeIntangibleFrames(Intangible * param_1, u32 frames)
{
    if (param_1->intangibleFrames < frames)
    {
        param_1->intangibleFrames = frames;
    }

    param_1->flashCycle = 0;
}

// 8034FA20
void decrementIntangibleFrames(Intangible * param_1)
{
    u32 temp_r4;
    temp_r4 = param_1->intangibleFrames;

    if (temp_r4 != 0)
    {
        param_1->intangibleFrames = temp_r4 - 1;
    }
}
