#pragma once

#include "Types.hh"

typedef struct Intangible
{
    u32 x0_intangibleFrames;
    u32 x4_flashCycle;
    u8 x8_wasHurt;
    u8 x9_disablePity;
} Intangible;

void intangibleDataConstructor(Intangible * param_1);
u32 canSetIntangible(Intangible * param_1);
u32 FUN_8034f9cc(Intangible * param_1);
void initializeIntangibleFrames(Intangible * param_1, u32 frames);
void decrementIntangibleFrames(Intangible * param_1);
void updateFlashCycle(Intangible * param_1);
void dataDestructor(Intangible * param_1);
