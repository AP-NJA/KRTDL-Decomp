#include "Invincible.h"
#include "../Model/Model.h"

void candyTimer(CandyInvinc * param_1)
{
    if (param_1->candyTimer == 0)
    {
        param_1->mightyEffect = 0;
        return;
    }

    param_1->candyTimer -= 1;
    param_1->mightyEffect = 1;
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

    if (param_1->mightyEffect == 0)
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
