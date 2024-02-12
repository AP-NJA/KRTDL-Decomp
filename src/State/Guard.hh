#pragma once

#include "Types.hh"
#include "Model/Model.hh"

typedef struct Guard
{
    Model * x0_modelData;
    u8 x4_enableGuardState;
    u8 x5_enableGuardFlash;
    u8 pad[0x6 - 0x4];
    u32 x8_guardFlashCycle;
} Guard;

void resetGuardFlashCycle(Guard * param_1);
void guardDataConstructor(Guard * param_1, Model * param_2);
void updateGuardState(Guard * param_1);
void playerGuardingCheck(Guard * param_1, u8 param_2);