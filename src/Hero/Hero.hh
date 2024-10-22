#pragma once

#include "Types.hh"

typedef struct Hero
{
    u8 x0[0x67 - 0x0]; // 0x0
    u8 displayHeroModel; // 0x67
} Hero;

u8 isVisible(Hero * param_1);
