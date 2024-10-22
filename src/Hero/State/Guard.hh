#pragma once

#include "Hero/Hero.hh"
#include "Types.hh"

typedef struct Guard
{
    Hero * heroData; // 0x0
    u8 enableGuardState; // 0x4
    u8 enableGuardFlash; // 0x5
    u8 x6[0x8 - 0x6]; // 0x6
    u32 guardFlashCycle; // 0x8
} Guard;

void resetGuardFlashCycle(Guard * param_1);
void guardDataConstructor(Guard * param_1, Hero * param_2);
void updateGuardState(Guard * param_1);
void playerGuardingCheck(Guard * param_1, u8 guardingFlag);
