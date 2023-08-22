#include "Invincible.h"
#include "../Model/Model.h"

void candyTimer(CandyInvinc * param_1)
{
    PlayerInvinc * player = &param_1->player;

    if (param_1->candyTimer == 0)
    {
        return;
    }

    param_1->candyTimer -= 1;
    param_1->mightyEffect = 1;
    player->disablePity = 1;

    return;
}

void enableSparkle(CandyInvinc * param_1)
{
    if (param_1->sparkleEffect == 0)
    {
        param_1->sparkleEffect = 1;
    }

    return;
}

void disableSparkle(CandyInvinc * param_1)
{
    if (param_1->sparkleEffect != 0)
    {
        param_1->sparkleEffect = 0;
    }

    return;
}

void manageSparkleEffect(CandyInvinc * param_1)
{
    Model model;

    param_1->sparkleEffect = 0;

    if (param_1->candyTimer == 0)
    {
        return;
    }

    if (isVisible(&model) == 0)
    {
        disableSparkle(param_1);
        return;
    }

    enableSparkle(param_1);
}

void rainbowTimer(CandyInvinc * param_1)
{
    PlayerInvinc * player = &param_1->player;

    if (param_1->candyTimer != 0)
    {
        return;
    }

    if (param_1->rainbowTimer == 0)
    {
        param_1->mightyEffect = 0;
        player->disablePity = 0;
        return;
    }

    param_1->rainbowTimer -= 1;
}

void rainbowCycle(CandyInvinc * param_1)
{
    if (param_1->rainbowTimer == 0)
    {
        param_1->rainbowCycle = 0;
        return;
    }

    if (param_1->rainbowTimer & 1 != 0)
    {
        return;
    }

    if (param_1->rainbowCycle == 48)
    {
        param_1->rainbowCycle = 0;
    }

    param_1->rainbowCycle += 1;
}
