#include "HP.hh"

// 8034F59C
void HPManager(HP * param_1, u32 damageTaken)
{
    s32 newHP;

    param_1->x10_previousHP = param_1->x0_currentHP;
    if ((s32)param_1->x0_currentHP == 0)
    {
        lbl_8034F6A0(param_1, damageTaken);
        return;
    }

    newHP = param_1->x0_currentHP - damageTaken;
    if (newHP < (s32)param_1->x8_minHP)
    {
        param_1->x0_currentHP = param_1->x8_minHP;
    }
    else
    {
        param_1->x0_currentHP = newHP;
    }

    if ((param_1->x14_unk14 != 0) && (param_1->x0_currentHP == 0) && (param_1->x10_previousHP >= param_1->x14_unk14))
    {
        param_1->x0_currentHP = 1;
    }
}

void lbl_8034F6A0(HP * param_1, u32 param_2)
{
    u32 temp_r0;

    temp_r0 = param_1->xC_unkC;
    if (temp_r0 < param_2)
    {
        param_1->xC_unkC = 0;
        return;
    }
    param_1->xC_unkC = temp_r0 - param_2;
}
