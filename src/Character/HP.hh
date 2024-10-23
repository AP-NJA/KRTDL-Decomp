#pragma once

#include "Types.hh"

typedef struct HP
{
    vu32 currentHP;
    MaxMinU32 limits;
    u32 corpseHP;
    u32 previousHP;
    u32 unk14;
} HP;

void decreaseHP(HP * param_1, u32 damageTaken);
void gainHP(HP * param_1, u32 healAmount);
void decreaseCorpseHP(HP * param_1, u32 damageTaken);
