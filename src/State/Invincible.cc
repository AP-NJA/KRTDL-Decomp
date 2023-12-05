#include "Invincible.hh"

Invincible * invincibleDataConstructor(Invincible * param_1, Model * param_2)
{
    param_1->x0_modelData = param_2;
    intangibleDataConstructor(&param_1->x4_intangibleData);
    param_1->x10_enableIntangibleFlash = false;
    param_1->x11_mightyEffect = false;
    param_1->x12_invincibleSparkleEffect = false;
    param_1->x14_candyTimer = 0;
    param_1->x18_endRainbowTimer = 0;
    param_1->x1C_rainbowCycle = 0;
    param_1->x24_unk24 = 0;
    return param_1;
}

void updateInvincibleState(Invincible * param_1)
{
    
}