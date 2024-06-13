#pragma once

#include "Intangible.hh"
#include "Model/Model.hh"

typedef struct Invincible
{
    Model * x0_modelData;
    Intangible x4_intangibleData;
    u8 x10_enableIntangibleFlash;
    u8 x11_mightyEffect;
    u8 x12_invincibleSparkleEffect;
    u32 x14_candyTimer;
    u32 x18_endRainbowTimer;
    u32 x1C_rainbowCycle;
    u8 x20_rgbRedValue;
    u8 x21_rgbGreenValue;
    u8 x22_rgbBlueValue;
    u8 x23_unk23;
    u8 x24_unk24;
} Invincible;

Invincible * invincibleDataConstructor(Invincible * param_1, Model * param_2);
void updateInvincibleState(Invincible * param_1);
