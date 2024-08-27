#pragma once

#include "Types.hh"

typedef struct HP
{
    u32 x0_currentHP;
    u32 x4_maxHP;
    u32 x8_minHP;
    u32 xC_unkC;
    u32 x10_previousHP;
    u32 x14_unk14;
} HP;

void HPManager(HP * param_1, u32 damageTaken);
void lbl_8034F6A0(HP * param_1, u32 param_2);
