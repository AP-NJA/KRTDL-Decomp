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
        lbl_8034F6A0(param_1, damageTaken);
        return;
    }

    newHP = temp_r5 - damageTaken;
    if (newHP < (s32)param_1->minimumHP)
    {
        param_1->currentHP = param_1->minimumHP;
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

void lbl_8034F6A0(HP * param_1, u32 param_2)
{
    u32 temp_r0;

    temp_r0 = param_1->unkC;
    if (temp_r0 < param_2)
    {
        param_1->unkC = 0;
        return;
    }
    param_1->unkC = temp_r0 - param_2;
}
