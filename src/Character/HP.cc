#include "HP.hh"

// 8034F59C
void decreaseHP(HP * param_1, u32 damageTaken)
{
    s32 newHP;
    u32 temp_r5;

    temp_r5 = param_1->currentHP;
    param_1->previousHP = temp_r5;

    if (param_1->currentHP == 0)
    {
        decreaseCorpseHP(param_1, damageTaken);
        return;
    }

    newHP = temp_r5 - damageTaken;
    if (newHP < (s32)param_1->limits.minimum)
    {
        param_1->currentHP = param_1->limits.minimum;
    }
    else
    {
        param_1->currentHP = newHP;
    }

    if ((param_1->unk14 != 0) && (param_1->currentHP == 0) && (param_1->previousHP >= param_1->unk14))
    {
        param_1->currentHP = 1;
    }
    return;
}

// 8034F600
void gainHP(HP * param_1, u32 healAmount)
{
    u32 sp8;
    u32 temp_r0;

    temp_r0 = param_1->currentHP;
    param_1->previousHP = temp_r0;
    sp8 = temp_r0 + healAmount;
    param_1->currentHP = *lbl_8014C34C(&param_1->limits, &sp8);
}

// 8034F6A0
void decreaseCorpseHP(HP * param_1, u32 damageTaken)
{
    u32 temp_r0;

    temp_r0 = param_1->corpseHP;
    if (temp_r0 < damageTaken)
    {
        param_1->corpseHP = 0;
        return;
    }
    param_1->corpseHP = temp_r0 - damageTaken;
}
