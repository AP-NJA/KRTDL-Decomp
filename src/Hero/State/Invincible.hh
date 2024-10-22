#pragma once

#include "Hero/Hero.hh"
#include "Intangible.hh"

typedef struct Invincible
{
    Hero * heroData;
    Intangible intangibleData;
    u8 enableIntangibleFlash;
    u8 mightyEffect;
    u8 invincibleSparkleEffect;
    u32 candyTimer;
    u32 endRainbowTimer;
    u32 rainbowCycle;
    u8 rgbRedValue;
    u8 rgbGreenValue;
    u8 rgbBlueValue;
    u8 unk23;
    u8 unk24;
} Invincible;

Invincible * invincibleDataConstructor(Invincible * param_1, Hero * param_2);
void updateInvincibleState(Invincible * param_1);
