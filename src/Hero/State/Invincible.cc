#include "Invincible.hh"

// 804F04DC
Invincible * invincibleDataConstructor(Invincible * param_1, Hero * param_2)
{
    param_1->heroData = param_2;
    intangibleDataConstructor(&param_1->intangibleData);
    param_1->enableIntangibleFlash = 0;
    param_1->mightyEffect = 0;
    param_1->invincibleSparkleEffect = 0;
    param_1->candyTimer = 0;
    param_1->endRainbowTimer = 0;
    param_1->rainbowCycle = 0;
    param_1->unk24 = 0;
    return param_1;
}
