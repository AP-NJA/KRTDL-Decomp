#pragma once

#include "Types.hh"

typedef struct HP
{
    vu32 currentHP;
    u32 maximumHP;
    u32 minimumHP;
    u32 unkC;
    u32 previousHP;
    u32 unk14;
} HP;

void decreaseHP(HP * param_1, u32 damageTaken);
void lbl_8034F6A0(HP * param_1, u32 param_2);
