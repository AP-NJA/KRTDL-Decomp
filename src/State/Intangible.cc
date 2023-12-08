#include "Intangible.hh"

void intangibleDataConstructor(Intangible * param_1) 
{
    param_1->x0_intangibleFrames = 0;
    param_1->x4_flashCycle = 0;
    param_1->x8_wasHurt = false;
    param_1->x9_disablePity = false;
}

bool canSetIntangible(Intangible * param_1)
{
    bool result = false;

    if ((param_1->x9_disablePity != false) || (param_1->x8_wasHurt != false) || (param_1->x0_intangibleFrames != 0))
    {
        result = true;
    }

    return result;
}

void initializeIntangibleFrames(Intangible * param_1, u32 frames)
{
    if (param_1->x0_intangibleFrames < frames) 
    {
        param_1->x0_intangibleFrames = frames;
    }
    
    param_1->x4_flashCycle = 0;
}

void decrementIntangibleFrames(Intangible * param_1)
{
    u32 temp_r4;
    temp_r4 = param_1->x0_intangibleFrames;
    
    if (temp_r4 != 0) 
    {
        param_1->x0_intangibleFrames = temp_r4 - 1;
    }
}

void updateFlashCycle(Intangible * param_1)
{
    u32 temp_r0;

    if (canSetIntangible(param_1) != false) 
    {
        decrementIntangibleFrames(param_1);
        temp_r0 = param_1->x4_flashCycle + 1;
        param_1->x4_flashCycle = temp_r0;
        
        if (temp_r0 == 0x14) 
        {
            param_1->x4_flashCycle = 0x10;
        }
    }
}
