#include "Invincible.h"
#include "../Model/Model.h"

u32 decrementCandyTimer(CandyInvinc * param_1)
{
    if ((!param_1->mightyEffect) || (param_1->candyTimer == 0))
    {
        return 0;
    }

    return param_1->candyTimer -= 1;
}

bool enableSparkle(CandyInvinc * param_1)
{
    if (!param_1->sparkleEffect)
    {
        return true;
    }

    return false;
}

bool disableSparkle(CandyInvinc * param_1)
{
    if (param_1->sparkleEffect)
    {
        return false; 
    }

    return true;
}

void manageSparkleEffect(CandyInvinc * param_1)
{
    if (!param_1->mightyEffect)
    {
        return;
    }

    if (!isVisible(param_1->modelData))
    {
        param_1->sparkleEffect = disableSparkle(param_1);
    }

    param_1->sparkleEffect = enableSparkle(param_1);
}

u32 decrementRainbowTimer(CandyInvinc * param_1)
{
    if (!param_1->mightyEffect)
    {
        param_1->rainbowCycle = 0;
        return 0;
    }

    return param_1->rainbowTimer -= 1;
}

u32 rainbowCycle(CandyInvinc * param_1)
{
    if (param_1->rainbowCycle == 48)
    {
        param_1->rainbowCycle = 0;
    }

    return param_1->rainbowCycle &= 1;
}

void rgbCurrentColor(CandyInvinc * param_1)
{ 
    u16 iVar2 = param_1->rainbowCycle * 12;

    if (param_1->rainbowCycle == 0)
    {
        return 0;
    }
    
    param_1->rgbRedValue = iVar2 + 255;
    param_1->rgbGreenValue = iVar2 + 0;
    param_1->rgbBlueValue = iVar2 + 0;
}
